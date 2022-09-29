#include<stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

//��ʼ��
void InitQueue(SqQueue &Q) {
	Q.front = Q.rear = 0;
}

//�п�
bool isEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//���
bool EnQueue(SqQueue &Q, ElemType e) {
	if((Q.rear + 1) % MaxSize == Q.front)
		return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

//����
bool DeQueue(SqQueue &Q, ElemType &e) {
	if(Q.rear == Q.front)
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//����ͷԪ��
bool GetHead(SqQueue Q, ElemType &e) {
	if(Q.rear == Q.front) 
		return false;
	e = Q.data[Q.front];
	return true;
}

int main() {
	SqQueue Q;
	ElemType e;
	int n;
	InitQueue(Q);
	printf("��ʼ���ɹ���\n");
	printf("��������г��ȣ�");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		if((Q.rear + 1) % MaxSize != Q.front) {
			printf("������Ԫ�أ�");
			scanf("%d", &e);
			EnQueue(Q, e);
			printf("%d���\n", e);
			if(GetHead(Q, e))
				printf("��ͷԪ��Ϊ��%d\n", e);
			else
				printf("��Ϊ�գ�\n");
		}
		else
			printf("�����ˣ�\n");
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