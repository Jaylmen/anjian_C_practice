#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//ͷ�巨����������
LinkList List_HeadInsert(LinkList &L) {
	LNode *s;
	int x = 0;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x != 999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

//β�巨����������
LinkList List_TailInsert(LinkList &L) {
	int x = 0;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L; //rΪβָ��
	scanf("%d",&x);
	while(x != 999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
}

//��ʼ����������ͷ��㣩
bool InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)
		return false;
	L->next = NULL;
	return true;
}

//�ж��Ƿ�Ϊ��
bool EmptyList(LinkList L) {
	return L->next == NULL;
}

//�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩  ����ͷ���ĵ�����i=1���д���,j��Ϊ1
bool ListInsert(LinkList &L, int i, ElemType e) {
	if(i < 1)
		return false;
	LNode *p;
	int j = 0;
	p = L;
	while(p!=NULL && j<i-1){
		p = p->next;
		j++;
	}
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//��ѯ��i��Ԫ�ص�ֵ
LNode *GetElem(LinkList L, int i) {
	int j = 1;
	LNode *p = L->next;
	if(i == 0)
		return L;
	if(i < 1)
		return NULL;
	while(p!=NULL && j<i) {
		p = p->next;
		j++;
	}
	return p;
}

int main() {
	LinkList L;
	printf("����������:\n");
	//List_HeadInsert(L);
	List_TailInsert(L);
	printf("�Ѵ���\n");
	printf("��3��Ԫ��Ϊ%d\n",GetElem(L, 3)->data);
	ListInsert(L, 2, 66);
	ListInsert(L, 3, 67);
	for(LinkList p=L->next; p!=NULL; p=p->next)
		printf("����%d\n",p->data);
}