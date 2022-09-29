#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef int ElemType;

typedef struct{
	ElemType data[MaxSize];
	int top1;
	int top2;
}CoStack;

//��ʼ��
bool InitStack(CoStack &S) {
	S.top1 = -1;
	S.top2 = MaxSize;
	return true;
}

//�ж�ջ��
bool isFull(CoStack S) {
	return S.top1 + 1 == S.top2;
}



//s1��ջ
bool PushS1(CoStack &S, ElemType e) {
	if(isFull(S))
		return false;
	S.data[++S.top1] = e;
	return true;
}

//s1��ջ
bool PopS1(CoStack &S, ElemType &e) {
	if(S.top1 == -1)
		return false;
	e = S.data[S.top1--];
	return true;
}

//s2��ջ
bool PushS2(CoStack &S, ElemType e) {
	if(isFull(S))
		return false;
	S.data[--S.top2] = e;
	return true;
}

//s2��ջ
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