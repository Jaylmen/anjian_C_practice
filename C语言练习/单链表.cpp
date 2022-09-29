#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

//头插法创建单链表
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

//尾插法创建单链表
LinkList List_TailInsert(LinkList &L) {
	int x = 0;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L; //r为尾指针
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

//初始化单链表（带头结点）
bool InitList(LinkList &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL)
		return false;
	L->next = NULL;
	return true;
}

//判断是否为空
bool EmptyList(LinkList L) {
	return L->next == NULL;
}

//在第i个位置插入元素e（带头结点）  不带头结点的单独对i=1进行处理,j设为1
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

//查询第i个元素的值
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
	printf("请输入数据:\n");
	//List_HeadInsert(L);
	List_TailInsert(L);
	printf("已创建\n");
	printf("第3个元素为%d\n",GetElem(L, 3)->data);
	ListInsert(L, 2, 66);
	ListInsert(L, 3, 67);
	for(LinkList p=L->next; p!=NULL; p=p->next)
		printf("数据%d\n",p->data);
}