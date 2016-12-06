#include<stdio.h>
int my_strnchr( char const *str, int ch, int which ) {
	int index = 0;
	while ( which > 0 && *(str + index) != '\0' ) {
		if (*(str + index) == ch) {
			which--;
		}
		index++;
	}
	if (which > 0) {
		printf("have not found");
	}
	else {
		return index - 1;
	}
}
int main() {
	char str[20] = "hello world!";
	printf("%d", my_strnchr(str, 'l', 2));
} 
