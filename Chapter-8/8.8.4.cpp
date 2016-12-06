#include <stdio.h>
#include "math.h"
#define False 0
#define True 1
int identity_matrix( int *matrix, int size ) {
	//检查矩阵是否为正方形 
	if ( sqrt(size) != size / sqrt(size) ) {
		return False;
	} 
	
	int Row = sqrt(size);
	for ( int i = 0; i < Row; i++ ) {
		if ( *(matrix + i * Row + i) == 0 ) {
			return False;
		}
	}
	for ( int i = 0; i < Row; i++) {
		for ( int j = 0; j < Row; j++) {
			if ( i == j ) {
				continue;
			} else if ( *(matrix + i * Row + j) != 0 ) {
				return False;
			}
		}
	}
	return True;
}
int main() {
	int matrix[3][4] = {
		{
			1, 0, 0, 0
		},
		{
			0, 1, 0, 0
		},
		{
			0, 0, 1, 0 
		}
	};
	float size = 12;
	if ( identity_matrix(*matrix, size) ) {
		printf("yes");
	}
	else {
		printf("no");
	}
}
