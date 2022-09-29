#include<stdio.h>
#include<stdlib.h>

//�洢��������
typedef struct BSTNode {
	int key;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//����
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

//����
void Create_BST(BSTree &T, int arr[], int n) {
	T = NULL;
	for(int i=0; i<n; i++)
		BST_Insert(T, arr[i]);
}

//����
BSTNode *BST_Search(BSTree T, int k) {
	while(T != NULL && k != T->key) { //�����ջ�С�ڸ����ֵ������ѭ��
		if(k < T->key)					//С�ڸ����ֵ��������������
			T = T->lchild;
		else							//���ڸ����ֵ��������������
			T = T->rchild;
	}
	return T;
}



//ɾ��
bool BST_Delete(BSTree &T, int k) {
	BSTNode *p = T, *parent = NULL;

	while(p != NULL && k != p->key) {
		parent = p;
		if(k < p->key)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if(p == NULL)//Ҫɾ����㲻����
		return false;
	if(p->lchild == NULL && p->rchild == NULL) {//ɾ�����ΪҶ�ӽ��
		if(parent->lchild == p)
			parent->lchild = NULL;
		else
			parent->rchild = NULL;
		free(p);
		return true;
	}
	else if(p->lchild != NULL && p->rchild != NULL) {//ɾ�������������������
		BSTNode *rsn = p->rchild;
		BSTNode *rsnp = p;
		while(rsn->lchild != NULL) {//�ҵ�����������������е�һ�������ʵĽ��rsn
			rsnp = rsn;
			rsn = rsn->lchild;
		}
		int temp = p->key;//������ɾ���������rsn��ֵ
		p->key = rsn->key;
		rsn->key = temp;
		if(rsn->lchild == NULL && rsn->rchild == NULL) {//rsnΪҶ�ӽ��
			if(rsnp->lchild == rsn)
				rsnp->lchild = NULL;
			else
				rsnp->rchild = NULL;
			
		}
		else if(rsn->rchild != NULL) {//rsnֻ��������
			if(rsnp->lchild == rsn)
				rsnp->lchild = rsn->rchild;
			else
				rsnp->rchild = rsn->rchild;
		}
		free(rsn);
		return true;
	}
	else if(p->lchild != NULL) {//ɾ�����ֻ��������
		if(parent->lchild == p)
			parent->lchild = p->lchild;
		else
			parent->rchild = p->lchild;
		free(p);
		return true;
	}
	else {//ɾ�����ֻ��������
		if(parent->lchild == p)
			parent->lchild = p->rchild;
		else
			parent->rchild = p->rchild;
		free(p);
		return true;		
	}
}

//����������ݹ飩
void InOrder(BSTree T) {
	if(T != NULL) {
		InOrder(T->lchild);
		printf("%d ", T->key);
		InOrder(T->rchild);
	}
}

//����������ݹ飩
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
	printf("���������");
	InOrder(T);
	printf("\n");
	printf("���������");
	PreOrder(T);
	printf("\n");
	p = BST_Search(T, k);
	printf("%d������Ϊ%d\n", p->key, p->lchild->key);
	printf("%d���Һ���Ϊ%d\n", p->key, p->rchild->key);
	BST_Delete(T, 19);
	printf("���������");
	InOrder(T);
	printf("\n");
	printf("���������");
	PreOrder(T);
	printf("\n");
	return 0;
}