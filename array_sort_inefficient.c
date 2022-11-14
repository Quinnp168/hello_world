#include <stdio.h>

void sort_string(int s[], int len){
	for( int i = 0; i < len; i += 1 ){
		for( int j = 0; j < len - 1; j++ ){
		if( s[j] > s[j + 1]){
		    int t = s[j];
		    s[j] = s[j + 1];
		    s[j + 1] = t;
		}
		}
	}
}

int main(void) {
	// your code goes here
	int s[] = { 7, 4, 3 , 8, 10, 5,24,87,-32,50};
	int len = sizeof s / sizeof s[0];
	for( int i = 0; i < len; i++ ){
	    printf("%d ", s[i]);
	}
	putchar('\n');
	sort_string(s, len);
	for( int i = 0; i < len; i++ ){
	    printf("%d ", s[i]);
	}
	
	return 0;
}
