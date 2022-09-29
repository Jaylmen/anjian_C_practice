#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LiStack;

//��ʼ������ͷ��㣩
bool InitStack(LiStack &S) {
	S = (LiStack)malloc(sizeof(LNode));
	if(S == NULL)
		return false;
	S->next = NULL;
	return true;
}

//�п�
bool StackEmpty(LiStack S) {
	return S->next == NULL;
}

//��ջ
bool Push(LiStack &S, ElemType e) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	if(p == NULL)
		return false;
	p->data = e;
	p->next = S->next;
	S->next = p;
	return true;
}

//��ջ
bool Pop(LiStack &S, ElemType &e) {
	if(StackEmpty(S))
		return false;
	LNode *p = S->next;
	S->next = p->next;
	e = p->data;
	free(p);
	return true;
}

//��ȡջ��Ԫ��
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
	printf("��ʼ����ջ�ɹ���\n");
	printf("����������ջ��Ԫ�ظ�����");
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		printf("��������ջֵ��");
		scanf("%d",&e);
		Push(S, e);
		printf("%d��ջ\n", e);
		if(GetTop(S, e))
			printf("ջ��Ԫ��Ϊ%d\n", e);
		else
			printf("ջ���ˣ�\n");
	}

	printf("\n���γ�ջ\n\n");

	for(i=0; i<n; i++) {
		Pop(S, e);
		printf("%d��ջ\n", e);
		if(GetTop(S, e))
			printf("ջ��Ԫ��Ϊ%d\n", e);
		else
			printf("ջ���ˣ�\n");
	}

	return 0;
}
