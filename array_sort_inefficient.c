#include <stdio.h>

void sort_string(int s[], int len){
	for( int i = 0; i < len; i += 1 ){
		int s1 = s[0];
		int s2 = s[1];
		if( s[0] > s[1]){
			s[0] = s2;
			s[1] = s1;
		}
		if( s[1] > s[2]){
			s2 = s[1];
			int s3 = s[2];
			s[1]= s3;
			s[2] = s2;
		}
	}
}

int main(void) {
	// your code goes here
	int s[] = { 7, 4, 3 };
	printf("%d %d %d\n", s[0], s[1], s[2]);
	sort_string(s, 3);
	printf("%d %d %d\n", s[0], s[1], s[2]);
	return 0;
}
