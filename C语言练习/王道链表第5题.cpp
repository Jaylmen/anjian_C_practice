#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

ElemType a[] = {1,2,3,4,5,6};
int n = 6;
//����
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

//��������
void PrintL(LinkList L) {
	LNode *p = L->next;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//ԭ������
bool Reverse(LinkList &L) {
	LNode *p, *pre, *q;
	p = L->next;
	q = p->next;
	p->next = NULL;
	while(q){  //qΪNULL����qʱ��pΪ���һ�����
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
	printf("����ǰ��");
	PrintL(L);
	Reverse(L);
	printf("���ú�");
	PrintL(L);
	printf("\n");
	return 0;
}