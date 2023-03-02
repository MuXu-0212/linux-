#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "drawtree.h"

#define elemtype int

typedef struct tree{
	elemtype data;
	struct tree* left;
	struct tree* right;
}BiTNode,* BiTree;

BiTNode* BiTree_create(int data)
{
	BiTNode* root = (BiTNode*)malloc(sizeof(BiTree));
	if ( root != NULL)
	{
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	return NULL;
} 

BiTNode* Inset_Node_Tree_V2(BiTree root, elemtype data)
{
	if (root == NULL)
	{
		return BiTree_create(data);
	}
	//新节点的数据要小于根节点
	if (data < root->data)
	{
		root->left = Inset_Node_Tree_V2(root->left,data);
	}//新节点的数据要大于根节点
	else if (data > root->data)
	{
		root->right =  Inset_Node_Tree_V2(root->right,data);
	}//相等
	else
	{
		printf("节点数据重复,无法插入\n");
	}
	return root;
}

void visit(BiTree root)
{
	// printf("444\t");
	printf("%d\t", root->data);
}

void PreOrder(BiTree root)
{
	if (root != NULL)
	{
		visit(root);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder( BiTree root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		visit(root);
		InOrder(root->right);
	}
}

void PostOrder( BiTree root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		visit(root);	
	}
}

bool BiTree_InsertNode( BiTree root, elemtype data)
{
    BiTNode* new = (BiTNode*)malloc(sizeof(BiTree));
	if (new == NULL)
	{
        return false;
	}

	new->data = data;
	new->left = NULL;
	new->right = NULL;

	BiTree p = root;

	while (1)
	{
		if (data > p->data)
		{
			if (p->right != NULL)
			{
				p = p->right;
			}
			else
			{
				p->right = new;
				return  true;
			}
		}
		else if (data < p->data)
		{
			if (p->left != NULL)
			{
				p = p->left;
			}
			else
			{
				p->left = new;
				return true;
			}
		}
		else
		{
			printf("this %d is common!\n", data);
			return true;
		}
	}
}

void BiTree_RandScanf( BiTree root)
{
	srand(time(NULL));

	int i=0, len=rand()%10+5;

	for (i=0; i<len; i++)
	{
		elemtype data = rand()%100+1;
		// BiTree_InsertNode( root, data);
		Inset_Node_Tree_V2( root, data);
	}
}


/*定义队列节点*/
typedef struct node{
	BiTree T;
	struct node* next;
}node, *queue;

/*定义一个存储队头和队尾的指针*/
typedef struct{
	queue front;
	queue rear;
}Queue;

/*初始化带头结点的队列*/
Queue* linkqueue_init()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL)
	{
		q->front = (node*)malloc(sizeof(node));
		q->rear = q->front;
		q->front->next = NULL;
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
bool linkqueue_enter(Queue* q, BiTree root)
{
	node* new = (node*)malloc(sizeof(node));
	if (new != NULL)
	{
		new->T = root;
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
bool linkqueue_out(Queue* q, BiTree* root)
{
	if (linkqueue_IsEmpty(*q))
	{
		return false;
	}

	*root = q->front->next->T;
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

void LevelOrder(BiTree root)
{
	Queue* q = linkqueue_init();
	BiTree t = root;

	linkqueue_enter( q, t);

	while (!linkqueue_IsEmpty( *q))
	{
		// printf("111\n");
		linkqueue_out( q, &t);
		// printf("222\n");
		visit( t);
		// printf("333\n");
		if (t->left != NULL)
		{
			linkqueue_enter( q, t->left);
		}
		if (t->right != NULL)
		{
			linkqueue_enter( q, t->right);
		}
	}
}

int main(int argc, char const *argv[])
{
	BiTree root = BiTree_create(40);
	BiTree_RandScanf( root);

	printf("前序遍历!\n");
	PreOrder( root);

	printf("\n\n中序遍历!\n");
	InOrder( root);

	printf("\n\n后序遍历!\n");
	PostOrder( root);

	printf("\n\n层序遍历!\n");
	LevelOrder( root);

	printf("\n");

	draw(root);
	return 0;
}