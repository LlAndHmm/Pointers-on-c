#include<stdio.h>
int gcd(int M, int N) {
	if (M > 0 && N > 0) {
		if (M % N == 0) {
			return N;
		}
		else {
			return gcd(N, M % N);
		}
	}
	else {
		return 0;
	} 
}
int main() {
	printf("65和26的公约数:%d\n",gcd(65, 26));
	printf("26和65的公约数:%d\n",gcd(26, 65));
	printf("当M小于零时函数返回值：%d", gcd(-1, 2));
} 
