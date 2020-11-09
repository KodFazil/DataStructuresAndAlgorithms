#include<stdio.h>

char * reverseString(char array[]) {
	static char arrayB[10];
	int i=0, j=0;
	while (array[i]!='\0') {
		i++;
	}
	i=i-1;
	while (i>=0) {
		arrayB[j] = array[i];
		i--;
		j++;
	}
	arrayB[j]='\0';
	return arrayB;
}

int compare(char array[], char array2[]) {
	int i,j;
	for (i=0, j=0; array[i]!='\0' && array2[j]!='\0'; i++, j++) {
		if (array[i]!=array2[j]) {
			return 0;
		}
	}
	if (array[i]==array2[j]) return 1;
}

void isPalindrome(char array[]) {
	char *arrayPal = reverseString(array);
	if (compare(array, arrayPal)) {
		printf("String is palindrome");
	}
	else {
		printf("It is not palindrome");
	}
}

void isPalindrome2(char array[]) {
	int i=0, j=0;
	while (array[j]!='\0') {
		j++;
	}
	j=j-1;
	while (i<j && array[i]==array[j]) {
		i++;
		j--;
	}
	if (i==j) {
		printf("String is palindrome");
	} else {
		printf("It is not palindrome");
	}
	
}

int main() {
	char array[50];
	gets(array);
	printf("First method:\n");
	isPalindrome(array);
	printf("\nSecond method:\n");
	isPalindrome2(array);
	return 0;
}
