#include<stdio.h> 
int main() {
	int x = 3, y = 2, z = 4;
	int m1[3][2] = {{2, -6},{3, 5},{1, -1}};
	int m2[2][4] = {{4, -2, -4, -5}, {-7, -3, 6, 7}};
	int r[3][4] = {0};
	
	int sum = 0;
	for ( int i = 0; i < x; i++ ) {
		for ( int j = 0; j < z; j++) {
			for (int k = 0; k < y; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			r[i][j] = sum;
			sum = 0;
		}
	}
	
	for ( int i = 0; i < x; i++ ) {
		for ( int j = 0; j < z; j++) {
			printf("%5d", r[i][j]);
		}
		printf("\n");
	}
}

