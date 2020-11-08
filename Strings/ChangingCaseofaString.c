#include<stdio.h>

void uppertoLower(char array[]) {
	int i;
	for (i=0; array[i]!='\0'; i++) {
		array[i] += 32;
	}
}

void lowertoUpper(char array[]) {
	int i=0;
	while (array[i]!='\0') {
		array[i] -= 32;
		i++;
	}
}

void toggleCases(char array[]) {
	int i=0;
	while (array[i]!=0) {
		if (array[i] >= 65 && array[i]<='Z') {
			array[i] += 32;
		}
		else if (array[i]>='a' && array[i] <=122) {
			array[i] -= 32;
		}
		i++;
	}
}

int main() {
	
	char array[50]="HELLO";
	char array2[50]="hello";
	char array3[50]="hElLo";
	
	uppertoLower(array);
	lowertoUpper(array2);
	toggleCases(array3);
	
	printf("%s\n", array);
	printf("%s\n", array2);
	printf("%s", array3);
	
	return 0;
}
