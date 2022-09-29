#include<stdio.h>

#define MaxSize 100

double p(int n, double x) {
	struct stack {
		int no;
		double val;
	}st[MaxSize];
	int top = -1;
	double fv1 = 1, fv2;
	fv2 = 2 * x;
	
	for(int i=n; i>=2; i--) {
		top++;
		st[top].no = n;
	}

	while(top >= 0) { 
		st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
		fv1 = fv2;
		fv2 = st[top].val;
		top--;
	}
	
	if(n == 0)
		return fv1;
	else
		return fv2;
}

int main() {
	int n = 0;
	double x = 0;
	printf("请输入n的值：");
	scanf("%d", &n);
	printf("请输入x的值：");
	scanf("%lf", &x);

	printf("P%d(%.2f)=%.2of\n", n, x, p(n, x));
	return 0;
}