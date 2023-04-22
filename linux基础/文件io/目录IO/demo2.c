#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>

#define FILE_PATH "/mnt/hgfs/2212/文件IO/目录IO/代码/1.txt"

int main(int argc, char const *argv[])
{
	struct stat buf;
	int ret = stat(argv[1], &buf);
	if (ret != 0)
	{
		perror("get info failed\n");
		return -1;
	}

	// switch (buf.st_mode & S_IFMT)
	// {
	// 	case S_IFIFO:
	// 		printf("管道文件\n");
	// 		break;
	// 	case S_IFDIR:
	// 		printf("目录文件\n");
	// 		break;
	// 	case S_IFBLK:
	// 		printf("块设备文件\n");
	// 		break;
	// 	case S_IFCHR:
	// 		printf("字符设备文件\n");
	// 		break;
	// 	case S_IFREG:
	// 		printf("普通文件\n");
	// 		break;
	// default:
	// 	break;
	// }


	if (S_ISREG(buf.st_mode))
	{
		printf("普通文件\n");
	}
	else
	{
		printf("非普通文件\n");
	}
	


	return 0;
}
