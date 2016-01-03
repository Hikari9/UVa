/**
	UVa 10921 - Find the Telephone
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<cstdio>
const char *a = "22233344455566677778889999";
char c[35], *p;
int main(){
	while( gets(c) ){
		for( p=c; *p; ++p ){
			if( *p>'@' ) putchar( a[*p-'A'] );
			else putchar(*p);
		}
		putchar('\n');
	}
}
