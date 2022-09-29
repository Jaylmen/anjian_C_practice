#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BTNode {
	ElemType data;
	struct BTNode *lchild, *rchild;
} BTNode, *BTree;

typedef struct LNode {
	BTNode *data;
	struct LNode *next;
} LNode, *LinkStack;

typedef struct {
	LNode *front;
	LNode *rear;
} LinkQueue;

//栈的初始化(带头结点)
void InitStack(LinkStack &S) {
	S = (LNode *)malloc(sizeof(LNode));
	S->next = NULL;
}

//入栈
bool Push(LinkStack &S, BTNode *e) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	if(p == NULL)
		return false;
	p->data = e;
	p->next = S->next;
	S->next = p;
	return true;
}

//出栈
bool Pop(LinkStack &S, BTNode* &e) {
	if(S->next == NULL)
		return false;
	LNode *p = S->next;
	e = p->data;
	S->next = p->next;
	free(p);
	return true;
}

//读栈顶元素
bool GetTop(LinkStack S, BTNode* &e) {
	if(S->next == NULL)
		return false;
	LNode *p = S->next;
	e = p->data;
	return true;
}

//栈判空
bool isEmpty(LinkStack S) {
	return S->next == NULL;
}

//队列初始化(带头结点)
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.front->next = NULL;
}

//入队
bool EnQueue(LinkQueue &Q, BTNode *e) {
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)
		return false;
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}

//出队
bool DeQueue(LinkQueue &Q, BTNode* &e) {
	if(Q.rear == Q.front) 
		return false;
	LNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return true;
}

//队判空
bool isEmpty(LinkQueue Q) {
	return Q.rear == Q.front;
}

//生成树
BTNode *CreateBTree() {
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
		p->lchild = CreateBTree();
		printf("生成%c的右孩子\n", e);
		p->rchild = CreateBTree();
	}
	return p;
}

//先序遍历——递归
void PreOrder(BTree T) {
	if(T != NULL) {
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序遍历——递归
void InOrder(BTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

//后序遍历——递归
void PostOrder(BTree T) {
	if(T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}

//先序遍历——非递归
void PreOrder2(BTree T) {
	LinkStack S;
	InitStack(S);
	BTree p = T;
	while(p || !isEmpty(S)) {
		if(p) {
			printf("%c", p->data);
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			p = p->rchild;
		}
	}
}

//中序遍历——非递归
void InOrder2(BTree T) {
	LinkStack S;
	InitStack(S);
	BTree p = T;
	while(p || !isEmpty(S)) {
		if(p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			printf("%c", p->data);
			p = p->rchild;
		}
	}
}

//后序遍历——非递归
void PostOrder2(BTree T) {
	LinkStack S;
	InitStack(S);
	BTree p = T, r = NULL;
	while(p || !isEmpty(S)) {
		if(p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			GetTop(S, p);
			if(p->rchild && p->rchild != r)
				p = p->rchild;
			else {
				Pop(S, p);
				printf("%c", p->data);
				r = p;
				p = NULL;
			}
		}
	}
}

//层序遍历
void LevelOrder(BTree T) {
	LinkQueue Q;
	InitQueue(Q);
	BTNode *p;
	EnQueue(Q, T);
	while(!isEmpty(Q)) {
		DeQueue(Q, p);
		printf("%c", p->data);
		if(p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if(p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}

int main() {
	BTree T = CreateBTree();
	printf("先序遍历：");
	PreOrder(T);
	printf("\n");
	printf("中序遍历：");
	InOrder(T);
	printf("\n");
	printf("后序遍历：");
	PostOrder(T);
	printf("\n");
	printf("先序遍历(非递归)：");
	PreOrder2(T);
	printf("\n");
	printf("中序遍历(非递归)：");
	InOrder2(T);
	printf("\n");
	printf("后序遍历(非递归)：");
	PostOrder2(T);
	printf("\n");
	printf("层序遍历：");
	LevelOrder(T);
	printf("\n");
	return 0;
}
