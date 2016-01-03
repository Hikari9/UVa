/**
	UVa 524 - Prime Ring Problem
	by Rico Tiongson
	Submitted: August 28, 2013
	Accepted 0.282s C++
	O(n!logn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[20], tc;
bool isPrime[36];
bool adj[20][20], v[20];
void dfs( int x, int i ){
	if( v[x] ) return;
	a[i] = x;
	if( i==n ){
		if( !isPrime[x+a[1]] ) return;
		putchar('1');
		for( i=2; i<=n; ++i ){
			printf(" %d",a[i]);
		}
		putchar('\n');
		return;
	}
	
	v[x] = true;
	for( int j=2; j<=n; ++j ){
		if( adj[x][j] ){
			dfs(j,i+1);
		}
	}
	v[x] = false;
}
int main(){
	memset( isPrime, 1, sizeof( isPrime ) );
	isPrime[0] = isPrime[1] = false;
	for( int i=2; i<36; ++i ){
		if( isPrime[i] ){
			for( int j=i*2; j<36; j+=i ){
				isPrime[j] = false;
			}
		}
	}
	for( int i=1; i<17; ++i ){
		for( int j=1; j<17; ++j ){
			adj[i][j] = adj[j][i] = ( isPrime[i+j] ) ;
		}
	}
	while( scanf("%d",&n)==1 ){
		if(tc)putchar('\n');
		printf( "Case %d:\n", ++tc );
		memset( v, 0, sizeof v );
		// v[1] = true;
		dfs(1,1);
	}
}
