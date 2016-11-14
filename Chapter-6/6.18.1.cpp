#include<stdio.h>
char* find_char(char const *source,
	char const *chars) 
{
	int i, j;
	int flag = 0;
	if (*source != '\0' && *chars != '\0' && source != NULL && chars != NULL) {
		for (i = 0; *(chars + i) !='\0'; i++) {
			if (flag == 1) break;
			for (j = 0; *(source + j) != '\0'; j++) {
				if (*(chars + i) == *(source + j)) {
					flag = 1;
					break;
				}
			}	
		}	
	}
	else {
		printf("wrong!");
		return NULL;
	}
	 
	if (flag == 1) {
		return (char*)source + j;	
	}	
	else {
		
		return NULL;
	}
} 
int main() {
	char source[100] = "ABCDEF";
	printf("source:%s\n", source); 
	char chars[100] = "XRCQEF";
	printf("chars :%s\n", chars);
	char* p;
	p = find_char(source, chars);
	
	if (p == NULL) {
		printf("havent found!");
	}
	else {
		printf("%c", *p);
	}
	
} 
