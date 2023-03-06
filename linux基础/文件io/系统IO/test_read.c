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

#include <errno.h>  
/*perror("")错误提示示例代码

	*/

#define FILE_PATH "/mnt/hgfs/C_CODE/系统IO/test_read.txt"

int main(int argc, char const *argv[])
{
	int fd = open( FILE_PATH, O_RDWR | O_APPEND | O_EXCL, 0644);
	if (fd == -1)
	{
		perror("打开文件失败\n");
		return -1;
	}
	printf("文件描述符为%d\n", fd);

	char read_data[100];
	ssize_t ret = read(fd, read_data, sizeof(read_data));

	printf("ret = %ld\n", ret);
	if (ret > 0)
	{
		printf("读取了%ld个数据字节\n", ret);
		printf("读取的数据为%s\n", read_data);
	}

	close(fd);
	return 0;
}