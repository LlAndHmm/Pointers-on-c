#include<stdio.h>
#define True 1
#define False 0
//字符串长度 
int length(char const *string) {
	int len = 0;
	while (*(string + len) != '\0') {
		len++;
	}
	return len;
}
 

//接收起始删除位置 
int start;
//判断模式串j是否为目标串的子串
int index(char *str, char const *substr,
	 int length_str, int length_substr) 
{
	int i = 0, j = 0;
	while (i <= length_str && 
		j < length_substr)
	{
		if (*(str + i) == *(substr + j)) {
			i++;
			j++;
		}	
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == length_substr) {
		start = i - length_substr;
		return True;
	}
	else return False;
} 

int del_substr(char *str, char const *substr) {
	int length_str = length(str); 
	int length_substr = length(substr); 

	if (index(str, substr, length_str, length_substr) != 0) {
		while (start <= length_str) {
			*(str + start) = *(str + start + length_substr);
			start++;
		}
	}
	else {
		return False;
	}
}
int main() {
	char str[100] = "ABCDEFG";
	char substr[100] = "ABC";
	printf("str   : %s\n", str); 
	printf("substr: %s\n\n", substr);
	if (del_substr(str, substr)) {
		printf("del_substr() has been excuted\n\nstr: %s", str);
	}
	else {
		printf("'%s' have not found in '%s'", substr, str);
	}	
}
