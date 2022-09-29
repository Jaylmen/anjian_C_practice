#include<stdio.h>
#include<stdlib.h>

//存储类型描述
typedef struct BSTNode {
	int key;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//插入
int BST_Insert(BSTree &T, int k) {
	if(T == NULL) {
		T = (BSTNode *)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	else if(T->key == k)
		return 0;
	else if(k < T->key)
		return BST_Insert(T->lchild, k);
	else if(k > T->key)
		return BST_Insert(T->rchild, k); 
}

//构造
void Create_BST(BSTree &T, int arr[], int n) {
	T = NULL;
	for(int i=0; i<n; i++)
		BST_Insert(T, arr[i]);
}

//查找
BSTNode *BST_Search(BSTree T, int k) {
	while(T != NULL && k != T->key) { //若树空或小于根结点值，结束循环
		if(k < T->key)					//小于根结点值，在左子树查找
			T = T->lchild;
		else							//大于根结点值，在右子树查找
			T = T->rchild;
	}
	return T;
}



//删除
bool BST_Delete(BSTree &T, int k) {
	BSTNode *p = T, *parent = NULL;

	while(p != NULL && k != p->key) {
		parent = p;
		if(k < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if(p == NULL)//要删除结点不存在
		return false;
	if(p->lchild == NULL && p->rchild == NULL) {//删除结点为叶子结点
		if(parent->lchild == p)
			parent->lchild = NULL;
		else
			parent->rchild = NULL;
		free(p);
		return true;
	}
	else if(p->lchild != NULL && p->rchild != NULL) {//删除结点左右子树都存在
		BSTNode *rsn = p->rchild;
		BSTNode *rsnp = p;
		while(rsn->lchild != NULL) {//找到右子树中序遍历序列第一个被访问的结点rsn
			rsnp = rsn;
			rsn = rsn->lchild;
		}
		int temp = p->key;//交换待删除结点与结点rsn的值
		p->key = rsn->key;
		rsn->key = temp;
		if(rsn->lchild == NULL && rsn->rchild == NULL) {//rsn为叶子结点
			if(rsnp->lchild == rsn)
				rsnp->lchild = NULL;
			else
				rsnp->rchild = NULL;
			
		}
		else if(rsn->rchild != NULL) {//rsn只有右子树
			if(rsnp->lchild == rsn)
				rsnp->lchild = rsn->rchild;
			else
				rsnp->rchild = rsn->rchild;
		}
		free(rsn);
		return true;
	}
	else if(p->lchild != NULL) {//删除结点只有左子树
		if(parent->lchild == p)
			parent->lchild = p->lchild;
		else
			parent->rchild = p->lchild;
		free(p);
		return true;
	}
	else {//删除结点只有右子树
		if(parent->lchild == p)
			parent->lchild = p->rchild;
		else
			parent->rchild = p->rchild;
		free(p);
		return true;		
	}
}

//中序遍历（递归）
void InOrder(BSTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		printf("%d ", T->key);
		InOrder(T->rchild);
	}
}

//先序遍历（递归）
void PreOrder(BSTree T) {
	if(T != NULL) {
		printf("%d ", T->key);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}


int main() {
	BSTree T;
	BSTNode *p;
	int k = 66;
	int arr[] = {19, 13, 11, 8, 50, 26, 21, 30, 66, 60, 63, 61, 65, 70};
	Create_BST(T, arr, 14);
	printf("中序遍历：");
	InOrder(T);
	printf("\n");
	printf("先序遍历：");
	PreOrder(T);
	printf("\n");
	p = BST_Search(T, k);
	printf("%d的左孩子为%d\n", p->key, p->lchild->key);
	printf("%d的右孩子为%d\n", p->key, p->rchild->key);
	BST_Delete(T, 19);
	printf("中序遍历：");
	InOrder(T);
	printf("\n");
	printf("先序遍历：");
	PreOrder(T);
	printf("\n");
	return 0;
}