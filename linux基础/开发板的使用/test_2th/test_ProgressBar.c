#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <strings.h>

// #define height 480
// #define width 800
#define PATH_LCD "/dev/fb0"


int print_color(char* path, int width, int height, int x, int y)
{
	int fd_lcd = open(PATH_LCD, O_RDWR);
	if (fd_lcd == -1)
	{
		perror("lcd驱动打开失败!\n");
		return 0;
	}

	char bmp_arr[width*height*3];
	int ret = read(fd_bmp, bmp_arr, height*width*3);

	int* share_addr_ = mmap(
			NULL,
			height*width*4,
			PROT READ|PROT WRITE,
			MAP_SHARED,
			fd_LCD,
			0
			);


	close(fd_lcd);
	munmap(share_addr, width*height*4);
}