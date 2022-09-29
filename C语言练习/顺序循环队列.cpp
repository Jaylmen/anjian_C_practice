#include<stdio.h>

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int front, rear;
} SqQueue;

//初始化
void InitQueue(SqQueue &Q) {
	Q.front = Q.rear = 0;
}

//判空
bool isEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}

//入队
bool EnQueue(SqQueue &Q, ElemType e) {
	if((Q.rear + 1) % MaxSize == Q.front)
		return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &e) {
	if(Q.rear == Q.front)
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}

//读队头元素
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
	printf("初始化成功！\n");
	printf("请输入队列长度：");
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		if((Q.rear + 1) % MaxSize != Q.front) {
			printf("请输入元素：");
			scanf("%d", &e);
			EnQueue(Q, e);
			printf("%d入队\n", e);
			if(GetHead(Q, e))
				printf("队头元素为：%d\n", e);
			else
				printf("队为空！\n");
		}
		else
			printf("队满了！\n");
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