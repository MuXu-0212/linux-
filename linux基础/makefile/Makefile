
TARGET = main 
CC    := gcc
#.c文件的目录在src .当前目录的文件
DIRS = ./src ./src2
LIB = libtest.a
LIB_PATH = ./lib
#指定头文件路径
CFLAGS =  -I ./include -I ./include2
#在指定路径,获取到所有的.c文件放入到SRCS变量中
SRCS   =  $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
#把所有从 $(SRCS) 中搜索到的 .c 依赖文件 都替换为 .o 目标文件 放入到OBJ的列表当中
OBJ    =  $(patsubst %.c,%.o,$(SRCS)) 
RMRF  := rm -rf

all: $(LIB) $(TARGET) 

$(TARGET):$(OBJ) 
	$(CC) $^ main.c -o $(TARGET)  $(CFLAGS)
	./main

$(LIB):$(OBJ)
	ar -cr $(LIB) $(OBJ)
	mkdir lib
	mv $(LIB) $(LIB_PATH)

.PHONY: 
clrearall:
	$(RMRF) $(OBJ) $(TARGET) $(LIB) ./lib
clrear:
	$(RMRF) $(OBJ)