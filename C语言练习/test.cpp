#include<stdio.h>

int main() {
	int x = 0, y = 0, z = 0;
	z = (x == 1) && (y = 1);
	printf("y=%d\n", y);
	printf("z=%d\n", z);
	return 0;
}