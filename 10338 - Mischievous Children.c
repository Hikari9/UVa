/**
	UVa 10338 - Mischievous Children
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.025s ANSI C
	O(n) time
*/
#include<stdio.h>
#include<string.h>
unsigned long long f[21] = { 1LL, 1LL }, ans;
int i, len, n, tc=0, c[26];
char s[25];
int main(){
	for( i=2; i<21; ++i ){
		f[i] = f[i-1]*(unsigned long long)i;
	}
	scanf( "%d\n", &n );
	while( tc<n ){
		gets(s);
		len = strlen(s);
		ans = f[len];
		memset( c, 0, sizeof c );
		for( i=0; i<len; ++i ){
			++c[ s[i]-'A' ];
		}
		for( i=0; i<26; ++i ){
			if( c[i]>1 ) ans /= f[c[i]];
		}
		printf( "Data set %d: %lld\n", ++tc, ans );
	}
}
