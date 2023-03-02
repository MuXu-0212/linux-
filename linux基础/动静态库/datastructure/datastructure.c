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




/*---------------------单向循环链表----------------------*/

/*初始化一个单向循环链表*/
LNode* linklist_create()
{
	LNode* head = (LNode*)malloc(sizeof(LNode));

	if (head != NULL)
	{
		head->next = head;
		return head;
	}
	printf("create head, error!\n");
	return NULL;
}

/*创建一个新节点*/
LNode* linklist_NewNode( elemtype data)
{
    LNode* new = (LNode*)malloc(sizeof(LNode));
    if (new != NULL)
    {
    	new->data = data;
    	new->next = NULL;
    	return new;
    }
    printf("new node, error!\n");
    return NULL;
}

/*单向循环链表尾插一个节点*/
void linklist_InsertNodeTail( linklist head, linklist new)
{
    LNode* p = head;
    while (p->next != head)
    {
    	p = p->next;
    }
    
    new->next = head;
    p->next = new;
}

/*单向循环链表头插一个节点*/
void linklist_InsertNodeHead( linklist head, linklist new)
{
    new->next = head->next;
    head->next = new;
}


/*在单循环链表中尾插一个新数据*/
bool linklist_InsertDataTail( linklist head, elemtype data)
{
	LNode* new = (LNode*)malloc(sizeof(LNode));
	if (new != NULL)
	{
		LNode* p = head;
		while (p->next != head)
		{
			p = p->next;
		}
		new->next = head;
		p->next = new;
		return true;
	}
	return false;
}

/*在单循环链表中头插一个新数据*/
bool linklist_InsertDataHead( linklist head, elemtype data)
{
	LNode* new = (LNode*)malloc(sizeof(LNode));
	if (new != NULL)
	{
		new->next = head->next;
		head->next = new;
		return true;
	}
	return false;	
}

/*打印单向循环链表*/
bool linklist_print( linklist head)
{
	if (head->next = head)
	{
		return false;
	}

    LNode* p = head->next;
    while (p != head)
    {
    	printf("%d  ",p->data);
    }
    return true;
}

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


/*------------------------------------------------------*/

/*============================================================*/

/*---------------------双向循环链表----------------------*/

/*初始化一个双向循环链表*/
DNode* Dlinklist_create()
{
	DNode* head = (DNode*)malloc(sizeof(DNode));
	if ( head != NULL)
	{
		head->prev = head;
        head->next = head;
		return head;
	} 
	return NULL;
}

/*创建一个新节点*/
DNode* Dlinklist_NewNode( elemtype data)
{
	DNode* NewNode = (DNode*)malloc(sizeof(DNode));
    if (NewNode != NULL)
    {
    	NewNode->data = data;
    	NewNode->next = NewNode;
    	NewNode->prev = NewNode;
    	return NewNode;
    }
    return NULL;
}

/*在双循环链表中尾插一个新数据*/
bool Dlinklist_InsertDataTail( Dlinklist head, elemtype data)
{
	DNode* new = (DNode*)malloc(sizeof(DNode));

	if (new != NULL)
	{
		new->data = data;
		new->prev = head->prev;
		new->next = head;
		head->prev->next = new;
		head->prev = new;
		return true;
	}
	return false;
}

//在双循环链表中头插一个新数据
bool Dlinklist_InsertDataHead( Dlinklist head, elemtype data)
{
	DNode* new = (DNode*)malloc(sizeof(DNode));

	if (new != NULL)
	{
        new->data = data;
        new->prev = head;
        new->next = head->next;
        head->next->prev = new;
        head->next = new;
		return true;
	}
	return false;
}

/*双向循环链表尾插一个节点*/
void Dlinklist_InsertNodeTail( Dlinklist head, Dlinklist NewNode)
{
    NewNode->next = head; 
    NewNode->prev = head->prev;
    head->prev->next = NewNode;
    head->prev = NewNode;
}

/*双向循环链表头插一个节点*/
void Dlinklist_InsertNodeHead(Dlinklist head, Dlinklist new)
{
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
}

/*双向循环链表尾插*/
bool Dlinklist_PreOrder(Dlinklist head)
{
	if (head->prev == head)
	{
		return false;
	}
	DNode* p = head;
	for (p=head->prev; p!=head; p=p->prev)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
	return true;
}


bool Dlinklist_LastOrder(Dlinklist head)
{
	if (head->next == head)
	{
		return false;
	}

	DNode* p = head;

	for (p=head->next; p!=head; p=p->next)
	{
		printf("%d  ", p->data);
	}
	printf("\n");
}

void Dlinklist_RandScanf(Dlinklist head, int len)
{
	srand(time(NULL));
	int i=0;
	DNode* new = NULL;
	for (i=0; i<len; i++)
	{
		new = Dlinklist_NewNode( rand()%100+1);
		Dlinklist_InsertNodeHead(head, new);
	}
}

DNode* Dlinklist_UnbringNode(Dlinklist p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	p->prev = p;
	p->next = p;
	return p;
}

bool Dlinklist_delete( Dlinklist head)
{
	DNode* p = head->next;
	while(p != head)
	{
		free(Dlinklist_UnbringNode(p));
		p = head->next;
	}

	if (head->prev == head || head->next == head)
	{
		free(head);
		return true;
	}
}

bool Dlinklist_sort(Dlinklist head)
{
    if (head->next==head || head->next->next==head)
    {
    	return false;
    }

    DNode* head_t = head;
    DNode* pre = head;
    DNode* p = pre->next;
    DNode* p_m = NULL;
    int min = 0;
    int len = 0;

    while (pre->next != head)
    {
    	len++;
    	pre=pre->next;
    }
    pre = head->next;

    while (head_t->next != head)
    {
    	// printf("len = %d\n", len);
    	pre = head_t->next;
    	min = pre->data;
    	p_m = head;

    	for (p=pre->next; p!=head; p=p->next, pre=pre->next)
    	{
    		if (min > p->data)
    		{
    			min = p->data;
    			p_m = pre;
    		}
    	}
    	if (p_m != head)
    	{
    		p = p_m->next;
    		p_m->next = p->next;
    		p->next->prev = p_m;
    		Dlinklist_InsertNodeHead(head_t, p);
    	}
    	head_t = head_t->next;
    }
    return true;
}

/*选择排序: 
	每次比较一轮,选择无序序列当中的最大或最小的数据*/
bool Dlinklist_SelectSort(Dlinklist head)
{
	//没有节点或只有一个节点的时候是不需要排序的
	if ((head->next == head || head->prev == head) && (head->next->next == head))
	{
		return false;
	}


	//1.结束条件
	//2.插入的基准点
	DNode* p = head->next;
	int len = 0;
	//计算出链表的总节点个数
	while( p != head)
	{
		len++;
		p = p->next;
	}
	len = len - 1;

	DNode* t = head; //插入基准点
	DNode* tmp = NULL;
	int min = 0;

	//比较的轮数
	while(len--)
	{
		min = t->next->data;
		//去寻找一组无序序列当中最小或最大的数据
		for (p = t->next->next; p != head; p = p->next)
		{
			if (min > p->data)
			{
				min = p->data;
				tmp = p;
			}
		}

		if (tmp != NULL)
		{
			Dlinklist_InsertNodeHead(t,Dlinklist_UnbringNode(tmp));
			tmp = NULL;
		}
		t = t->next;
	} /*while(len--)*/
	return true;
}


/*---------------------链队----------------------*/
/*初始化带头结点的队列*/
Queue* linkqueue_init()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL)
	{
		q->front = (node*)malloc(sizeof(node));
		q->rear = q->front;
		q->front->next = NULL;
		// printf("1111\n");
		return q;		
	}
	return NULL;
}

/*判断队空*/
bool linkqueue_IsEmpty(Queue q)
{
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

/*入队*/
bool linkqueue_enter(Queue* q, elemtype data)
{
	// printf("1111\n");
	node* new = (node*)malloc(sizeof(node));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
		q->rear->next = new;
		q->rear = new;
		// printf("q->rear = %p\n", q->rear);
		// printf("q->front->next->data = %d\n", q->front->next->data);
		return true;
	}
	return false;
}

/*出队*/
bool linkqueue_out(Queue* q, elemtype* data)
{
	if (linkqueue_IsEmpty(*q))
	{
		return false;
	}

	*data = q->front->next->data;
	node* temp = q->front->next;
    q->front->next = temp->next;
    temp->next = NULL;
    if (q->rear == temp)
    {
    	q->rear = q->front;
    }
    free(temp);

    return true;
}

/*打印队列*/
bool linkqueue_print(Queue q)
{
	int i=0;
	if (linkqueue_IsEmpty(q))
	{
		printf("表空!\n");
		return false;
	}
	node* p = q.front->next;
	while (p != NULL)
	{
		i++;
        printf("%d\t",p->data);
        p = p->next;
        // if ( i == 5)
        // {
        // 	i=0;
        // 	printf("\n");
        // }
	}
	printf("\n");
	return true;
}

/*随机队列数据*/
void linkqueue_RandScanf(Queue* q, int len)
{
	int i = 0;
	int data = 0;

	srand(time(NULL));

	for (i=0; i<len; i++)
	{
		data = rand()%999+1;
		// printf("%d\n", data);
		linkqueue_enter(q, data);
	}
	printf("\n");
}

/*---------------------二叉树----------------------*/
/*初始化一个二叉树的根节点*/
BiTNode* BiTree_create(elemtype data)
{
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTree));
	if (root != NULL)
	{
		root->data = data;
		root->lchild = NULL;
		root->rchild = NULL;
		return root;
	}
	return NULL;
}

/*二叉树访问节点*/
void BiTree_visit( BiTree root)
{
	printf("%d ", root->data);
}

/*二叉树前序遍历*/
void BiTree_PreOrder(BiTNode* root)
{
    if (root != NULL)
    {
    	BiTree_visit( root);
    	BiTree_PreOrder( root->lchild);
    	BiTree_PreOrder( root->rchild);
    }
}

/*二叉树中序遍历*/
void BiTree_InOrder(BiTNode* root)
{
	if (root != NULL)
	{
		BiTree_InOrder( root->lchild);
		BiTree_visit( root);
		BiTree_InOrder( root->rchild);
	}
}

/*二叉树后序遍历*/
void BiTree_PostOrder(BiTNode* root)
{
	if (root != NULL)
	{
		BiTree_PostOrder( root->lchild);
		BiTree_PostOrder( root->rchild);
		BiTree_visit( root);
	}
}

// /*二叉树按层遍历*/
// /**/
// void BiTree_levelOrder(BiTNode* root)
// {
// 	elemtype data=0;

// 	Queue* q = linkqueue_init();

// 	queue_enter( q, root->data);

//     while (!linkqueue_IsEmpty(*q))
//     {
//     	linkqueue_out( q, &data);
//     	if (q)
//     }

// }

/*二叉树增加新节点*/
BiTNode* BiTree_NewNode(BiTNode* root, elemtype data)
{
	if (root == NULL)
	{
        BiTNode* new = (BiTNode*)malloc(sizeof(BiTNode));
        if (new != NULL)
        {
        	new->data = data;
        	new->lchild = NULL;
        	new->rchild = NULL;
        	return new;
        }
	}
	else if ( data < root->data)
	{
        root->lchild = BiTree_NewNode( root->lchild, data);
	}
	else if ( data > root->data)
	{
		root->rchild = BiTree_NewNode( root->rchild, data);
	}
	else
	{
        printf("数据%d重复,无法插入\n", data);
	}
	return root;
}

/*二叉树随机添加新节点, len为新增节点个数*/
void BiTree_SrandScanf(BiTNode* root, int len)
{
	BiTNode* new = NULL;
	srand(time(NULL));
	int i=0;
    for ( i=0; i<len; i++)
    {
    	new = BiTree_NewNode( root, rand()%100+10);
    }
}






