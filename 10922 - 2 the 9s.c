/**
	UVa 10922 - 2 the 9s
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.025s ANSI C
	O(log(9)n) time
*/
#include<stdio.h>
int dig, x;
char buf[1024], *p, deg;
int main(){
	gets(buf);
	while( buf[1] || buf[0]!='0' ){
		printf("%s is ",buf);
		deg = '1';
		dig = 0;
		for( p=buf; *p; ++p ){
			dig += *p-'0';
		}
		if( dig%9 ) puts("not a multiple of 9.");
		else{
			while( dig!=9 ){
				x = 0;
				++deg;
				while( dig ){
					x += dig%10;
					dig/=10;
				}
				dig = x;
			}
			printf("a multiple of 9 and has 9-degree %c.\n",deg);
		}
		gets(buf);
	}
}
