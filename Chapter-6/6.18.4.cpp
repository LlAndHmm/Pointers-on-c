#include<stdio.h>
#define MaxNum 293000
void Eratoshenes(int* flag) {
	//将flag数组全部置为1
	for (int i = 0; i <= MaxNum; i++) {
		flag[i] = 1;
	} 
	flag[0] = flag[1] = 0;

	for (int i = 2; i <= MaxNum; i++) {

		if (flag[i] == 1) {
			for (int j = 2 * i; j <= MaxNum; j += i) {
				flag[j] = 0;
			}
		}
	}
}
int main() {
	int flag[MaxNum];
	Eratoshenes(flag);
	
	int start = 0;
	int end = 1000;
	int total = 0; 
	while (end <= MaxNum) {
		int count = 0;
		while (start++ <= end) {
			if (flag[start - 1] == 1) {
				count++;
				total++;
			}
		}
		start -= 1002;
		printf("%6d到%6d质数个数：%d\n", start, end, count);
		start += 1001;
		end += 1000;
	}	
	printf("\n总共:\n%6d到%6d质数个数：%d\n", 0, MaxNum, total);
} 
