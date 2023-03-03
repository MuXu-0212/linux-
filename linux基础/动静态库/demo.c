#include <stdio.h>
#include <stdlib.h>
#include "drawtree.h"

//设计二叉树节点
typedef struct tree_node
{
	int data;
	struct tree_node *left;  //左指针
	struct tree_node *right; //右指针
}tree_s, *tree_p;


//功能:创建数的节点
//返回值 返回一个创建成功的节点地址
//参数 要给节点赋值的数据
tree_p Creat_Tree_Node(int data)
{
	tree_p node = (tree_p)malloc(sizeof(tree_s));
	if (node != NULL)
	{
		node->data = data;
		node->left = NULL;
		node->right= NULL;
		return node;
	}
	return NULL;
}

//非递归的形式插入节点
//功能：插入节点到数当中
int Inset_Node_Tree(tree_p root, int data)
{
	tree_p new_node =  Creat_Tree_Node(data);
	if (new_node == NULL)
	{
		return -1;
	}

	//弄一个中间变量来替代 root 操作 防止树的节点丢失
	tree_p p = root;

	while(1)
	{
		//新节点的数据大于 根 节点的情况下
		if (new_node->data > p->data)
		{
			//右子树有节点的情况下
			if (p->right != NULL)
			{
				p = p->right;
			}
			else //右子树没有节点的时候
			{
				p->right = new_node;
				return 1;
			}
		}//新节点的数据小于 根 节点的情况下
		else if (new_node->data < p->data)
		{
			//左子树有节点的时候
			if (p->left != NULL)
			{
				p = p->left;
			}//左子树没有节点的时候
			else
			{
				p->left = new_node;
			}
		}
		else
		{
			printf("数据相同无法插入节点\n");
			return 1;
		}
	}
}

//递归的方式插入节点
tree_p Inset_Node_Tree_V2(tree_p root, int data)
{
	if (root == NULL)
	{
		return Creat_Tree_Node(data);
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

//先序  根———>左————>右
void Preorder(tree_p tree)
{
	if (tree != NULL)
	{
		printf("%d ",tree->data);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}
//中序 左———>根————>右
void Preorder1(tree_p tree)
{
	if (tree != NULL)
	{
		Preorder1(tree->left);
		printf("%d ",tree->data);
		Preorder1(tree->right);
	}
}
//后序 左———>右————>根
void Preorder2(tree_p tree)
{
	if (tree != NULL)
	{
		Preorder2(tree->left);
		Preorder2(tree->right);
		printf("%d ",tree->data);
	}
}

int Find_Node(tree_p tree, int data)
{
	if (tree == NULL)
	{
		return -1;
	}
	while (1)
	{
		//1.data相等要找的数据
		if(tree->data == data)
		{
			printf("%d\n",tree->data);
			return 1;
		}
		//2.data	小于 节点的数据 
		else if (data < tree->data)
		{
			tree = tree->left;
		}//3.data大于 节点的数据 
		else if (data > tree->data)
		{
			tree = tree->right;
		}
		else if (tree == NULL)
		{
			break;
		}
	}

	printf("沒有找到该节点\n");
}

//如果你要使用该节点时,需要判断该节点是否为NULL
//如果为NULL 说明没有找到该节点.
//非NULL 则是找到了该节点
tree_p Find_Node_V2(tree_p tree, int data)
{
	if (tree == NULL || tree->data == data)
	{
		return tree;
	}
	if (data < tree->data)
	{
		return Find_Node_V2(tree->left, data);
	}

	return Find_Node_V2(tree->right, data);
}

tree_p Delete_Node(tree_p tree, int data)
{
	if (tree == NULL)
	{
		return tree;
	}
	//1.找到要删除的节点位置
	//如果说比根节点要小的数据则去左边找
	if (data < tree->data)
	{
		tree->left = Delete_Node(tree->left, data);
	}//如果说比根节点要大的数据则去右边找
	else if (data > tree->data)
	{
		tree->right = Delete_Node(tree->right, data);
	}//当上面的递归完毕时.说明就找了我们要删除的节点
	else //2.有3种情况 a,即没有左子树也没有右子树 b.仅有左子树或右子树 c.即有左子树也有右子树
	{
		tree_p temp = NULL;
		//有左子树
		if(tree->left != NULL)
		{
			//让tmp指向整颗数左子树中最大的节点
			temp = tree->left; //移动left指针
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			//把它的数据赋值给要删除的节点
			tree->data = temp->data;
			//递归的删除掉被替换的节点,以当前节点的左子树的根为出发点，
			//找到要替换的节点;
			tree->left = Delete_Node(tree->left, temp->data);
		}//有右子树的情况
		else if (tree->right != NULL)
		{
			temp = tree->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			tree->data = temp->data;
			tree->right = Delete_Node(tree->right, temp->data);
		}
		else
		{
			free(tree);
			return NULL;
		}
	}

	return tree;
}

int main(int argc, char const *argv[])
{
	tree_p root = Creat_Tree_Node(5);
	tree_p p = root;

	Inset_Node_Tree_V2(p, 2);
	Inset_Node_Tree_V2(p, 9);
	Inset_Node_Tree_V2(p, 0);
	Inset_Node_Tree_V2(p, 4);
	Inset_Node_Tree_V2(p, 3);
	Inset_Node_Tree_V2(p, 7);
	Inset_Node_Tree_V2(p, 8);
	
	Preorder(root);
	printf("\n");

	// draw(root);

	Delete_Node(root,2);

	Preorder(root);
	printf("\n");



	return 0;
}
