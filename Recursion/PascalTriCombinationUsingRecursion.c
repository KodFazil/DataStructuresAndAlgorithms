#include<stdio.h>

int pasComb(int n, int r) {
	
	if (n==r || r==0) {
		return 1;
	}
	else {
		return pasComb(n-1, r-1) + pasComb(n-1, r);
	}
}

int main() {
	
	printf("%d", pasComb(725, 3));
	return 0;
}
