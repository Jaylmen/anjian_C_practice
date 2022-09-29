#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LiStack;

//初始化（带头结点）
bool InitStack(LiStack &S) {
	S = (LiStack)malloc(sizeof(LNode));
	if(S == NULL)
		return false;
	S->next = NULL;
	return true;
}

//判空
bool StackEmpty(LiStack S) {
	return S->next == NULL;
}

//入栈
bool Push(LiStack &S, ElemType e) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	if(p == NULL)
		return false;
	p->data = e;
	p->next = S->next;
	S->next = p;
	return true;
}

//出栈
bool Pop(LiStack &S, ElemType &e) {
	if(StackEmpty(S))
		return false;
	LNode *p = S->next;
	S->next = p->next;
	e = p->data;
	free(p);
	return true;
}

//读取栈顶元素
bool GetTop(LiStack S, ElemType &e) {
	if(StackEmpty(S))
		return false;
	e = S->next->data;
	return true;
}


int main() {
	LiStack S;
	ElemType e;
	int n;
	InitStack(S);
	printf("初始化链栈成功！\n");
	printf("请输入想入栈的元素个数：");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("请输入入栈值：");
		scanf("%d",&e);
		Push(S, e);
		printf("%d入栈\n", e);
		if(GetTop(S, e))
			printf("栈顶元素为%d\n", e);
		else
			printf("栈空了！\n");
	}

	printf("\n依次出栈\n\n");

	for(i=0; i<n; i++) {
		Pop(S, e);
		printf("%d出栈\n", e);
		if(GetTop(S, e))
			printf("栈顶元素为%d\n", e);
		else
			printf("栈空了！\n");
	}

	return 0;
}
