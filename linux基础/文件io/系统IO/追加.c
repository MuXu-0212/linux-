#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"
#define FILE_PATH1 "/mnt/hgfs/2212/文件IO/代码/2.txt"

#define APPEND  1
#define EXCL 	2
#define CREAT   3

int Open_File(char *path, int flags ,mode_t mode)
{
	int flag = 0;
	if (flags == APPEND)
	{
		flag = O_RDWR | O_APPEND;
	}
	else if (flags == CREAT)
	{
		flag = O_RDWR | O_CREAT;
	}

	int fd = open(path, flag ,mode);
	if (fd != -1)
	{
		return fd;
	}
}

int main(int argc, char const *argv[])
{
	//1.打开该文件
	int file1_fd = Open_File(FILE_PATH,3,0777);
	int file2_fd = Open_File(FILE_PATH1,1,0777);

	char read_data[128];
	int ret;
	while( ret = read(file1_fd, read_data,sizeof(read_data)))
	{
		//从1.txt当中读取数据 
		//把读取到的数据写入到2.txt当中
		write(file2_fd, read_data, ret);
		memset(read_data, 0, sizeof(read_data));
	}
	
	close(file1_fd);
	close(file2_fd);

	return 0;
}
