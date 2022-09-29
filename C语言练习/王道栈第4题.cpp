#include<stdio.h>
#include<stdlib.h>

typedef struct LNode {
	char data;
	struct LNode *next;
}LNode, *LinkList;

char a[] = {'a','b','c','b','a'};
int n = 5;

void BuildList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	for(int i=0; i<n; i++) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

bool isOk(LinkList L, int n) {
	char *str = (char *)malloc(sizeof(char)*(n/2));
	LNode *p = L->next;
	for(int i=0; i<n/2; i++) {
		str[i] = p->data;
		p = p->next;
	}
	i--;
	if(n%2 == 1)
		p = p->next;
	while(p && p->data==str[i]) {
		i--;
		p = p->next;
	}
	free(str);
	if(i == -1) 
		return true;
	else 
		return false;
}

int main() {
	LinkList L;
	BuildList(L);
	if(isOk(L, 5))
		printf("yes\n");
	else
		printf("no\n");
	return 1;
}

