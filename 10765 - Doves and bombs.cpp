/**
	UVa 10765 - Doves and bombs
	by Rico Tiongson
	Submitted: October 27, 2013
	Accepted 0.035s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define MX 10001

using namespace std;

struct node{
	int id, pigeon_value;
	node() {}
	node( int ID, int PIGEON_VALUE ): id(ID), pigeon_value(PIGEON_VALUE) {}
	bool operator < ( const node& n ) const {
		return pigeon_value < n.pigeon_value || ( pigeon_value == n.pigeon_value && id > n.id );
	}
};

vector<int> adj[MX];
int low[MX], id[MX], ID;
int pigeons[MX], nations;
int n, m, a, b;

void dfs( int par, int u ){
	id[u] = low[u] = ID++;
	pigeons[u] = 1;
	int children = 0;
	for( int i=0, I=adj[u].size(); i<I; ++i ){
		int v = adj[u][i];
		if( id[v] == -1 ){
			dfs(u, v);
			if( par == -1 ) ++children;
			low[u] = min( low[u], low[v] );
			if( id[u] <= low[v] ){
				++pigeons[u];
			}
		}
		else if( v != par ){
			low[u] = min( low[u], id[v] );
		}
	}
	if( par == -1 )
		pigeons[u] = children;
}

void Tarjan(){
	memset( id, -1, sizeof id );
	ID = 0;
	nations = -1;
	for( int i=0; i<n; ++i ){
		if( id[i] == -1 ){
			++nations;
			dfs(-1, i);
		}
	}
}

int main(){
	while( scanf( "%d %d", &n, &m ) == 2 && ( n || m ) ){
		for( int i=0; i<n; ++i ) adj[i].clear();
		while( scanf( "%d %d", &a, &b ) == 2 && a !=-1 && b != -1 ){
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		Tarjan();
		priority_queue<node> pq;
		for( int i=0; i<n; ++i ){
			pq.push( node(i, nations + pigeons[i]) );
		}
		while( m-- ){
			a = pq.top().id;
			b = pq.top().pigeon_value;
			pq.pop();
			printf( "%d %d\n", a, b );
		}
		putchar( '\n' );
	}
}
