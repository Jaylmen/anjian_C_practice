#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10
typedef char ElemType;
typedef struct {
	ElemType data[MaxSize];
	int top;
}Stack;

bool bracketCheck(char str[], int length) {
	Stack S;
	S.top = -1;
	for(int i=0; i<8; i++) {
		if(str[i]=='{' || str[i]=='[' || str[i]=='(') {
			if(S.top+1 != MaxSize){
				S.top++;
				S.data[S.top] = str[i];
				printf("%c入栈\n",str[i]);
			}
			else{
				printf("栈已满，无法入栈\n");
				return false;
			}

		}
		else {
			if(S.top == -1)
				return false;

			char ele;
			ele = S.data[S.top];
			printf("%c出栈\n",ele);
			S.top--;
			if(ele=='(' && str[i]!=')')
				return false;
			if(ele=='{' && str[i]!='}')
				return false;
			if(ele=='[' && str[i]!=']')
				return false;
		}
	}

	return S.top==-1;
}

int main() {
	char str[] = {'[','(','[',']','[',']',')',']'};
	
	if(bracketCheck(str, 8))
		printf("匹配成功！\n");
	else
		printf("匹配失败！\n");
	return 0;
}