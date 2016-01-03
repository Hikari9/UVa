/**
	UVa 306 - Cipher
	by Rico Tiongson
	Submitted: August 16, 2013
	Accepted 0.049s C++
	O(nlogn) time
*/
// #include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int n, i, j, J, k;
int a[205], sa[205], p;
char letters[205], out[205];
int main(){
	scanf( "%d", &n );
	while( n ){
		for( i=1; i<=n; ++i )
			// cin >> a[i];
			scanf( "%d", a+i );
		for( i=1; i<=n; ++i ){
			sa[i] = 1;
			p = a[i];
			while( p!=i ){
				++sa[i];
				p = a[p];
			}
		}
		// puts("HELLO");
		scanf( "%d", &k );
		while( k ){
			memset( letters, ' ', sizeof letters );
			getchar();
			gets( letters+1 );
			letters[ strlen(letters) ] = ' ';
			// simulate
			for( i=1; i<=n; ++i ){
				p = i;
				for( j=0, J=k%sa[i]; j<J; ++j ){
					p = a[p];
				}
				out[p] = letters[i];
			}
			out[n+1] = '\0';
			puts( out+1 );
			scanf( "%d", &k );
		}
		putchar( '\n' );
		scanf( "%d", &n );
	}
}
