/**
	UVa 12114 - Bachelor Arithmetic
	by Rico Tiongson
	Submitted: August 3, 2013
	Accepted 0.015s C++
	O(1) time
*/
#include<cstdio>
using namespace std;
int tc;
long long b, s;
int main(){
	while( true ){
		scanf( "%lld %lld\n", &b, &s );
		if( !b && !s ) return 0;
		printf( "Case %d: :-", ++tc );
		if( b==1 ) putchar( '\\' );
		else if( b<=s ) putchar( '|' );
		else if( b*(s-1) < s*(b-1) ) putchar( '(' );
		else putchar( ')' );
		putchar( '\n' );
	}
}
