#include<stdio.h>

void reverseString(char array[]) {
	int i=0, j=0, lengthi;
	char reverseArray[10];
	while (array[i]!='\0') {
		i++;
	}
	lengthi = i-1;
	while (lengthi>=0) {
		reverseArray[j] = array[lengthi];
		lengthi--;
		j++;
	}
	reverseArray[j]='\0';
	printf("%s\n", reverseArray);
}

void reverseString2(char *array) {
	int i, j=0;
	char temp;
	for (i=0; array[i]!='\0'; i++) {
	}
	i=i-1;
	for (j=0; j<i; i--, j++) {
		temp = array[i];
		array[i]=array[j];
		array[j]=temp;
	}
	printf("%s", array);
}

int main() {
	
	char array[10];
	//char array[]="reversework"; 
	//char *array="reversnotwook";
	//char *array;"notwork";
	//scanf("%s", array);
	gets(array);
	reverseString(array);
	reverseString2(array);
	return 0;
} 

