#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max) {
	int num = 0;
	int ch;
	//取得列标号，如果所读取的数小于0则停止 
	while (num < max && scanf("%d",&columns[num]) == 1
		&& columns[num] >= 0)
	{
		num++;
	}
	
	//确认已经读取的标号为偶数个，因为它们是以成对的形式出现的 
	if (num % 2 != 0) {
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}
	//清空缓冲区  
	while((ch = getchar()) != '\n' && ch != EOF);
	return num;
}

void rearrange(char *output, char const *input,
	int n_columns, int const columns[])
{
	int col;		//columns数组的下标 
	int output_col;	//输出列计数器
	int len;		//输出行的长度 
	
	len = strlen(input);
	output_col = 0;
	 
	//处理每对列标号
	for (col = 0; col < n_columns; col = col + 2) {
		int nchars = columns[col + 1] - columns[col] + 1;
		
		//如果输入行结束或输出行数组已满，就结束任务
		if (columns[col] >= len ||
			output_col == MAX_INPUT - 1) 
		{
			break;
		} 
		
		//如果输出行数据空间不够，只复制可以容纳的部分 
		if (output_col + nchars > MAX_INPUT - 1) {
			nchars = MAX_INPUT - output_col - 1;
		} 
		//复制相关数据
		//char *strncpy(char *dest, const char *src, int n)
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars; 
	} 
	output[output_col] = '\0';
} 
int main() {
	int n_columns;
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];
	
	n_columns = read_column_numbers(columns, MAX_COLS);
	
	//读取，处理和打印剩余的输入行
	
	while(gets(input) != NULL) {
		printf("Original input:%s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rearranged line:%s\n", output);
	} 
	return EXIT_SUCCESS; 
}

