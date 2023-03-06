#include <stdio.h>

#include <unistd.h>	
/*关闭头文件, int close(int fd)关闭成功返回0, 失败返回-1
  读取数据, ssize_t read(int fd ,void* buf, size_t count)
  写入数据, ssize_t write(int fd ,void* buf, size_t count)
	*/
#include <sys/stat.h>
#include <sys/types.h>/*& #include<unistd.h>*/
/*移动文件的读写位置 off_t lseek(int fildes, off_t offset, int whence)
	*/

#include <fcntl.h>
#include <string.h>

#include <errno.h>  
/*perror("")错误提示示例代码
	*/

#define FILE_PATH_APPEND "/mnt/hgfs/C_CODE/系统IO/test_append.txt"
#define FILE_PATH_READ "/mnt/hgfs/C_CODE/系统IO/test_read.txt"
#define MAXSIZE 50
int main(int argc, char const *argv[])
{
	/*检测文件是否存在*/
	if (access(FILE_PATH_READ, F_OK) == -1 
		&& access(FILE_PATH_APPEND, F_OK) == -1)
	{
		return 0;
	}

	int fd_read = open(FILE_PATH_READ, O_RDWR);
	int fd_append = open(FILE_PATH_APPEND, O_RDWR | O_CREAT);

	if (fd_read == -1 && fd_append == -1)
	{
		printf("打开文件失败!\n");
		return 0;
	}

	char read_data[128];
	int ret = 0;

	while ( ret = read(fd_read, read_data, sizeof(read_data)))
	{
		write(fd_append, read_data, ret);
		memset(read_data, 0, sizeof(read_data));
	}

	close(fd_read);
	close(fd_append);
	return 0;
}