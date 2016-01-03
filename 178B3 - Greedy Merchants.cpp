/**
	CodeForces 178B3 - Greedy Merchants
	by Rico Tiongson
	Submitted: December 4, 2013
	Accepted 280ms GNU C++
	O(|V| + E + nlogn) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#define MX 100001

using namespace std;


int n, m;
vector<int> adj[MX];

int e1[MX], e2[MX];
bool bridge[MX];

namespace Tarjan {
	
	int id[MX], low[MX], ID;
	
	int other( int node, int g ){
		if( node == e1[g] ) return e2[g];
		return e1[g];
	}
	
	void dfs( int par, int u ){
		id[u] = low[u] = ID++;
		for( int i=0, I=adj[u].size(); i<I; ++i ){
			int E = adj[u][i];
			int v = other( u, E );
			if( id[v] == -1 ){
				dfs(u, v);
				low[u] = min( low[u], low[v] );
				if( low[v] == id[v] ){
					bridge[E] = true;
				}
			}
			else if( par != v ){
				low[u] = min( low[u], id[v] );
			}
		}
	}	
	
	void AssignBridges(){
		ID = 0;
		memset( id, -1, sizeof id );
		memset( low, -1, sizeof low );
		for( int i=1; i<=n; ++i ){
			if( id[i] == -1 ) dfs(i, i);
		}
	}
	
}

namespace Pseudo {
	
	int f[MX];
	int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }
	
	void Merge(){
		for( int i=1; i<=n; ++i ){
			f[i] = i;
			adj[i].clear();
		}
		for( int i=0; i<m; ++i ){
			if( !bridge[i] ){
				int a = find( e1[i] );
				int b = find( e2[i] );
				if( a != b ) f[a] = b;
			}
		}
		for( int i=0; i<m; ++i ){
			if( bridge[i] ){
				int a = find( e1[i] );
				int b = find( e2[i] );
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
	}
	
	int stack[MX], trace;
	int depth[MX], size[MX];
	int parent[MX][19];
	
	void dfs( int u ){
		stack[trace] = u;
		depth[u] = trace;
		int i, I;
		for( i=0, I=1; trace-I >= 0; ++i, I<<=1 ){
			parent[u][i] = stack[trace-I];
		}
		size[u] = i;
		++trace;
		for( i=0, I=adj[u].size(); i<I; ++i ){
			int v = adj[u][i];
			if( depth[v] == -1 ){
				dfs(v);
			}
		}
		--trace;
	}
	
	void AssignDepth(){
		for( int i=1; i<=n; ++i ) depth[i] = -1;
		for( int i=1; i<=n; ++i ){
			int node = find(i);
			if( depth[node] == -1 ){
				trace = 0;
				dfs(node);
			}
		}
	}
	
	int LCA( int a, int b ){
		a = find(a);
		b = find(b);
		if( a == b ) return 0;
		int ans = abs( depth[a] - depth[b] );
		int mn = min( depth[a], depth[b] );
		int i, I;
		if( depth[a] > depth[b] ){
			for( i=size[a]-1, I=(1<<i); i>=0 && depth[a] != depth[b]; --i, I>>=1 ){
				if( depth[a] - I >= depth[b] ){
					a = parent[a][i];
				}
			}
		}
		if( depth[a] < depth[b] ){
			for( i=size[b]-1, I=(1<<i); i>=0 && depth[a] != depth[b]; --i, I>>=1 ){
				if( depth[b] - I >= depth[a] ){
					b = parent[b][i];
				}
			}
		}
		if( a != b ){
			for( i=size[a]-1, I=(1<<i); i>=0 && a != b; --i, I>>=1 ){
				if( parent[a][i] != parent[b][i] && parent[a][i+1] == parent[b][i+1] ){
					a = parent[a][i];
					b = parent[b][i];
				}
			}
			if( a != b ){
				a = parent[a][0];
				b = parent[b][0];
			}
		}
		// cout << mn << " " << depth[a] << endl;
		return ans + 2*(mn-depth[a]);
	}
	
}



int main(){
	scanf( "%d %d", &n, &m );
	for( int i=0; i<m; ++i ){
		scanf( "%d %d", e1 + i, e2 + i );
		adj[e1[i]].push_back(i);
		adj[e2[i]].push_back(i);
	}
	Tarjan::AssignBridges();
	Pseudo::Merge();
	Pseudo::AssignDepth();
	int a, b, k;
	scanf( "%d", &k );
	while( k-- > 0 ){
		scanf( "%d %d", &a, &b );
		printf( "%d\n", Pseudo::LCA(a, b) );
	}
}
