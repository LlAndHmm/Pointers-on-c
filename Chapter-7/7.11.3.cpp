#include<stdio.h>
int ascii_to_integer(char *string) {
	int value = 0;
	while (*string >= '0' && *string <= '9') {
		value *= 10;
		value += *string - '0';
		string++;
	}
	if (*string != '\0') {
		value = 0;
	}
	return value;
}
int main() {
	char string[10] = "12345";
	printf("%d", ascii_to_integer(string));
}
