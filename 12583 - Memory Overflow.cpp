/**
	UVa 12583 - Memory Overflow
	by Rico Tiongson
	Submitted: August 21, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int t, tc, n, k, i, c;
char b[1005];
map<char,int> m;
int main(){
	scanf( "%d", &t );
	while( tc<t ){
		scanf( "%d %d", &n, &k );
		memset( b, -1, k );
		scanf( "%s", b + k );
		c = 0;
		m.clear();
		m[-1] = k;
		for( i=k; b[i]; ++i ){
			if( m[b[i]]>0 ) ++c;
			--m[b[i-k]];
			++m[b[i]];
		}
		printf( "Case %d: %d\n", ++tc, c );
	}
}
