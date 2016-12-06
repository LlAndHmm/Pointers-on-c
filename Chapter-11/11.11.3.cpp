#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* allocate() {
	int len = 1;
	char input;
	char *buffer = (char*)malloc(sizeof(char) * 1);
	while ((input = getchar()) != '\n') {
		*(buffer + len - 1) = input;
		len++;
		realloc(buffer, len);	
	}
	//在字符串结尾加上'结束标志' 
	*(buffer + len) = '\0';
	
	return buffer;
}
int main() {
	printf("%s", allocate());
} 
