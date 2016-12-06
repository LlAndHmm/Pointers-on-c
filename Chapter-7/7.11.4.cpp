#include<stdio.h>
#include<stdarg.h>
int max_list(int max, ...) {
	va_list var_max;
	va_start(var_max, max);
	int temp;
	if (max >= 0) {
		temp = va_arg(var_max, int);
	}
	else return 0;
	
	while(temp >= 0) {
		if (temp > max) {
			max = temp;
		}
		temp = va_arg(var_max, int);
	}
	va_end(var_max);
	return max;
} 
int main() {
	printf("%d", max_list(0, 10, 6, 8, 3, 5, 7, 12, 29, 59, -1));		//必须以一个负值结尾 
}

