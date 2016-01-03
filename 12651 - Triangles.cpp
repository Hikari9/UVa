/**
	UVa 12651 - Triangles
	by Rico Tiongson
	Submitted: September 17, 2013
	Accepted 0.138s C++
	O(n/3) time
*/
#include<cstdio>
#include<hash_set>
using namespace std;
using namespace __gnu_cxx;
int n, i, x[100005], eq, c;
hash_set<int> hs;
int main(){
	while( scanf("%d",&n)==1 ){
		hs.clear();
		for( i=1; i<=n; ++i ){
			scanf( "%d", x+i );
			x[i] += x[i-1];
			hs.insert( x[i] );
		}
		if( x[n]%3!=0 ){
			puts("0");
			continue;
		}
		eq = x[n]/3; 
		c = 0;
		for( i=0; x[i]<eq; ++i ){
			if( hs.count( x[i]+eq ) && hs.count( x[i]+eq*2 ) ){
				++c;
			}
		}
		printf( "%d\n", c );
	}
}
