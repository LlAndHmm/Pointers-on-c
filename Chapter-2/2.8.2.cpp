#include<stdio.h>
#define MAX_NUM 100
//�򻯳�����ƥ������ 

char stack[100];	//��ʼ��һ��ջ
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
		printf("������ƥ���!\n");
	} else {
		printf("���Ų�ƥ��!\n");
	}
} 
