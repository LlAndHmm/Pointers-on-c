#include<stdio.h>
#define MAX_NUM 100

void copy_n(char dst[], char src[], int n) {
	int src_lenth = 0;
	int count = 0;
	//���Դ�ַ������� 
	while (src[count] != '\0') {
		src_lenth++;
		count++;
	}
	// Դ�ַ�������n�� dst���齫����NUL��β 
	if (n <= src_lenth) {
		for (int i = 0; i < n; i++) {
			dst[i] = src[i];
		}
	}
	//Դ�ַ���С��n, dst������NUL�������±�n - 1��ָԪ�� 
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
	printf("�������ַ���:\n");
	scanf("%s", src);
	printf("������n��ֵ:\n");
	scanf("%d", &n);
	copy_n(dst, src ,n);
	printf("���Ƶ�ǰn���ַ�:%s\n", dst);
	
}
