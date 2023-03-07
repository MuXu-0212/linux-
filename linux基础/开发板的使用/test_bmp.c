#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

//屏幕驱动文件路径
#define LCD_PATH "/dev/fb0"
#define BMP_PATH "/MYDIR/color/1.bmp"

int lcd_fd;
int* share_addr = NULL;

int show_bmp(char* pathname, int width, int height, int x, int y)
{
	int ret;
	char head_buf[54] = {0};
	int i,j;

	char bmp_buf[width*height*3];
	bzero(bmp_buf, width*height*3);

	int lcd_buf[width*height];
	bzero(lcd_buf, width*height);

	int bmp_fd = open(pathname, O_RDWR);

	if (bmp_fd < 0)
	{
		printf("open bmp failed\n");
		return -1;
	}

	read(bmp_fd, head_buf, 54);
	read(bmp_fd, bmp_buf, width*height*3);

	for (j = 0; j < height; j++)
	{
		for (i = 0; i < width; i++)
		{
			lcd_buf[i+j*width] = bmp_buf[3*(i+j*width)+0];
			lcd_buf[i+j*width] |=  bmp_buf[3*(i+j*width)+1]<<8;
			lcd_buf[i+j*width] |= bmp_buf[3*(i+j*width)+2]<<16;
		}
	}

	//将处理好的图片数据写入到LCD屏,进行映射.
	for(j = 0; j < height; j++)
	{
		for(i = 0; i < width; i++)
		{
			*(share_addr + i + j*800 + x + y*800) = lcd_buf[i+(height-1-j)*width];
		}
	}

	close(bmp_fd);
	return 0;
}

void Dev_Init(void)
{
	lcd_fd = open(LCD_PATH, O_RDWR);
	if (lcd_fd == -1)
	{
		perror("打开LCD驱动文件失败!\n");
		return ;
	}

	//功能 : 申请共享内存
	//返回值成功,则返回共享内存的地址, 失败,为NULL
	share_addr = mmap(
		NULL,					//需要申请的内存地址 NULL 标准 让CPU帮你选择
		800*480*4,				//800*480*4
		PROT_READ | PROT_WRITE,	//内存的使用权限 PROT_READ | PROT_WRITE
		MAP_SHARED,				//MAP_SHARED
		lcd_fd,					//文件描述符
		0);						//偏移量
}

void Uninit(void)
{
	close(lcd_fd);
	munmap(share_addr, 800*480*4);
}

int main(int argc, char const *argv[])
{
	Dev_Init();

	show_bmp(BMP_PATH, 800, 480, 0, 0);

	Uninit();
	return 0;
}

