#include "a.h"
#include "b.h"
#include <stdio.h>


int main(int argc, char const *argv[])
{	
	int arr[5] = {1,2,3,4,5};
	printf("%d\n",Max(arr,5));
	printf("%d\n",Min(arr,5));
	return 0;
}
