#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct NODE {
	int value;
	struct NODE *link;
}Node;

//头插法建表 
void CreatList(Node **root) {
	Node *p = *root;
	Node *new_node;
	int new_value;
	
	while (scanf("%d", &new_value) != EOF) {
		//输入负值作为结束标志 
		if (new_value < 0) {
			break;
		}
		new_node = (Node *)malloc(sizeof(Node));
		new_node->value = new_value;
		p->link= new_node;
		new_node->link = NULL;
		p = p->link;
	}
}
//输出链表 
void DispList(Node **root) {
	Node *p = (*root)->link;
	while( p != NULL) {
		printf("%d ", p->value);
		p = p->link;
	} 
	printf("\n");
}
//反置链表
int ReverseList(Node **root) {
	Node *p = NULL;
	Node *tmp = NULL;
	if (root == NULL) {
		return FALSE;
	}
	tmp = (*root)->link;
	while (tmp->link != NULL) {
		p = tmp->link;
        tmp->link = p->link;
        p->link = (*root)->link;
        (*root)->link = p;
	}
	return TRUE;
} 
int main() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->link = NULL;
	CreatList(&root);
	printf("原链表：");
	DispList(&root);
	
	ReverseList(&root);
	printf("反置后链表：");
	DispList(&root);
} 
