/**
	UVa 10459 - The Tree Root
	by Rico Tiongson
	Submitted: September 19, 2013
	Accepted 0.113s C++
	O(V+|E|) time
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#define MX 5005
using namespace std;
int n, i, I, k;
int child[MX][2], parent[MX], root[MX], best, worst;
bool v[MX];
vector<int> fr[MX];

void dfs( int x ){
	int j, J, y;
	v[x] = true;
	// cout << fr[x].size() << endl;
	for( j=0, J=fr[x].size(); j<J; ++j ){
		y = fr[x][j];
		if( !v[y] ){
			dfs(y);
			child[x][1] = max( child[x][1], child[y][0]+1 );
			if( child[x][0] < child[x][1] ) swap( child[x][0], child[x][1] );
		}
	}
}

void dfs2( int x, int d ){
	int j, J, y;
	v[x] = true;
	parent[x] = d;
	for( j=0, J=fr[x].size(); j<J; ++j ){
		y = fr[x][j];
		if( !v[y] ){
			dfs2( y, max(d,( child[y][0]+1 != child[x][0] ? child[x][0] : child[x][1] ) )+1 );
		}
	}
}

int main(){
	while( scanf("%d",&n)==1 ){
		for( i=1; i<=n; ++i ){
			scanf("%d",&k);
			fr[i].resize(k);
			for( I=0; I<k; ++I ){
				scanf("%d",&fr[i][I]);
			}
		}
		
		memset( child, 0, sizeof child );
		memset( parent, 0, sizeof parent );
		memset( v, 0, sizeof v );
		// dfs dummy node 1
		dfs(1);
		memset( v, 0, sizeof v );
		dfs2(1,0);
		best = 2147483647;
		worst = 0;
		// for( i=1; i<=n; ++i ){
			// cout << child[i][0] << " " << child[0][1] << endl;
		// }
		for( i=1; i<=n; ++i ){
			root[i] = max( parent[i], max( child[i][0], child[i][1] ) );
			best = min( root[i], best );
			worst = max( root[i], worst );
		}
		// cout << best << " " << worst << endl;
		printf( "Best Roots  :" );
		for( i=1; i<=n; ++i ){
			if( root[i]==best ) printf( " %d", i );
		}
		printf( "\nWorst Roots :" );
		for( i=1; i<=n; ++i ){
			if( root[i]==worst ) printf( " %d", i );
		}
		putchar('\n');
	}
}
