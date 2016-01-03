/**
	CodeForces 231E - Cactus
	by Rico Tiongson
	Submitted: December 5, 2013
	Accepted 312ms GNU C++
	O(nlogn) time
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MX 100001
using namespace std;

vector<int> adj[MX];
int e1[MX], e2[MX];
bool bridge[MX];

int n, m;

namespace Tarjan {

	int id[MX], low[MX], ID;
	
	int other( int u, int i ){
		if( e1[i] == u ) return e2[i];
		return e1[i];
	}
	
	void dfs( int par, int u ){
		id[u] = low[u] = ID++;
		for( int i=0, I=adj[u].size(); i<I; ++i ){
			int E = adj[u][i];
			int v = other( u, adj[u][i] );
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
			if( id[i] == -1 ){
				dfs(i, i);
			}
		}
	}
	
}

namespace Pseudo {
	
	int f[MX], count[MX];
	int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }
	
	int g[MX];
	int gind( int x ){ return g[x] == x ? x : g[x] = gind( g[x] ); }
	
	void MakeNodes(){
		for( int i=1; i<=n; ++i ){
			f[i] = i;
			g[i] = i;
			count[i] = 1;
			adj[i].clear();
		}
		for( int i=0; i<m; ++i ){
			if( !bridge[i] ){
				int a = find( e1[i] );
				int b = find( e2[i] );
				if( a != b ){
					f[a] = b;
					count[b] += count[a];
				}
			}
		}
		for( int i=0; i<m; ++i ){
			if( bridge[i] ){
				int a = find( e1[i] );
				int b = find( e2[i] );
				adj[a].push_back(b);
				adj[b].push_back(a);
				a = gind(a);
				b = gind(b);
				if( a != b ) g[a] = b;
			}
		}
	}
	
	int depth[MX], stack[MX], trace;
	int parent[MX][19], size[MX];
	int value[MX], curval;
	
	void dfs( int u ){
		stack[trace] = u;
		depth[u] = trace;
		int i, I;
		for( i=0, I=1; trace-I >= 0; ++i, I<<=1 ){
			parent[u][i] = stack[trace-I];
		}
		size[u] = i;
		if( count[u] > 1 )
			curval++;
		value[u] = curval;
		++trace;
		for( i=0, I=adj[u].size(); i<I; ++i ){
			int v = adj[u][i];
			if( depth[v] == -1 ){
				dfs(v);
			}
		}
		if( count[u] > 1 )
			curval--;
		--trace;
	}
	
	void Preprocess(){
		for( int i=1; i<=n; ++i ) depth[i] = -1;
		for( int i=1; i<=n; ++i ){
			int node = find(i);
			if( depth[node] == -1 ){
				trace = 0;
				curval = 0;
				dfs(node);
			}
		}
	}
	
	bool connected( int node1, int node2 ){
		return gind(node1) == gind(node2);
	}
	
	long long modPow( int expo ){
		if( expo == 0 ) return 1;
		long long half = modPow( expo >> 1 );
		half = (half*half) % 1000000007;
		if( expo & 1 ) return (half<<1) % 1000000007;
		return half;
	}
	
	long long LCA( int a, int b ){
		a = find(a);
		b = find(b);
		if( !connected(a, b) ) return 0;
		if( a == b ) return count[a] > 1 ? 2 : 1;
		int v1 = value[a];
		int v2 = value[b];
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
		int v = value[a];
		int expo = v1 + v2 - 2*v + ( count[a] > 1 ? 1 : 0 );
		return modPow(expo);
	}
	
}

int main(){
	scanf( "%d %d", &n, &m );
	for( int i=0; i<m; ++i ){
		scanf( "%d %d", e1+i, e2+i );
		adj[e1[i]].push_back(i);
		adj[e2[i]].push_back(i);
	}
	Tarjan::AssignBridges();
	Pseudo::MakeNodes();
	Pseudo::Preprocess();
	int a, b, k;
	scanf( "%d", &k );
	while( k-- > 0 ){
		scanf( "%d %d", &a, &b );
		printf( "%I64d\n", Pseudo::LCA(a, b) );
	}
}
