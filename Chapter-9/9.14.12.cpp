#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
char alphabet[26] = {0};

int prepare_key(char *key) {
	if(strlen(key) > 26) {
		return FALSE;
	}
	char has_shown_char[26] = {0};
	int len;	//记录已经出现字母个数 
	
	for (int i = 0; *key != NULL && i < 26; i++) {
		//如果重复就跳过 
		if (strchr(has_shown_char, *key) == NULL) {
			alphabet[i] = *key;
			has_shown_char[len++] = *key++;
			continue;
		} 
		else {
			i = i - 1;
			key++;
		}
	}
	//补全字母表 
	for (int i = len; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (strchr(has_shown_char, 'A' + j) == NULL) {
				alphabet[i] = 'A' + j;
				has_shown_char[len++] = 'A' + j;
				break;
			}
		} 
	}
	return TRUE;
}
void encrypt(char *data, char const *key) {
	char encrypted_data[20] = {0};
	int i;
	for (i = 0; *data != '\0'; i++) {
		
		if (*data == ' ') {
			encrypted_data[i] = ' ';
		} 
		else{
			encrypted_data[i] = alphabet[*data - 'A'];
		}
		
		data++;
	}
	printf("%s", encrypted_data);
}
int main() {
	char key[27] = "TRAILBLAZERS";
	prepare_key(key);
	printf("生成密码表：%s\n", alphabet); 
	
	
	char src_data[20] = "ATTACK AT DAWN";
	printf("元数据：%s\n", src_data); 
	
	printf("加密后数据："); 
	encrypt(src_data, key);
} 
