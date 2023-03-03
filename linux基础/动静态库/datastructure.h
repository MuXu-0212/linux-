#ifndef __datastructure_h_
#define __datastructure_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define elemtype int

/*---------------------单向循环链表----------------------*/

/*定义一个头节点*/
typedef struct LNode{
	int data;
	struct LNode* next;
}LNode, *linklist;


/*初始化一个单向循环链表*/
extern LNode* linklist_create();

/*创建一个新节点*/
/*参数 data:要添加的数据*/
extern LNode* linklist_NewNode( elemtype data);

/*单向循环链表尾插一个节点*/
/*参数  head:目的地链表的地址, 
	    new:尾插的新节点地址*/
extern void linklist_InsertNodeTail( linklist head, linklist new);

/*单向循环链表头插一个节点*/
/*参数  head:目的地链表的地址, 
	    new:头插的新节点地址*/
extern void linklist_InsertNodeHead( linklist head, linklist new);

/*在单循环链表中尾插一个新数据*/
/*参数  head:目的地链表的地址, 
	    data:要添加的数据*/
extern bool linklist_InsertDataTail( linklist head, elemtype data);

/*在单循环链表中头插一个新数据*/
/*参数  head:目的地链表的地址, 
	    data:要添加的数据*/
extern bool linklist_InsertDataHead( linklist head, elemtype data);

/*打印单向循环链表*/
/*参数  head:目的地链表的地址*/
extern bool linklist_print( linklist head);

/*---------------------双向循环链表----------------------*/
/*定义一个头节点*/
typedef struct DNode
{
	int data;
	struct DNode* next;
	struct DNode* prev;
}DNode, *Dlinklist;

/*初始化一个双向循环链表*/
extern DNode* Dlinklist_create();

/*创建一个新节点*/
extern DNode* Dlinklist_NewNode( elemtype data);

/*在双循环链表中尾插一个新数据*/
extern bool Dlinklist_InsertDataTail( Dlinklist head, elemtype data);

/*在双循环链表中头插一个新数据*/
extern bool Dlinklist_InsertDataHead( Dlinklist head, elemtype data);

/*双向循环链表尾插一个节点*/
extern void Dlinklist_InsertNodeTail( Dlinklist head, Dlinklist NewNode);

/*双向循环链表头插一个节点*/
extern void Dlinklist_InsertNodeHead( Dlinklist head, Dlinklist new);

/*双向循环链表向前遍历*/
extern bool Dlinklist_PreOrder( Dlinklist head);

/*双向循环链表向后遍历*/
extern bool Dlinklist_LastOrder( Dlinklist head);

/*双向循环链表随机赋值, len为随机个数*/
extern void Dlinklist_RandScanf(Dlinklist head, int len);

/*取下指定双循环链表的节点*/
extern DNode* Dlinklist_UnbringNode(Dlinklist p);

/*删除整个链表*/
extern bool Dlinklist_delete( Dlinklist head);

/*双循环链表地址排序*/
extern bool Dlinklist_sort(Dlinklist head);

/*双向循环链表_选择排序*/
extern bool Dlinklist_SelectSort(Dlinklist head);


/*---------------------链队----------------------*/
/*定义队列节点*/
typedef struct node{
	int data;
	struct node* next;
}node, *queue;

/*定义一个存储队头和队尾的指针*/
typedef struct{
	queue front;
	queue rear;
}Queue;

/*初始化带头结点的队列*/
extern Queue* linkqueue_init();

/*判断队空*/
extern bool linkqueue_IsEmpty(Queue q);

/*入队*/
extern bool linkqueue_enter(Queue* q, elemtype data);

/*出队*/
extern bool linkqueue_out(Queue* q, elemtype* data);

/*打印队列*/
extern bool linkqueue_print(Queue q);

/*给队列随机赋值数据, len是数据个数*/
extern void linkqueue_RandScanf(Queue* q, int len);


/*---------------------二叉树----------------------*/
/*定义一个二叉树节点*/
typedef struct tree{
	elemtype data;
	struct tree* lchild;
	struct tree* rchild;
}BiTNode, * BiTree;

/*初始化一个二叉树的根节点*/
extern BiTNode* BiTree_create(elemtype data);

/*二叉树访问节点*/
extern void BiTree_visit( BiTree root);

/*二叉树前序遍历*/
extern void BiTree_PreOrder(BiTNode* root);

/*二叉树中序遍历*/
extern void BiTree_InOrder(BiTNode* root);

/*二叉树后序遍历*/
extern void BiTree_PostOrder(BiTNode* root);

/*二叉树增加新节点*/
extern BiTNode* BiTree_NewNode(BiTNode* root, elemtype data);

/*二叉树随机添加新节点, len为新增节点个数*/
extern void BiTree_SrandScanf(BiTNode* root, int len);

/*二叉树按层遍历*/
extern void BiTree_levelOrder(BiTNode* root);


#endif