#include<stdio.h>

void deblank(char string[]) {
	int flag[100] = {0};	//����ַ�����������Ԫ�أ�string[i]Ϊ�ո���flag[i]Ϊ1 
	
	//���жϵ�һ�����Ƿ�Ϊ�ո� 
	if (string[0] != '\0' && string[0] == ' ') {
		flag[0] = 1;
	}
	int i = 1;
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			flag[i] = 1;
		}
		//���ǰ������Ԫ�ؾ�Ϊ�ո���������±�i + 1��ǰ�ƣ����ǵ�string[i] 
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
	printf("�������ַ�����");
	while ((string[i] = getchar()) != '\n') {
		i++;
	}
	string[i] = '\0';
	
	printf("\nԴ�ַ�����%s\n", string);
	deblank(string);
	printf("\nȥ������ո��%s\n", string);
}
