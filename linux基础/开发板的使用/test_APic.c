#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#define PATH_LCD "/dev/fb0"

int main(int argc, char const *argv[])
{
	int x, y;
	int fd_lcd = open(PATH_LCD, O_RDWR);
	if (fd_lcd == -1)
	{
		printf("打开LCD驱动文件失败!\n");
		return -1;
	}


	char color_data[800*480*4];
	for (x=0; x<200; x++)
	{
		for (y=0; y<480; y++)
		{
			color_data[0+4*x+800*4*y] = 0;  //蓝
			color_data[1+4*x+800*4*y] = 0;  //绿
			color_data[2+4*x+800*4*y] = 255;//红
			color_data[3+4*x+800*4*y] = 0;  //透明度
		}
	}

	for (x=200; x<400; x++)
	{
		for (y=0; y<480; y++)
		{
			color_data[0+4*x+800*4*y] = 0;  //蓝
			color_data[1+4*x+800*4*y] = 255;  //绿
			color_data[2+4*x+800*4*y] = 0;//红
			color_data[3+4*x+800*4*y] = 0;  //透明度
		}
	}

	for (x=400; x<600; x++)
	{
		for (y=0; y<480; y++)
		{
			color_data[0+4*x+800*4*y] = 255;  //蓝
			color_data[1+4*x+800*4*y] = 0;  //绿
			color_data[2+4*x+800*4*y] = 0;//红
			color_data[3+4*x+800*4*y] = 0;  //透明度
		}
	}

	for (x=600; x<800; x++)
	{
		for (y=0; y<480; y++)
		{
			color_data[0+4*x+800*4*y] = 100;  //蓝
			color_data[1+4*x+800*4*y] = 100;  //绿
			color_data[2+4*x+800*4*y] = 55;//红
			color_data[3+4*x+800*4*y] = 0;  //透明度
		}
	}
	write(fd_lcd, color_data, 800*400*4);

	close(fd_lcd);
	return 0;
}