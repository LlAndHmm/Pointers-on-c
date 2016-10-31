#include<stdio.h>

void deblank(char string[]) {
	int flag[100] = {0};	//标记字符串数组所有元素，string[i]为空格，则flag[i]为1 
	
	//先判断第一个数是否为空格 
	if (string[0] != '\0' && string[0] == ' ') {
		flag[0] = 1;
	}
	int i = 1;
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			flag[i] = 1;
		}
		//如果前后两个元素均为空格，则数组从下标i + 1处前移，覆盖掉string[i] 
		if (flag[i] == 1 && flag[i - 1] == 1) {
			int count = i;
			while (string[count + 1] != '\0') {
				string[count] = string[count + 1];
				count++;
			}
			string[count] = '\0';
			flag[i] = 0;
		} 
		else {
			i++;
		}	
	}
}
int main() {
	char string[100];
	
	int i = 0;
	printf("请输入字符串：");
	while ((string[i] = getchar()) != '\n') {
		i++;
	}
	string[i] = '\0';
	
	printf("\n源字符串：%s\n", string);
	deblank(string);
	printf("\n去除多余空格后：%s\n", string);
}
