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
	printf("65��26�Ĺ�Լ��:%d\n",gcd(65, 26));
	printf("26��65�Ĺ�Լ��:%d\n",gcd(26, 65));
	printf("��MС����ʱ��������ֵ��%d", gcd(-1, 2));
} 
