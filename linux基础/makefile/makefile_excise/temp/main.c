#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main(int argc, char const *argv[])
{
	int a=3, b=4;
	add( a, b);
	sub( a, b);
	mul( a, b);
	div( a, b);
	return 0;
}