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

//ջ�ĳ�ʼ��(��ͷ���)
void InitStack(LinkStack &S) {
	S = (LNode *)malloc(sizeof(LNode));
	S->next = NULL;
}

//��ջ
bool Push(LinkStack &S, BTNode *e) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	if(p == NULL)
		return false;
	p->data = e;
	p->next = S->next;
	S->next = p;
	return true;
}

//��ջ
bool Pop(LinkStack &S, BTNode* &e) {
	if(S->next == NULL)
		return false;
	LNode *p = S->next;
	e = p->data;
	S->next = p->next;
	free(p);
	return true;
}

//��ջ��Ԫ��
bool GetTop(LinkStack S, BTNode* &e) {
	if(S->next == NULL)
		return false;
	LNode *p = S->next;
	e = p->data;
	return true;
}

//ջ�п�
bool isEmpty(LinkStack S) {
	return S->next == NULL;
}

//���г�ʼ��(��ͷ���)
void InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.front->next = NULL;
}

//���
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

//����
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

//���п�
bool isEmpty(LinkQueue Q) {
	return Q.rear == Q.front;
}

//������
BTNode *CreateBTree() {
	BTNode *p;
	ElemType e;
	printf("������Ԫ�أ�");
	scanf(" %c", &e);
	if(e == '0')
		p = NULL;
	else {
		p = (BTNode *)malloc(sizeof(BTNode));
		p->data = e;
		printf("����%c������\n", e);
		p->lchild = CreateBTree();
		printf("����%c���Һ���\n", e);
		p->rchild = CreateBTree();
	}
	return p;
}

//������������ݹ�
void PreOrder(BTree T) {
	if(T != NULL) {
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//������������ݹ�
void InOrder(BTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

//������������ݹ�
void PostOrder(BTree T) {
	if(T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c", T->data);
	}
}

//������������ǵݹ�
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

//������������ǵݹ�
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

//������������ǵݹ�
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

//�������
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
	printf("���������");
	PreOrder(T);
	printf("\n");
	printf("���������");
	InOrder(T);
	printf("\n");
	printf("���������");
	PostOrder(T);
	printf("\n");
	printf("�������(�ǵݹ�)��");
	PreOrder2(T);
	printf("\n");
	printf("�������(�ǵݹ�)��");
	InOrder2(T);
	printf("\n");
	printf("�������(�ǵݹ�)��");
	PostOrder2(T);
	printf("\n");
	printf("���������");
	LevelOrder(T);
	printf("\n");
	return 0;
}
