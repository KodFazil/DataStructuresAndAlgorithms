#include<stdio.h>

int nestFunct(int n) {
	
	if(n > 100) {
		return n - 10;
	}
	else {
		return nestFunct(nestFunct(n + 11));
	}
}

int main() {
	
	printf("%d", nestFunct(95));
	return 0;
}
