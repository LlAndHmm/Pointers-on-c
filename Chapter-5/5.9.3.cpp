#include<stdio.h>
//����˼·����ȡ���ټ�һ���ѷ���λ���� 
int reverse(int a) {
	int result;
	result = ~a + 1;
	printf("stop"); 
}
int main() {
	int a = 25;
	reverse(a);
}
