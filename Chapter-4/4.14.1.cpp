#include<stdio.h>
int count = 0;	//计数guess了几次 
float sqrt(int n) {
	float guess = 1;
	while (guess != ((guess + n / guess) / 2)) {
		guess = (guess + n / guess) / 2;
		count++; 
	}
	return guess;
} 
int main() {
	int n;
	printf("请输入n的值\n");
	scanf("%d", &n);
	printf("the square of n is %f\n", sqrt(n));
	printf("the guess time is %d\n", count);
}
