#include "datastructure.h"

// DNode* Dlinklist_unbring(Dlinklist p)
// {
// 	DNode* temp = p->next;
// 	temp->next->prev = p;
// 	p->next = temp->next;
// 	return temp;
// }

// void sort( Dlinklist head)
// {
// 	DNode* p = head->next;
// 	DNode* pre = head;
// 	DNode* head_t = head;

// 	while (head_t->next != head)
// 	{
// 		while (p->next->data)
// 		{
// 			;
// 		}
// 	}
// }

// bool func( Dlinklist head)
// {


// }

int main(int argc, char const *argv[])
{
	BiTNode* root = BiTree_create(50);
	BiTree_SrandScanf( root, 30);

	BiTree_PreOrder( root);
	printf("\n");

	BiTree_InOrder( root);
	printf("\n");

	BiTree_PostOrder( root);
	printf("\n");

	
	return 0;
}