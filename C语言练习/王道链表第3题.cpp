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

/*	
	������� �ݹ�ʵ�� 
	����ʱ��ͷ���L����ΪL->next, ʾ����PrintRev(L->next)  
	����ͷ���L����ΪL, ʾ����PrintRev(L)
*/
void PrintRev(LinkList L) {
	if(L == NULL) return;
	PrintRev(L->next);
	printf("%d ",L->data);
}


int main() {
	LinkList L = BuildList();
	printf("����������");
	PrintL(L);
	
	printf("���������");
	PrintRev(L->next);
	printf("\n");
	return 0;
}