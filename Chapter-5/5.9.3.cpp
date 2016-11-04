#include<stdio.h> 
unsigned reverse(unsigned int value) {
	unsigned int answer; 
	unsigned int i;
	
	answer = 0;
	
	for(i = 1; i != 0; i <<= 1) {
		/*
		**将旧的answer左移一位，为下一位留下空间 
		**如果value的最后一位是1，answer就与1进行or操作 
		**然后将value右移至下一位 
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
