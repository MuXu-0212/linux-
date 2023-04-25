#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH1 "/mnt/hgfs/2212/文件IO/标准IO/code/1.txt"
#define FILE_PATH2 "/mnt/hgfs/2212/文件IO/标准IO/code/copy.txt"

int main(int argc, char const *argv[])
{
	//打开1.txt
	FILE * file1_fp = fopen(FILE_PATH1,"r");
	if (file1_fp == NULL)
	{
		perror("open file1 failed\n");
		return -1;
	}

	//打开 copy.txt
	FILE * file2_fp = fopen(FILE_PATH2,"w+");
	if (file2_fp == NULL)
	{
		perror("open file2 failed\n");
		return -1;
	}

	int ret;
	char read_data[128];
	while(1)
	{
		memset(read_data,0,sizeof(read_data));

		ret = fread(read_data, sizeof(read_data), 1, file1_fp);
		if (ret <= 0)
		{	
			//判断文件指针是否到达文件末尾处
			if (feof(file1_fp))
			{
				fwrite(read_data, strlen(read_data), 1, file2_fp);
				break;
			}
			else
			{
				return -1;
			}
		}
		
		fwrite(read_data, sizeof(read_data), 1, file2_fp);
	}

	fclose(file1_fp);
	fclose(file2_fp);
	
	return 0;
}
