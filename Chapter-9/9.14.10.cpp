#include<stdio.h>
#include<ctype.h>
#include<string.h> 
void check( char *src ) {
	int front = 0;
	int rear = strlen(src) - 1;
	while ( front < rear ) {
		if (*(src + front) != *(src + rear)) {
			break;
		}
		front++;
		rear--;
	}
	//字符串长度为偶数，匹配时front会比rear大1 
	if ( front >= rear ) {
		printf("yes");
	}
	else {
		printf("no");
	}
}
int main() {
	char src[20] = "HellOolleh";
	for ( int i = 0; src[i] != '\0'; i++ ) {
		src[i] = tolower(src[i]);
	}

	check(src);
}

