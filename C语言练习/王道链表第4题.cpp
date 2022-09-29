#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

ElemType a[] = {2,4,3,1,5,6};
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

bool DelMin(LinkList &L) {
	if(L==NULL || L->next==NULL)
		return false;
	LNode *p, *pre, *min, *minPre;
	p = L->next;
	pre = L;
	min = p;
	minPre = pre;
	while(p) {
		if(p->data < min->data) {
			min = p;
			minPre = pre;
		}
		pre = p;
		p = p->next;
	}
	minPre->next = min->next;
	free(min);
	return true;
}

int main() {
	LinkList L = BuildList();
	printf("删除前：");
	PrintL(L);
	DelMin(L);
	printf("删除后：");
	PrintL(L);
	printf("\n");
	return 0;
}