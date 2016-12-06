#include<stdio.h>
char* my_strcat(char *dst, char *src, int size) {
	int dst_index = 0;
	while (*(dst + dst_index) != '\0') {
		dst_index++;
	}
	int src_index = 0;
	while (dst_index < size && *(src + src_index) != '\0') {
		*(dst + dst_index) = *(src + src_index);
		dst_index++;
		src_index++;
	}
	if (dst_index == size) {
		*(dst + size - 1) = '\0';
	}
	else {
		*(dst + dst_index) = '\0';
	}
	return dst;
}
int main() {
	char dst[10] = "hello ";
	char src[10] = "world!";
	
	printf("%s", my_strcat(dst, src, 10));
}
