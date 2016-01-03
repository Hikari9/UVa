/**
	UVa 11770 - Lighting Away
	by Rico Tiongson
	Submitted: September 19, 2013
	Accepted 0.102s C++
	O(V+|E|) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define MX 10005
using namespace std;
int low[MX], id[MX], ID, SSC[MX], ID2, top;
bool inStack[MX], side_effect[MX];
stack<int> S;
int t, tc, n, m, i, a, b;
vector<int> adj[MX];

void dfs( int v ){
	id[v] = low[v] = ID++;
	inStack[v] = true;
	S.push(v);
	for( int j=0, w; j<adj[v].size(); ++j ){
		w = adj[v][j];
		if( id[w]==-1 ){
			dfs(w);
			low[v] = min( low[v], low[w] );
		}
		else if( inStack[w] ){
			low[v] = min( low[v], id[w] );
		}
	}
	if( id[v]==low[v] ){
		do{
			top = S.top(); S.pop();
			inStack[top] = false;
			SSC[top] = ID2;
		} while( top!=v );
		++ID2;
	}
}

int tarjan(){
	memset( low, -1, sizeof low );
	memset( id, -1, sizeof id );
	memset( inStack, 0, sizeof inStack );
	// memset( SSC, -1, sizeof SSC );
	ID = ID2 = 0;
	S = stack<int>();
	for( i=1; i<=n; ++i ){
		if( id[i]==-1 ) dfs(i);
	}
	int j, w;
	memset( side_effect, 0, sizeof side_effect );
	for( i=1; i<=n; ++i ){
		for( j=0; j<adj[i].size(); ++j ){
			w = adj[i][j];
			if( SSC[i]==SSC[w] ) continue;
			side_effect[ SSC[w] ] = true;
		}
	}
	// cout << ID2 << endl;
	j = 0;
	for( i=0; i<ID2; ++i ){
		if( !side_effect[i] ) ++j;
	}
	return j;
}

int main(){
	scanf( "%d", &t );
	while( tc<t ){
		scanf( "%d %d", &n, &m );
		for( i=1; i<=n; ++i ) adj[i].clear();
		while(m--){
			scanf( "%d %d", &a, &b );
			adj[a].push_back(b);
		}
		printf( "Case %d: %d\n", ++tc, tarjan() );
	}
}
