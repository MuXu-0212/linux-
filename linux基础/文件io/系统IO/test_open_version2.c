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

#define FILE_PATH "/mnt/hgfs/C_CODE/系统IO/test_open_v2.txt"
#define MAXSIZE 50
int main(int argc, char const *argv[])
{
	int fd;
	int ret = access(FILE_PATH, F_OK);

/*检测文件是否存在, 不存在则创建一个*/
	if (access(FILE_PATH, F_OK) == -1)
	{
		fd = open(FILE_PATH, O_RDWR | O_CREAT | O_EXCL, 0777 );
		if (fd == -1)
		{
			printf("打开文件失败!\n");
			return 0;
		}
	}
	else
	{
		fd = open(FILE_PATH, O_RDWR);
		if (fd == -1)
		{
			printf("打开文件失败!\n");
			return 0;
		}
	}

	fd = open(FILE_PATH, O_RDWR);
	printf("文件描述符为%d\n", fd);

	close(fd);
	return 0;
}