/**
	UVa 12049 - Just Prune The List
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.235s C++
	O(n) time
*/
#include<cstdio>
#include<hash_map>

using namespace std;
using namespace __gnu_cxx;

hash_map<int, int> hm;

int t, n, m, a, b, c;

int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d", &n, &m );
		hm.clear();
		
		for( int i=0; i<n; ++i ){
			scanf( "%d", &a );
			++hm[a];
		}
		c = 0;
		for( int i=0; i<m; ++i ){
			scanf( "%d", &b );
			if( !hm[b] ){
				++c;
				continue;
			}
			--hm[b];
		}
		for( hash_map<int, int>::iterator it = hm.begin(); it != hm.end(); ++it ){
			c += it->second;
		}
		printf( "%d\n", c );
	}
}