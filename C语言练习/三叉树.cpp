#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct BTNode {
	ElemType data;
	struct BTNode *lchild, *rchild, *parent;
}BTNode, *BTree;

//生成树
BTNode *CreateBTree(BTNode *f) {
	BTNode *p;
	ElemType e;
	printf("请输入元素：");
	scanf(" %c", &e);
	if(e == '0')
		p = NULL;
	else {
		p = (BTNode *)malloc(sizeof(BTNode));
		p->data = e;
		printf("生成%c的左孩子\n", e);
		p->parent = f;
		p->lchild = CreateBTree(p);
		printf("生成%c的右孩子\n", e);
		p->parent = f;
		p->rchild = CreateBTree(p);
	}
	return p;
}

//中序遍历——递归
void InOrder(BTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

//三叉链表法
void InOrder1(BTree T) {
	if(T == NULL)
		return;
	BTNode *p = T;
	while(p->lchild)
		p = p->lchild;
	while(p) {
		printf("%c", p->data);
		if(p->rchild) {
			p = p->rchild;
			while(p->lchild)
				p = p->lchild;
		}
		else{
			BTNode *f = p->parent;
			if(p->data == f->lchild->data) {
				p = f;
			}
			else {
				while(p == f->rchild) {
					p = f;
					f = f->parent;
					if(f == NULL)
						break;	
				}
				p = f;
			}
		}
	}
	return;
}

int main() {
	BTree T = CreateBTree(NULL);
	T->parent = NULL;
	printf("中序遍历(递归)：");
	InOrder(T);
	printf("\n");

	printf("%c\n", T->lchild->rchild->data);
	printf("中序遍历(三叉链表)：");
	InOrder1(T);
	printf("\n");
	return 1;

}

