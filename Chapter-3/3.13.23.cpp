#include<stdio.h>
static char b = 2; 

void y(void) {
	int a;
	printf("y.a = %d\n", a);
	printf("y.b = %c\n", b);
} 

int a = 1;

void x(void) {
	int c = 3;
	static float d = 4;	
	printf("x.a = %d\n", a);
	printf("x.b = %c\n", b);
}

int main() {
	x();
	y();
} 
