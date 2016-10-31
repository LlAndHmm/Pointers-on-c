#include<stdio.h>
#define MAX_NUM 100

void copy_n(char dst[], char src[], int n) {
	int src_lenth = 0;
	int count = 0;
	//求出源字符串长度 
	while (src[count] != '\0') {
		src_lenth++;
		count++;
	}
	// 源字符串大于n， dst数组将不是NUL结尾 
	if (n <= src_lenth) {
		for (int i = 0; i < n; i++) {
			dst[i] = src[i];
		}
	}
	//源字符串小于n, dst数组用NUL填满至下标n - 1所指元素 
	else {
		int remain_lenth = n - src_lenth;
		for (int i = 0; i < src_lenth; i++) {
			dst[i] = src[i];
		} 
		for (int i = src_lenth; i < remain_lenth; i++) {
			dst[i] = '\0';
		}
	}
}
int main() {
	char src[MAX_NUM];
	char dst[MAX_NUM];
	int n; 
	printf("请输入字符串:\n");
	scanf("%s", src);
	printf("请输入n的值:\n");
	scanf("%d", &n);
	copy_n(dst, src ,n);
	printf("复制的前n个字符:%s\n", dst);
	
}
