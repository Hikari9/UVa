/**
	UVa 11572 - Unique Snowflakes
	by Rico Tiongson
	Submitted: September 1, 2013
	Accepted 0.212s C++
	O(n) time
*/
#include<cstdio>
#include<hash_map>
#include<algorithm>
using namespace std;
using namespace __gnu_cxx;
hash_map<int,int> m;
int t, n, x, i, u, mx;
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d", &n );
		m.clear();
		mx = u = 0;
		for( i=1; i<=n; ++i ){
			scanf( "%d", &x );
			int& r = m[x];
			if( r>u ){
				mx = max(mx,i-u-1);
				u = r;
			}
			r = i;
		}
		mx = max(mx,n-u);
		printf( "%d\n", mx );
	}
}
