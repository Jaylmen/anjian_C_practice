#include<stdio.h>
#include<stdlib.h>

//�洢��������
typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
} ThreadNode, *ThreadTree;

//������
ThreadNode *CreateThreadTree() {
	ThreadNode *p;
	ElemType e;
	printf("������ֵ��");
	scanf(" %c", &e);
	if(e == '0')
		p = NULL;
	else {
		p = (ThreadNode *)malloc(sizeof(ThreadNode));
		p->data = e;
		printf("����%c��������\n", e);
		p->lchild = CreateThreadTree();
		printf("����%c��������\n", e);
		p->rchild = CreateThreadTree();
		p->ltag = 0;
		p->rtag = 0;
	}
	return p;
}

//ͨ����������Զ���������������
void InThread(ThreadTree &p, ThreadTree &pre) {
	if(p != NULL) {
		InThread(p->lchild, pre);
		if(p->lchild == NULL) {		//������Ϊ�գ�����ǰ������
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;		//����ǰ�����ĺ������
			pre->rtag = 1;
		}
		pre = p;					//��ǵ�ǰ���Ϊ�ոշ��ʹ��Ľ��
		InThread(p->rchild, pre);
	}
}

//ͨ������������������������������������㷨
void CreateInThreadTree(ThreadTree T) {
	ThreadNode *pre = NULL;
	if(T != NULL) {
		InThread(T, pre);
		if(pre->rchild == NULL)
			pre->rtag = 1;
	}
}

//�����������������������������µĵ�һ�����
ThreadNode *FirstNode(ThreadNode *p) {
	while(p->ltag == 0)
		p = p->lchild;
	return p;
}

//��������������p�����������µĺ��
ThreadNode *NextNode(ThreadNode *p) {
	if(p->rtag == 0)//p->rchildָ���Һ��ӣ�������������һ�������ʵĽ��
		return FirstNode(p->rchild);
	else//p->rchildָ���̣�ֱ�ӷ���p->rchild
		return p->rchild;
}

//�������
void InOrder(ThreadTree T) {
	for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
		printf("%c", p->data);
	}
}

//�����������������������������µ����һ�����
ThreadNode *LastNode(ThreadNode *p) {
	while(p->rtag == 0)
		p = p->rchild;
	return p;
}

//��������������p�����������µ�ǰ��
ThreadNode *PreNode(ThreadNode *p) {
	if(p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;
}

//�����������
void RevInOrder(ThreadTree T) {
	for(ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) {
		printf("%c", p->data);
	}
}


int main() {
	ThreadTree T = CreateThreadTree();	//����һ��������
	CreateInThreadTree(T);				//��������T����������
	ThreadNode *p = FirstNode(T);
	printf("p->data=%c\n", p->data);
	printf("p->rtag=%d\n", p->rtag);
	printf("p->rchild->data=%c\n", p->rchild->data);
	printf("NextNode(p)->data=%c\n", NextNode(p)->data);
	printf("����������У�");
	InOrder(T);
	printf("\n");
	printf("��������������У�");
	RevInOrder(T);
	printf("\n");
	return 0;
}