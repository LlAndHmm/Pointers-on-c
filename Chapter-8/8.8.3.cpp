#include<stdio.h>
#define Row 3
#define False 0
#define True 1
bool identity_matrix( int (*matrix)[3] ) {
	for ( int i = 0; i < Row; i++ ) {
		if ( matrix[i][i] == 0 ) {
			return False;
		}
	}
	for ( int i = 0; i < Row; i++) {
		for ( int j = 0; j < 3; j++) {
			if ( i == j ) {
				continue;
			} else if ( matrix[i][j] != 0 ) {
				return False;
			}
		}
	}
	return True;
}
int main() {
	int matrix[Row][3] = {
		{
			1, 0, 0
		},
		{
			0, 1, 0
		},
		{
			0, 0, 1 
		}
	};
	if ( identity_matrix(matrix) ) {
		printf("yes");
	}
	else {
		printf("no");
	}
}
