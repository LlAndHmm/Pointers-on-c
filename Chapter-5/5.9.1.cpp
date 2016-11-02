#include<stdio.h>
int main() {
	char ch;
	while ((ch = getchar()) != '\n') {
		if (ch <= 90 && ch >= 65) {
			ch = ch | 0x20;
		}
		printf("%c", ch);
	}
}
