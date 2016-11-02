#include<stdio.h>
#include<string.h>
int main() {
	char input[129];
	char str_prev[129];
	bool printed = false;
	if (gets(str_prev) != NULL) {
		while (gets(input) != NULL) {
			if (strcmp(str_prev, input) != 0) {
				printed = false;
				strcpy(str_prev, input);
			}
			else if (printed == false) {
				printed = true;
				printf("the repeat str is:%s\n", str_prev);
			}
		}
	}
}
