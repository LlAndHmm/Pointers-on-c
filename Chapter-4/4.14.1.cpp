#include<stdio.h>
int count = 0;	//����guess�˼��� 
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
	printf("������n��ֵ\n");
	scanf("%d", &n);
	printf("the square of n is %f\n", sqrt(n));
	printf("the guess time is %d\n", count);
}
