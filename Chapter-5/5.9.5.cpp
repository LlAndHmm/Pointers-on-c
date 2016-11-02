#include<stdio.h>

int store_bit_field(int original_value,
	int value_to_store,
	unsigned starting_bit, unsigned ending_bit)
{
	unsigned mask = ~0;
	//´´½¨ÑÚÂë 
	mask = mask << (ending_bit - 1);
	
	original_value = orinal_value & ~mask;
	value_to_store = value_to_store << ending_bit;
	value_to_store = value_to_store & mask;
	value_to_store = value_to_store & original_value;
	
	return value_to_store;	
}
int main() {
	store_bit_field(0xffff, 0x123, 13, 9);
} 
