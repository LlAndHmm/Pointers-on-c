#include<stdio.h>
//��ָ��λ��Ϊ1 
void set_bit(char bit_array[],
	unsigned bit_number) 
{
	if (bit_number >= 0 && bit_number <= 7) {
		*(bit_array + 7 - bit_number) = '1';
	} 
	else {
		printf("��������Чλ\n"); 
	}
}
//��ָ��λ������ 
void clear_bit(char bit_array[],
	unsigned bit_number)
{
	if (bit_number >= 0 && bit_number <= 7) {
		*(bit_array + 7 - bit_number) = '0';
	} 
	else {
		printf("��������Чλ\n"); 
	}	
}
//���value��ֵ��0����ָ��λ��0����֮����Ϊ1 
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
		printf("��������Чλ\n"); 
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
		printf("��������Чλ\n"); 
	}	
}
int main() {
	char bit_array[9] = "10110101";
	printf("ԭλ����             ��%s\n\n", bit_array);
	
	set_bit(bit_array, 1);
	printf("��һλ����Ϊ1        ��%s\n\n", bit_array);
	
	clear_bit(bit_array, 5);
	printf("����λ������0        ��%s\n\n", bit_array);
	
	int value = 1;
	assign_bit(bit_array, 3, value);
	printf("��valueΪ1ʱ�ı��3λ��%s\n\n", bit_array);
	
	if(test_bit(bit_array, 4)) {
		printf("����λ����0\n\n");
	} 
	else {
		printf("����λ����\n\n");
	}  
	
} 
