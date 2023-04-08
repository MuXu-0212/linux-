#include "head.h"

#define path_read "./1.txt"
#define path_write "./2.txt"

int main(int argc, char const *argv[])
{
	FILE* fp, *fp_out;
	int n;

	fp = fopen(path_read, "r");
	if (fp == NULL)
	{
		perror("fopen error");
		exit(1);
	}

	fp_out = fopen(path_write, "w");
	if (fp_out == NULL)
	{
		perror("fopen error");
		exit(1);
	}

	while ( (n = fgetc(fp)) != EOF)
	{
		fputc(n, fp_out);
	}

	fclose(fp);
	fclose(fp_out);
	return 0;
}

