#include<stdio.h>
#include<string.h>
int scan(char *line) {
	int counter = 0;
	char *olds = line;		//指向下一个非the字符 
	while ( (olds = strstr(olds, "the")) !=  NULL) {
		counter++;
		olds += 3; 
	}
	return counter;
}
int main() {
    char line[50] = "the old, the young, the lady!";
    printf("%d", scan(line));
}

