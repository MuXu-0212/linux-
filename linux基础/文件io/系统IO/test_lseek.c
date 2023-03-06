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

#define FILE_PATH "/mnt/hgfs/C_CODE//系统IO/test_lseek.txt"
#define MAXSIZE 5

int main(int argc, char const *argv[])
{
	int fd = open(FILE_PATH, O_RDWR);
	if (fd == -1)
	{
		perror("open file failed!\n");
		return 0;
	}

	char str[MAXSIZE];
	strcpy(str, "12345");
	write(fd, str, sizeof (str));

	lseek(fd, 0, SEEK_SET);
	// write(fd, str, sizeof (str));

	// char read_arr[MAXSIZE]={0};
	int ret = read(fd, str, sizeof(str));

	printf("读取了 %d 个数据\n",ret);
	printf("读取到的数据为 %s\n",str);


	close(fd);
	return 0;
}