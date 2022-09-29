#include<stdio.h>
#include<stdlib.h>

//存储类型描述
typedef char ElemType;
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
} ThreadNode, *ThreadTree;

//生成树
ThreadNode *CreateThreadTree() {
	ThreadNode *p;
	ElemType e;
	printf("请输入值：");
	scanf(" %c", &e);
	if(e == '0')
		p = NULL;
	else {
		p = (ThreadNode *)malloc(sizeof(ThreadNode));
		p->data = e;
		printf("生成%c的左子树\n", e);
		p->lchild = CreateThreadTree();
		printf("生成%c的右子树\n", e);
		p->rchild = CreateThreadTree();
		p->ltag = 0;
		p->rtag = 0;
	}
	return p;
}

//通过中序遍历对二叉树进行线索化
void InThread(ThreadTree &p, ThreadTree &pre) {
	if(p != NULL) {
		InThread(p->lchild, pre);
		if(p->lchild == NULL) {		//左子树为空，建立前驱线索
			p->lchild = pre;
			p->ltag = 1;
		}
		if(pre != NULL && pre->rchild == NULL) {
			pre->rchild = p;		//建立前驱结点的后继线索
			pre->rtag = 1;
		}
		pre = p;					//标记当前结点为刚刚访问过的结点
		InThread(p->rchild, pre);
	}
}

//通过中序遍历建立中序线索二叉树的主过程算法
void CreateInThreadTree(ThreadTree T) {
	ThreadNode *pre = NULL;
	if(T != NULL) {
		InThread(T, pre);
		if(pre->rchild == NULL)
			pre->rtag = 1;
	}
}

//求中序线索二叉树中在中序序列下的第一个结点
ThreadNode *FirstNode(ThreadNode *p) {
	while(p->ltag == 0)
		p = p->lchild;
	return p;
}

//求中序二叉树结点p在中序序列下的后继
ThreadNode *NextNode(ThreadNode *p) {
	if(p->rtag == 0)//p->rchild指向右孩子，返回右子树第一个被访问的结点
		return FirstNode(p->rchild);
	else//p->rchild指向后继，直接返回p->rchild
		return p->rchild;
}

//中序遍历
void InOrder(ThreadTree T) {
	for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
		printf("%c", p->data);
	}
}

//求中序线索二叉树中在中序序列下的最后一个结点
ThreadNode *LastNode(ThreadNode *p) {
	while(p->rtag == 0)
		p = p->rchild;
	return p;
}

//求中序二叉树结点p在中序序列下的前驱
ThreadNode *PreNode(ThreadNode *p) {
	if(p->ltag == 0)
		return LastNode(p->lchild);
	else
		return p->lchild;
}

//逆向中序遍历
void RevInOrder(ThreadTree T) {
	for(ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) {
		printf("%c", p->data);
	}
}


int main() {
	ThreadTree T = CreateThreadTree();	//创建一个二叉树
	CreateInThreadTree(T);				//将二叉树T中序线索化
	ThreadNode *p = FirstNode(T);
	printf("p->data=%c\n", p->data);
	printf("p->rtag=%d\n", p->rtag);
	printf("p->rchild->data=%c\n", p->rchild->data);
	printf("NextNode(p)->data=%c\n", NextNode(p)->data);
	printf("中序遍历序列：");
	InOrder(T);
	printf("\n");
	printf("反向中序遍历序列：");
	RevInOrder(T);
	printf("\n");
	return 0;
}