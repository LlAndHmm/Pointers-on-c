#include<stdio.h>
#define MAX_ROW 100
int main() {
	int lenth[MAX_ROW];
	char input[MAX_ROW][1000];
	int r = 0, c = 0;
	int counter = 0;	//��¼���������� 
	 
	while (r < MAX_ROW) { 
		//���������ʾ����
		input[r][c] = getchar();
		if (input[r][c] == '\n') {
			break;
		} else {
			lenth[r]++;
		}
		//���з�Ҳ�������ַ��������� 
		while (input[r][c] != '\n') {
			c++;
			input[r][c] = getchar();
			lenth[r]++;
		}
		c = 0;
		r++;
		counter++; 
	}
	//����
	int max_row = 0;
	int max_row_index = 0;
	for (int i=0; i<counter; i++) {
		if (lenth[i] > max_row) {
			max_row = lenth[i];
			max_row_index = i;
		}
	} 
	//���
	for (int i=0; i<lenth[max_row_index]; i++) {
		printf("%c",input[max_row_index][i]);
	}
	 
}
