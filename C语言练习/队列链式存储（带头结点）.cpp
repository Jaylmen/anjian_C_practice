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

//初始化
bool InitQueue(LiQueue &Q) {
	Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
	Q.front->next = NULL;
	return true;
}

//判空
bool isEmpty(LiQueue Q) {
	return Q.rear == Q.front;
}

//入队
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

//出队
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

//读取队头元素
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
	printf("初始化成功！\n");
	printf("请输入队列长度：");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		
		printf("请输入元素：");
		scanf("%d", &e);
		EnQueue(Q, e);
		printf("%d入队\n", e);
		if(GetHead(Q, e))
			printf("队头元素为：%d\n", e);
		else
			printf("队为空！\n");

	}

	for(i=0; i<n; i++) {
		if(!isEmpty(Q)) {
			DeQueue(Q, e);
			printf("%d出队\n", e);
			if(GetHead(Q, e))
				printf("队头元素为：%d\n", e);
			else
				printf("队为空！\n");
		}
		else
			printf("队空了！\n");
	}
	return 0;
}