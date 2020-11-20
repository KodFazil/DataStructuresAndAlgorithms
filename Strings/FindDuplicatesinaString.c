#include<stdio.h>

void findDupsString(char string[]) {
	int i, j, count;
	for (i=0; string[i]!='\0'; i++) {
		count = 1;
		if (string[i] != -1) {
			for (j=i+1; string[j]!='\0'; j++) {
			if (string[i] == string[j]) {
				count++;
				string[j]=-1;
			}
		}
	}
		if (count > 1) {
			printf("%c appearing %d times\n", string[i], count);	
		}
	}
}

void findDupsStringHashing(char array[]) {
	int hashing[26]={0}, i;
	for (i=0; array[i]!='\0'; i++) {
		hashing[array[i]-97]++;
	}
 	for(i=0; i<26; i++) {
 		if (hashing[i] > 1) {
 			printf("%c appearing %d times\n", i+97, hashing[i]);
		 }	
	}
	printf("\nHashing Table\n");
	for(i=0; i<26; i++) {
 		printf("%d ", hashing[i]);	
	}
}


int main() {
	
	char array[50], array2[50];
	printf("Enter some string: ");
	gets(array);
	findDupsString(array);
	printf("Method using hash enter some string: ");
	gets(array2);
	findDupsStringHashing(array2);
	
	return 0;
}
