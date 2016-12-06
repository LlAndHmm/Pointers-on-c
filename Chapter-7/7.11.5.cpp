#include<stdio.h>
#include<stdarg.h>
void print_integer(int value) {
	
}
void print_float(int value) {
	
} 
void print(char* format, ...) {
	
	va_list arg;
	char ch;
	char *str;
	
	va_start(arg, format);
	
	while ((ch = *format++) != '\0') {
		if (ch != '%') {
			putchar(ch);
			continue;
		}
		
		switch(*format!='\0' ? *format++ : '\0') {
		case 'd': 
			print_integer(va_arg(arg, int));
			break;
		case 'f':
			print_integer(va_arg(arg, float));
			break;
		case 'c':
			putchar(va_arg(arg, int));
			break;	
		case 's':
			str = va_arg(arg, char*);
			while (*str != '\0') {
				putchar(*str);
				str++;
			}
			break;
		}	
	}
}

int main() {
	char value = 'a';
	char string[12] = "hello world";
	print("%c\n", value);
	print("%s", string);
}
