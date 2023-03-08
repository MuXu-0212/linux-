#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <strings.h>

#define PATH_LCD "/dev/fb0"
#define PATH_PIC "/MYDIR/color/1.bmp"
// #define PATH_PIC "/MYDIR/color/1.bmp"


int PicPrint(char* path, int height, int width, int x, int y)
{
	//1.打开lcd驱动文件
	int fd_lcd = open(PATH_LCD, O_RDWR);
	if (fd_lcd < 0)
	{
		perror("Don't open the file of lcd!\n");
		return 0;
	}

	//2.打开bmp图片
	int fd_bmp = open(PATH_PIC, O_RDWR);
	if (fd_bmp < 0)
	{
		perror("Don't open this picture!\n");
		return 0;
	}

	//3.申请虚拟共享内存
	int* share_addr = mmap(
		NULL,
		height*width*4,
		PROT_READ|PROT_WRITE,
		MAP_SHARED,
		fd_lcd,
		0
		);

	//4.从bmp图片把24位的颜色数据读出来
	char bmp_data[height*width*3];
	bzero(bmp_data, height*width*3);

	int share_addr_temp[height*width];
	bzero(share_addr_temp, height*width);

	//偏移54个字节头信息
	lseek(fd_bmp, 54, SEEK_SET);

	int ret = read(fd_bmp, bmp_data, height*width*3);

	if (ret < 0)
	{
		perror("fail!\n");
		return 0;
	}

	int i,j;

	for (i=0; i<height; i++)
	{
		for (j=0; j<width; j++)
		{
			share_addr_temp[i*width+j] = bmp_data[0+(j+i*width)*3];
			share_addr_temp[i*width+j] |= bmp_data[1+(j+i*width)*3]<<8;
			share_addr_temp[i*width+j] |= bmp_data[2+(j+i*width)*3]<<16;
		}
	}

	//将处理好的图片数据写入到LCD屏,进行映射.
	for(j = 0; j < height; j++)
	{
		for(i = 0; i < width; i++)
		{
			*(share_addr + i + j*width + x + y*width) = share_addr_temp[i+(height-1-j)*width];
		}
	}

	close(fd_lcd);
	close(fd_bmp);
	munmap(share_addr, height*width*4);
	return 0;
}

int main(int argc, char const *argv[])
{
	PicPrint(PATH_PIC, 480, 800, 0, 0);
	return 0;
}