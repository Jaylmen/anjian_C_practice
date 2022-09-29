#include<stdio.h>

#define MaxSize 10
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

bool InitList(SqList &L) {
	for(int i=0; i<MaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
	return true;
}

bool ListInsert(SqList &L, int i, ElemType e) {
	if(i<1 || i>L.length+1)
		return false;
	if(L.length >= MaxSize)
		return false;
	for(int j=L.length; j>=i; j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
	if(i<1 || i>L.length)
		return false;
	e = L.data[i-1];
	for(int j=i; j<L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

ElemType GetElem(SqList L, int i) {
	return L.data[i-1];
}

int LocateElem(SqList L, ElemType e) {
	for(int i=0; i<L.length; i++) {
		if(L.data[i] == e)
			return i+1;
	}
	return 0;
}

bool ListEmpty(SqList L) {
	return L.length ==0;
}



int main() {
	SqList L;
	ElemType e;
	InitList(L);
	if(ListEmpty(L))
		printf("�ձ�\n");
	else
		printf("�ǿ�\n");
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);	
	ListDelete(L,2,e);
	printf("�ɹ�ɾ����2��Ԫ��%d\n",e);
	printf("�Ƿ�����\n");
	for(int i=0; i<MaxSize; i++)
		printf("%d\n",L.data[i]);
	printf("�Ϸ�����\n");
	for(i=0; i<L.length; i++)
		printf("%d\n",L.data[i]);
	if(ListEmpty(L))
		printf("�ձ�\n");
	else
		printf("�ǿ�\n");
	return true;
}