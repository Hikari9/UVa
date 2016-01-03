/**
	UVa 865 - Substitution Cypher
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int t;
char a[70], b[70];
map<char, char> cipher;
int main(){
	scanf( "%d", &t );
	gets(a);
	gets(a);
	while(t--){
		gets(a);
		gets(b);
		puts(b);
		puts(a);
		cipher.clear();
		for( int i=0; a[i]; ++i ) cipher[a[i]] = b[i];
		while( gets(a) && a[0] ){
			for( int i=0; a[i]; ++i ){
				if( cipher.count( a[i] ) )
					putchar( cipher[a[i]] );
				else
					putchar( a[i] );
			}
			putchar( '\n' );
		}
		if(t) putchar( '\n' );
	}
	
}
