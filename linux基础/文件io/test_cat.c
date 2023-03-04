#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH_1 "/mnt/hgfs/C_CODE/新建文件夹/1.txt"
#define FILE_PATH_2 "/mnt/hgfs/C_CODE/新建文件夹/2.txt"

#define APPEND 1
#define EXCL 2
#define CREAT 3

int Open_File(char* path, int flags, mode_t mode)
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

	int fd = open( path, flag, mode);

	if ( fd != -1)
	{
		return fd;
	}
}

int main(int argc, char const *argv[])
{
	int fd_1 = Open_File(FILE_PATH_1, 1, 0777);
	int fd_2 = Open_File(FILE_PATH_2, 3, 0777);

	char read_data[128];
	int ret;

	while (ret = read(fd_2, read_data, sizeof(read_data)))
	{
		write( fd_1, read_data, ret);
		memset( read_data, 0, sizeof(read_data));
	}

	close(fd_1);
	close(fd_2);
	return 0;
}