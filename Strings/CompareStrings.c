#include<stdio.h>

void isEqual(char array[], char array2[]) {
	int i,j;
	for (i=0, j=0; array[i]!='\0' && array2[j]!='\0'; i++, j++) {
		if (array[i]!=array2[j]) {
			break;
		}
	}
	if (array[i]==array2[j]) printf("Equal");
	else if (array[i]<array2[j]) printf("Smaller");
	else printf("Bigger");
}

int main() {
	
	char array[25];
	char array2[25];
	gets(array);
	gets(array2);
	isEqual(array, array2);
	return 0;
}
