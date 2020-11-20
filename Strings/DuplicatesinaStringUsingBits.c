#include<stdio.h>

void dupsUsingBits(char array[]) {
	long int h = 0, x = 0;
	int i;
	for (i=0; array[i]!='\0'; i++) {
		x = 1;
		x = x << array[i] - 97;
		if ( (x & h) > 0) {
			printf("%c duplicates\n", array[i]);
		}
		else {
			h = x | h;
		}
	}
}

int main() {
	
	char array[50];
	printf("Enter a string: ");
	scanf("%s", array);
	dupsUsingBits(array);
	return 0;
}
