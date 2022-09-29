#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode;

typedef struct{
	LNode *front;
	LNode *rear;
} LiQueue;

//��ʼ��
bool InitQueue(LiQueue &Q) {
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.front->next = NULL;
	return true;
}

//�п�
bool isEmpty(LiQueue Q) {
	return Q.rear == Q.front;
}

//���
bool EnQueue(LiQueue &Q, ElemType e) {
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
bool DeQueue(LiQueue &Q, ElemType &e) {
	if(isEmpty(Q))
		return false;
	LNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if(Q.front->next == NULL)
		Q.rear = Q.front;
	free(p);	
	return true;
}

//��ȡ��ͷԪ��
bool GetHead(LiQueue Q, ElemType &e) {
	if(isEmpty(Q))
		return false;
	e = Q.front->next->data;
	return true;
}

int main() {
	LiQueue Q;
	ElemType e;
	int n;
	InitQueue(Q);
	printf("��ʼ���ɹ���\n");
	printf("��������г��ȣ�");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		
		printf("������Ԫ�أ�");
		scanf("%d", &e);
		EnQueue(Q, e);
		printf("%d���\n", e);
		if(GetHead(Q, e))
			printf("��ͷԪ��Ϊ��%d\n", e);
		else
			printf("��Ϊ�գ�\n");

	}

	for(i=0; i<n; i++) {
		if(!isEmpty(Q)) {
			DeQueue(Q, e);
			printf("%d����\n", e);
			if(GetHead(Q, e))
				printf("��ͷԪ��Ϊ��%d\n", e);
			else
				printf("��Ϊ�գ�\n");
		}
		else
			printf("�ӿ��ˣ�\n");
	}
	return 0;
}