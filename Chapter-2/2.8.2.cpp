#include<stdio.h>
#define MAX_NUM 100
//简化成括号匹配问题 

char stack[100];	//初始化一个栈
int top = -1;		
 
int main() {
	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch == '(') {
			top = top + 1;
			stack[top] = ch;
		}
		if (ch == ')') {
			if (stack[top] == '(') {
				stack[top] = 0;
				top = top - 1;
			}
		}
	}
	if (top == -1) {
		printf("括号是匹配的!\n");
	} else {
		printf("括号不匹配!\n");
	}
} 
