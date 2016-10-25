#include<stdio.h>
#define MAX_ROW 100
int main() {
	int lenth[MAX_ROW];
	char input[MAX_ROW][1000];
	int r = 0, c = 0;
	int counter = 0;	//记录输入行行数 
	 
	while (r < MAX_ROW) { 
		//若无输入表示结束
		input[r][c] = getchar();
		if (input[r][c] == '\n') {
			break;
		} else {
			lenth[r]++;
		}
		//换行符也计算在字符串长度里 
		while (input[r][c] != '\n') {
			c++;
			input[r][c] = getchar();
			lenth[r]++;
		}
		c = 0;
		r++;
		counter++; 
	}
	//排序
	int max_row = 0;
	int max_row_index = 0;
	for (int i=0; i<counter; i++) {
		if (lenth[i] > max_row) {
			max_row = lenth[i];
			max_row_index = i;
		}
	} 
	//输出
	for (int i=0; i<lenth[max_row_index]; i++) {
		printf("%c",input[max_row_index][i]);
	}
	 
}
