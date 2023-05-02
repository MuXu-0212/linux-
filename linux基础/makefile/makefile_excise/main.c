#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "hello.h"

int main(int argc, char const *argv[])
{
	int a=3, b=4;
	hello();
	add( a, b);
	sub( a, b);
	mul( a, b);
	div1( a, b);
	return 0;
}