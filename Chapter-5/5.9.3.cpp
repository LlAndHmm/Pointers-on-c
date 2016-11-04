#include<stdio.h> 
unsigned reverse(unsigned int value) {
	unsigned int answer; 
	unsigned int i;
	
	answer = 0;
	
	for(i = 1; i != 0; i <<= 1) {
		/*
		**���ɵ�answer����һλ��Ϊ��һλ���¿ռ� 
		**���value�����һλ��1��answer����1����or���� 
		**Ȼ��value��������һλ 
		*/
		answer <<= 1;
		if (value & 1) {
			answer |= 1;
		} 
		value >>= 1;
	}
	return answer;
}
int main() {
	unsigned value = 25;
	printf("%u", reverse(value));
}
