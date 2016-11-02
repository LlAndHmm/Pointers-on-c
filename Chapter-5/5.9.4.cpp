#include<stdio.h>
//将指定位置为1 
void set_bit(char bit_array[],
	unsigned bit_number) 
{
	if (bit_number >= 0 && bit_number <= 7) {
		*(bit_array + 7 - bit_number) = '1';
	} 
	else {
		printf("请输入有效位\n"); 
	}
}
//将指定位置清零 
void clear_bit(char bit_array[],
	unsigned bit_number)
{
	if (bit_number >= 0 && bit_number <= 7) {
		*(bit_array + 7 - bit_number) = '0';
	} 
	else {
		printf("请输入有效位\n"); 
	}	
}
//如果value的值是0，将指定位清0，反之设置为1 
void assign_bit(char bit_array[],
	unsigned bit_number, int value) 
{
	if (bit_number >= 0 && bit_number <= 7) {
		if (value) {
			*(bit_array + 7 - bit_number) = '1';
		}
		else {
			*(bit_array + 7 - bit_number) = '0';
		}	
	} 
	else {
		printf("请输入有效位\n"); 
	}
}
int test_bit(char bit_array[], unsigned bit_number) {
	if (bit_number >= 0 && bit_number <= 7) {
		if (*(bit_array + 7 - bit_number) == '1') {
			return 1;
		}
		else {
			return 0;
		}
	} 
	else {
		printf("请输入有效位\n"); 
	}	
}
int main() {
	char bit_array[9] = "10110101";
	printf("原位数组             ：%s\n\n", bit_array);
	
	set_bit(bit_array, 1);
	printf("第一位设置为1        ：%s\n\n", bit_array);
	
	clear_bit(bit_array, 5);
	printf("第五位设置清0        ：%s\n\n", bit_array);
	
	int value = 1;
	assign_bit(bit_array, 3, value);
	printf("当value为1时改变第3位：%s\n\n", bit_array);
	
	if(test_bit(bit_array, 4)) {
		printf("第四位不是0\n\n");
	} 
	else {
		printf("第四位是零\n\n");
	}  
	
} 
