#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

ElemType a[] = {1,2,3,4,5,6};
int n = 6;
//建表
LinkList BuildList() {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r=L;
	
	for(int i=0; i<n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}

//正常遍历
void PrintL(LinkList L) {
	LNode *p = L->next;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//原地逆置
bool Reverse(LinkList &L) {
	LNode *p, *pre, *q;
	p = L->next;
	q = p->next;
	p->next = NULL;
	while(q){  //q为NULL即非q时，p为最后一个结点
		pre = p;
		p = q;
		q = q->next;
		p->next = pre;
	}
	L->next = p;
	return true;
}

int main() {
	LinkList L = BuildList();
	printf("逆置前：");
	PrintL(L);
	Reverse(L);
	printf("逆置后：");
	PrintL(L);
	printf("\n");
	return 0;
}