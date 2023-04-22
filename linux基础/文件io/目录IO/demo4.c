#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>


void Get_Cmd(char * cmd,char *cmd1)
{
	//创建并且打开
	char tmp[100];
	sprintf(tmp,"%s %s",cmd,cmd1);
	system(tmp);
}


//复制一个文件
void Copy_File(char *file_name)
{
	char buf[256] = {0};
	sprintf(buf, "副本_%s",file_name);
	

	FILE *p = fopen(file_name,"r");
	FILE *new_p = fopen(buf,"w+");
	char read_data[58] = {0};
	int ret;
	
	while (1)
	{
		ret = fread(read_data, sizeof(read_data), 1, p);
		if (ret <= 0)
		{
			if (feof(p))
			{
				fwrite(read_data, strlen(read_data), 1 , new_p);
				fclose(new_p);
				fclose(p);
				return;
			}
			else
			{
				return;
			}

		}
		fwrite(read_data, sizeof(read_data), 1 , new_p);
		memset(read_data, 0 , sizeof(read_data));
	}
}


int main(int argc, char *argv[])
{

	DIR * dir_p = NULL;
	//判断该文件是否存在 存在则打开 不存在则创建
	if( !(access(argv[1],F_OK)))
	{
		dir_p = opendir(argv[1]);
		if (dir_p == NULL)
		{
			printf("打开目录失败\n");
			return -1;
		}
	}
	else
	{
		//创建并且打开
		Get_Cmd("mkdir",argv[1]);

		dir_p = opendir(argv[1]);
		if (dir_p == NULL)
		{
			printf("打开目录失败\n");
			return -1;
		}
	}

	//功能: 读取目录当中的文件
	//参数：DIR *dirp 你要读取的目录指针
	//返回值： 成功返回文件类型指针 ,失败为NULL
	struct dirent * p = NULL;
	while( p = readdir(dir_p) )
	{
		if (p->d_name[0] != '.' &&  strncmp(p->d_name,"..",2) != 0)
		{
			if (p->d_type == DT_REG)
			{
				Copy_File(p->d_name);
			}
		}
	}


	closedir(dir_p);
	return 0;
}
