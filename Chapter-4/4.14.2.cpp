#include<stdio.h>
bool check(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if ((n % i) == 0) {
			count++;
		}
	}
	if (count > 2) {
		return false;
	}
	else {
		return true;
	}
}
int main() {
	for (int i = 1; i <= 100 ; i++) {
		if(check(i)) {
			printf("%d ", i);
		}
	}
} 
