#include<stdio.h>
int main() {
	char checksum = -1;
	char a = getchar();
	while(a != '\n') {
		int temp = checksum;
		checksum = checksum + a;
		printf("%c", a);
		a = getchar(); 
	}
	checksum = checksum + a;
	printf("\n");
	printf("%d", checksum);
}
