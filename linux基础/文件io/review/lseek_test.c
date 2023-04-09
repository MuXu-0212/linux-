/*
	获取文件大小
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


int main(int argc, char const *argv[])
{
	int fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		perror("open error");
		exit(1);
	}

	int lenth = lseek(fd, 0, SEEK_END);
	printf("file size:%d\n", lenth);
	close(fd);
	
	return 0;
}