src = $(wildcard *.c) 
obj = $(patsubst %.c, %.o, $(src))

main:$(obj)
	gcc $(obj) -o main
add.o:add.c
	gcc -c add.c -o add.o
sub.o:sub.c
	gcc -c sub.c -o sub.o
mul.o:mul.c
	gcc -c mul.c -o mul.o
dev.o:dev.c
	gcc -c div.c -o div.o
hello.o:hello.c
	gcc -c hello.c -o hello.o

clean:
	-rm -rf $(obj) main

