#include<stdio.h>

int validate(char *array) {
	int i;
	for (i=0; array[i]!='\0'; i++) {
		if ((!(array[i]>='A' && array[i]<=90)) && 
		    (!(array[i]>=97 && array[i]<=122)) &&
			(!(array[i]>=48 && array[i]<='9'))) {
				return 0;
			} 	
	}
	return 1;
}

int main() {
	
	char array[50];
	gets(array);
	if (validate(array)) {
		printf("This string is valid");
	}
	else {
		printf("This string is not valid");
	}
	
	return 0;
}
