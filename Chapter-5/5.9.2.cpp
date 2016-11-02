#include<stdio.h>
void lower_case_encrypt(int ch) {
	ch = ch + 13 - 96;
	if (ch > 26) {
		ch = ch % 26;
	}
	printf("%c", ch + 96);
}
void upper_case_encrypt(int ch) {
	ch = ch + 13 - 64;
	if (ch > 26) {
		ch = ch % 26;
	}
	printf("%c", ch + 64);
}
int main() {
	int ch;
	while((ch = getchar())!= '\n') {
		if(ch >= 65 && ch <= 90) {
			upper_case_encrypt(ch);
		}
		else if(ch >= 97 && ch <= 122) {
			lower_case_encrypt(ch);
		}
		else {
			printf("%c", ch);
		}
	}
}
