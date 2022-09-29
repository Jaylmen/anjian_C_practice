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

/*	
	反向遍历 递归实现 
	调用时带头结点L传参为L->next, 示例：PrintRev(L->next)  
	不带头结点L传参为L, 示例：PrintRev(L)
*/
void PrintRev(LinkList L) {
	if(L == NULL) return;
	PrintRev(L->next);
	printf("%d ",L->data);
}


int main() {
	LinkList L = BuildList();
	printf("正常遍历：");
	PrintL(L);
	
	printf("反向遍历：");
	PrintRev(L->next);
	printf("\n");
	return 0;
}