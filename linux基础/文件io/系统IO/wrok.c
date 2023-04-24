#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"
#define FILE_PATH1 "/mnt/hgfs/2212/文件IO/代码/2.txt"

int Open_File(char *path, mode_t mode)
{
	int fd = open(path, O_RDWR | O_CREAT,mode);
	if (fd != -1)
	{
		return fd;
	}
}

int main(int argc, char const *argv[])
{
	//1.打开该文件
	int file1_fd = Open_File(FILE_PATH,0777);
	int file2_fd = Open_File(FILE_PATH1,0777);

	char read_data[128];
	int ret;
	while(1)
	{
		memset(read_data, 0, sizeof(read_data));
		//从1.txt当中读取数据 
		ret = read(file1_fd, read_data,sizeof(read_data));
		if (ret > 0)
		{
			//把读取到的数据写入到2.txt当中
			write(file2_fd, read_data, ret);
		}
		else
		{
			break;
		}
	}
	
	close(file1_fd);
	close(file2_fd);


	return 0;
}
