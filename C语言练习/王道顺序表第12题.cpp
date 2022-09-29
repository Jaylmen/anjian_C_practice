#include<stdio.h>

int Majority(int A[], int n){
	int c = A[0];
	int count = 1;
	int i;
	for(i=1; i<n; i++) {
		if(A[i] == c){
			count++;
		}
		else {
			count--;
			if(count == 0) {
				c = A[i];
				count = 1;
			}

		}
	}

	if(count > 0) {
		count = 0;
		for(i=0; i<n; i++) {
			if(A[i] == c)
				count++;
		}
	}

	if(count > n/2) {
		return c;
	}
	else{
		return -1;
	}
}

int main() {
	int A[] = {0,5,3,5,5,7,5,5};
	int B[] = {0,5,3,5,5,7,1,5};
	printf("%d\n", Majority(A, 8));
	printf("%d\n", Majority(B, 8));
}