#include<stdio.h>

typedef int ElemType;

void Reverse(ElemType A[], int left, int right, int ArrSize) {
	if(left>=right || right>=ArrSize)
		return;
	int mid = (left + right) / 2;
	ElemType temp;
	for(int i=left; i<=mid; i++) {
		temp = A[i];
		A[i] = A[right+left-i];
		A[right+left-i] = temp;
	}
}

void Exchange(ElemType A[], int m, int n, int ArrSize) {
	Reverse(A, 0, m+n-1, ArrSize); //全部翻转
	Reverse(A, 0, n-1, ArrSize); //前n项和后m项分别翻转
	Reverse(A, n, m+n-1, ArrSize);
}

int main() {
	int A[]={1,2,3,4,5,11,22,33,44,55,66};
	Exchange(A, 5, 6, 11);
	printf("置换后：");
	for(int i=0; i<11; i++)
		printf("%d ",A[i]);
	printf("\n");
	return 0;
}

