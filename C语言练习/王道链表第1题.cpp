#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

ElemType a[] = {3,3,2,2,3,3};
int n = 6;
LinkList BuildList() {
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r=L;
	L->data = a[0];
	for(int i=1; i<n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}

void PrintL(LinkList L) {
	LNode *p = L;
	while(p) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

//删除X    因为引用，所以L=L->next是真正改变原链表，而非仅仅只是将指针L指向L->next
void DelX(LinkList &L, ElemType x) {
	if(L == NULL) return;
	LNode *p;
	if(L->data == x) {
		p = L;
		L = L->next;
		free(p);
		DelX(L, x);
	}
	else
		DelX(L->next, x);
}

int main() {
	LinkList L = BuildList();
	printf("删除前：");
	PrintL(L);
	DelX(L, 3);
	printf("删除后：");
	PrintL(L);
	return 0;
}