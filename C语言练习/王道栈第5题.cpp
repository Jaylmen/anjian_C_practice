#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int top1;
	int top2;
}CoStack;

//初始化
bool InitStack(CoStack &S) {
	S.top1 = -1;
	S.top2 = MaxSize;
	return true;
}

//判断栈满
bool isFull(CoStack S) {
	return S.top1 + 1 == S.top2;
}



//s1入栈
bool PushS1(CoStack &S, ElemType e) {
	if(isFull(S))
		return false;
	S.data[++S.top1] = e;
	return true;
}

//s1出栈
bool PopS1(CoStack &S, ElemType &e) {
	if(S.top1 == -1)
		return false;
	e = S.data[S.top1--];
	return true;
}

//s2入栈
bool PushS2(CoStack &S, ElemType e) {
	if(isFull(S))
		return false;
	S.data[--S.top2] = e;
	return true;
}

//s2出栈
bool PopS2(CoStack &S, ElemType &e) {
	if(S.top2 == MaxSize)
		return false;
	e = S.data[S.top2++];
	return true;
}

int main() {
	CoStack S;
	InitStack(S);
	return 0;

}