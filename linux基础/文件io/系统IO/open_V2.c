#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define FILE_PATH "/mnt/hgfs/2212/文件IO/代码/1.txt"
//可选参数
//O_APPEND 追加写入数据
//O_CREAT  如果你要打开的文件不存在 则会帮你创建 如果存在则直接打开
//O_EXCL   如果你要打开的文件已经存在,则会报错
int main(int argc, char const *argv[])
{
	//判断一个文件是否存在或是否有执行权限
	//参数：const char *path 你要判断的文件路径
	//参数: int amode R_OK, W_OK, X_OK, F_OK
	//返回值 存在的话就是0 不存在则为-1
	int fd;
	int ret = access(FILE_PATH, F_OK);
	if (ret == -1)
	{
		fd = open(FILE_PATH, O_RDWR | O_CREAT, 0777);
		if (fd == -1)
		{
			printf("打开文件失败\n");
			return -1;
		}
	}
	else
	{
		fd = open(FILE_PATH, O_RDWR);
		if (fd == -1)
		{
			printf("打开文件失败\n");
			return -1;
		}
	}

	

	
	return 0;
}