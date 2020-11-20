#include<stdio.h>

void anagramUsingHash(char array1[], char array2[]) {
	int hash[26] = {0}, i;
	for (i=0; array1[i]!='\0'; i++) {
		hash[array1[i]-97]++;
	}
	for (i=0; array2[i]!='\0'; i++) {
		hash[array2[i]-97]--;
		if (hash[array2[i]-97] < 0) {
			printf("not anagram");
			break;
		}
	}
	if (array2[i]=='\0') {
		printf("Yes anagram");
	} 
}

void isAnagram(char array1[], char array2[]) {
	int i, j, count;
	for (i=0; array1[i]!='\0'; i++) {
		for (j=0; array2[j]!='\0'; j++) {
			if (array1[i]==array2[j]) {
				count++;
				break;
			}
		}
	}
	// find array2's length
	for (j=0; array2[j]!='\0'; j++) {}
	
	if (i==count && i == j) {
		printf("Yes anagram");
	} else {
		printf("Not anagram");
	}
}

int main() {
	
	char array1[50] = "decimal";
	char array2[50] = "medical";
	printf("Is first string anagram with second one?\n");
	printf("First method using hash with complexity O(n)\n");
	anagramUsingHash(array1, array2);
	printf("\nSecond method for loop inside for loop with complexity O(n^2)\n");
	isAnagram(array1, array2);
	
	return 0;
}

