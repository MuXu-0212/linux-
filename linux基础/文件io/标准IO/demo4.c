#include <stdio.h>
#include <error.h>
#include <unistd.h>
#include <string.h>

#define FILE_PATH "/mnt/hgfs/2212/文件IO/标准IO/code/1.txt"

struct info
{
	char name[30];
	int  score;
};


void Get_Info(FILE *fp, struct info *data)
{
	char buf[100] = {0};
	int i = 0;
	while(fgets(buf,sizeof(buf),fp))
	{
		sscanf(buf,"%s %d",data[i].name, &data[i].score);
		printf("%s %d\n",data[i].name,data[i].score);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	//1.打开文件
	FILE * fp = fopen(FILE_PATH, "r");
	
	struct info data[4];

	//读取数据
	Get_Info(fp,data);

	//输入新的信息
	struct info temp;
	printf("请输入姓名\n");
	scanf("%s",temp.name);
	printf("请输入分数\n");
	scanf("%d",&temp.score);


	//数据处理
	int i;
	for (i = 0; i < 3; i++)
	{
		if (temp.score > data[i].score)
		{
			break;
		}
	}
	for (size_t j = 4; j > i; j--)
	{
		data[j] = data[j-1]; 
	}
	
	data[i] = temp;
	fclose(fp);


	//把新的数据写入到文本中
	fp = fopen(FILE_PATH, "w+");
	char data1[100];
	for (size_t i = 0; i < 3; i++)
	{
		sprintf(data1,"%s %d\n",data[i].name,data[i].score);
		fputs(data1,fp);
	}
	
	fclose(fp);

	return 0;
}
