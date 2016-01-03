/**
	UVa 11838 - Come and Go
	by Rico Tiongson
	Submitted: September 18, 2013
	Accepted 0.088s C++
	O(V+|E|) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MX 2001
using namespace std;

int n, m, i;
bool adj[MX][MX];

int low[MX], id[MX], top, ID, c;
bool inStack[MX];
stack<int> S;

void dfs( int v ){
	id[v] = low[v] = ID++;
	S.push(v);
	inStack[v] = true;
	for( int w=0; w<n; ++w ){
		if( adj[v][w] ){
			if( id[w]==-1 ){
				dfs(w);
				low[v] = min( low[v], low[w] );
			}
			else if( inStack[w] ){
				low[v] = min( low[v], id[w] );
			}
		}
	}
	if( id[v]==low[v] ){
		++c;
		do{
			top = S.top(); S.pop();
			inStack[top] = false;
		} while( top!=v );
	}
}

int tarjan(){
	c = 0;
	ID = 0;
	memset( low, -1, sizeof low );
	memset( id, -1, sizeof id );
	memset( inStack, 0, sizeof inStack );
	S = stack<int>();
	for( i=0; i<n; ++i ){
		if( id[i]==-1 ) dfs(i);
	}
	// for( i=1; i<n; ++i ){
		// if( low[i]!=low[0] ) return 0;
	// }
	return (c==1);
}

int v, w, p;

int main(){
	while( scanf( "%d %d", &n, &m )==2 && (n||m) ){
		memset( adj, 0, sizeof adj );
		while(m--){
			scanf( "%d %d %d", &v, &w, &p );
			--v, --w;
			adj[v][w] = 1;
			if(p==2)
				adj[w][v] = 1;
		}
		printf( "%d\n", tarjan() );
	}
}
