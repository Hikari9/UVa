/**
	UVa 11690 - Money Matters
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.149s C++
	O(nlogn) time
*/
#include<cstdio>
using namespace std;
int f[10001], o[10001], mo[10001];
int find( int x ){ return f[x]==x ? x : f[x]=find(f[x]); }
int t, n, m, x, y, i;
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d", &n, &m );
		for( i=0; i<n; ++i ){
			scanf( "%d", o+i );
			f[i] = i;
			mo[i] = 0;
		}
		while( m-- ){
			scanf( "%d %d", &x, &y );
			f[find(x)] = find(y);
		}
		for( i=0; i<n; ++i ){
			mo[find(i)] += o[i];
		}
		for( i=0; i<n; ++i ){
			if( mo[i]!=0 ){
				printf( "IM" );
				break;
			}
		}
		puts( "POSSIBLE" );
	}
}
