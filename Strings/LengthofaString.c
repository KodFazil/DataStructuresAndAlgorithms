#include<stdio.h>

int main() {
	
	char array[50];
	gets(array);
	//scanf("%s", array);
	printf("%s\n", array);
	int i=0;
	while (array[i]!='\0') {
		i++;
	}
	printf("Length of a string: %d", i);
	
	return 0;
}
