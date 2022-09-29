#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

ElemType a[] = {1,3,2,2,7,3};
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

//����
void PrintL(LinkList L) {
	LNode *p = L->next;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//ɾ��x
void DelX(LinkList &L, ElemType x) {
	LNode *q, *pre=L, *p=L->next;
	while(p) {
		if(p->data == x) {
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}


int main() {
	LinkList L = BuildList();
	printf("ɾ��ǰ��");
	PrintL(L);
	DelX(L, 3);
	printf("ɾ����");
	PrintL(L);
	return 0;
}