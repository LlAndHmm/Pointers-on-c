#include<stdio.h>
//解题思路：先取反再加一最后把符号位置于 
int reverse(int a) {
	int result;
	result = ~a + 1;
	printf("stop"); 
}
int main() {
	int a = 25;
	reverse(a);
}
