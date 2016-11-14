#include<stdio.h>

int store_bit_field(int original_value,
	int value_to_store,
	unsigned starting_bit, unsigned ending_bit)
{
	//´´½¨ÑÚÂë 
	unsigned mask = ~0;
	mask >>= 32 - ( starting_bit - ending_bit + 1 );
	mask <<= ending_bit;
	
	original_value = original_value & ~mask;
	value_to_store = value_to_store << ending_bit;
	value_to_store = value_to_store & mask;
	value_to_store = value_to_store | original_value;
	
	return value_to_store;	
}
int main() {
	printf("%x", store_bit_field(0xffff, 0x123, 15, 4));
} 
