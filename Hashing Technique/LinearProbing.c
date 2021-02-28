#include<stdio.h>

// size is 10
int hash(int key) {
	return key%10;
}

int probe(int harr[], int key) {
	int index = hash(key), i = 0;
	while (harr[(index+i)%10] != 0) 
		i++;
	return (index+i)%10;	
}

void insert(int h[], int key) {
	int index = hash(key);
	if (h[index] != 0)
		index = probe(h, key);
	h[index] = key;	
}

int search(int h[], int key) {
	int index = hash(key), i = 0;
	while (h[(index+i)%10] != key) 
		i++;
	return (index+i)%10;
}

int main() {
	
	int hashTable[10] = {0};
	
	insert(hashTable, 7);
	insert(hashTable, 5);
	insert(hashTable, 17);
	insert(hashTable, 28);
	printf("Element you search found at index: %d\n", search(hashTable, 17));
	
	return 0;
}
