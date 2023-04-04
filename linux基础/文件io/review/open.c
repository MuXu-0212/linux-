#include "head.h"


/*------------int open(const char* pathname, int flags)-----------*/

#define path_open "./dir/1.txt"

int main(int argc, char const *argv[])
{
	//打开一个文件
	int fd = open(path_open, O_RDONLY | O_CREAT | O_TRUNC, 0644);
	// 0 表示八进制
	// 6 rw-
	// 4 r--
	// 4 r--
	// 依次为（读r=4）（写w=2）（运行x=1）

	printf("fd = %d\n", fd);

	close(fd);

	return 0;
}




