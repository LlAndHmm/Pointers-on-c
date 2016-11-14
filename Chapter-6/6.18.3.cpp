#include<stdio.h>
void reverse_string(char *string) {
	int length = 0;
	while (*(string + length) != '\0') {
		length++;
	}
	for (int i = 0; i < length / 2; i++) {
		char temp = *(string + i);
		*(string + i) = *(string + length - i - 1);
		*(string + length - i - 1) = temp;
		printf("²½Öè%d£º%s\n", i + 1, string);	
	}
}
int main() {
	char string[12] = "hello world";
	reverse_string(string);
} 
