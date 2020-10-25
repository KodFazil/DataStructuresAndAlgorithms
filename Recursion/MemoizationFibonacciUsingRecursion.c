#include<stdio.h>

int memoiArray[10];

int mFib(int n) {
	
	if (n==0 || n==1) {
		memoiArray[n] = n;
		return memoiArray[n];
	}
	else {
		if (memoiArray[n-1] == -1) {
			memoiArray[n-1] = mFib(n-1);
		}
		if (memoiArray[n-2] == -1) {
			memoiArray[n-2] == mFib(n-2);
		}		
		return memoiArray[n-1] + memoiArray[n-2];
	}
}

int main() {
	int i=0;
	for (i=0; i<10; i++) {
		memoiArray[i] = -1;
	}
	printf("%d", mFib(10));
}
