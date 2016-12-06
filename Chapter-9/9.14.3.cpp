#include<stdio.h>
char* my_strcpy(char *buffer, char *src, int size) {
	int length = 0;
	while ( length < size && *(src + length) != '\0') {
		*(buffer + length) = *(src + length);
		length++;
	}
	
	if (length == size) {
		*(buffer + size - 1) = '\0';
	}
	else {
		*(buffer + length) = '\0';
	}
	
	return buffer;
}

int main() {
	char buffer[5];
	char src[10] = "hello";
	
	printf("%s", my_strcpy(buffer, src, 5));
} 
