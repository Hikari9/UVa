/**
	UVa 719 - Glass Beads
	by Rico Tiongson
	Submitted: August 2, 2013
	Accepted 0.026s C++
	O(n) time
*/
// #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char buf[20005];
int n, i, j, off, len, cmp;
int main(){
	scanf( "%d", &n );
	while( n-- ){
		scanf( "%s", buf );
		len = strlen(buf);
		for( i=0; i<len; ++i ){
			buf[len+i] = buf[i];
		}
		for( i=0, j=1; i<len && j<len; ){
			// lex comp
			for( off=0; ; ++off ){
				if( off==len ) goto end;
				if( buf[i+off]!=buf[j+off] ){
					if( buf[i+off] < buf[j+off] ){
						// skip j offset
						j += off+1;
					}
					else{
						// skip i offset
						i += off+1;
					}
					if( i==j ) ++j; // conflict
					break;
				}
			}
		}
		end:
		if( i<j ) printf( "%d\n", i+1 );
		else printf( "%d\n", j+1 );
	}
}
