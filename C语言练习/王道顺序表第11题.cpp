#include<stdio.h>

int P(int m) {
	if(m%2 == 0)
		return m/2-1;
	else
		return m/2;
}

int MidNum(int A[], int La, int B[], int Lb) {
	int k =0, i=0, j=0;
	while(i<La && j<Lb) {
		if(k == P(La+Lb)) {
			if(A[i] <= B[j])
				return A[i];
			else
				return B[j];
		}
		
		if(A[i] < B[j]){
			i++;
			k++;
		}
		else{
			j++;
			k++;
		}
	}

	while(i < La){
		if(k == P(La+Lb)) {
			if(A[i] < B[j])
				return A[i];
			else
				return B[j];
		}
		i++;
		k++;
		
	}
	while(j < Lb) {
		if(k == P(La+Lb)) {
			if(A[i] < B[j])
				return A[i];
			else
				return B[j];
		}
		j++;
		k++;
		
	}
	return -1;
}

int main() {
	int S1[] = {11,13,15,17,19};
	int S2[] = {2,4,6,8,20};
	int S3[] = {11,17};
	int S4[] = {13,15,19};
	int Mid = MidNum(S1, 5, S2, 5);
	printf("%d\n", Mid);
	printf("%d\n", MidNum(S3, 2, S4, 3));
	return 0;
}