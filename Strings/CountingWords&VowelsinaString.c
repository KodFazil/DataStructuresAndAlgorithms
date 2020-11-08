#include<stdio.h>

void countVowels(char a[]) {
	int i, vowelCount=0, consonantCount=0;
	for (i=0; a[i]!='\0'; i++) {
		if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='u' || a[i]=='o' || 
	        a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='U' || a[i]=='O') {
		    	vowelCount++;
			}
		else if ((a[i]>=65 && a[i]<=97) || (a[i]>=97 && a[i]<=122)) {
			consonantCount++;
		}	
	}
	printf("vowel count: %d consonant count %d\n", vowelCount, consonantCount);
}

void countWords(char array[]) {
	int i, space=0, word=0;
	for (i=0; array[i]!='\0'; i++) {
		if (array[i]==' ' && array[i-1]!=' ') {
			space++;
		}
	}
	word = space + 1;
	printf("Number of words: %d", word);
}

int main() {
	
	char array[50];
	gets(array);
	countVowels(array);
	countWords(array);
	
	return 0;
}
