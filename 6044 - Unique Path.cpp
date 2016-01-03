/**
	ACM 6044 - Unique Path
	by Rico Tiongson
	Submitted: December 6, 2013
	Accepted 0.143s C++
	O(|V|+E) time
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int t, n, m, tc;

vector<int> adj[10001];
int e1[100001], e2[100001];
bool bridge[100001];

namespace Tarjan {

	void clear(){
		for( int i=1; i<=n; ++i ) adj[i].clear();
	}

	int id[10001], low[10001], ID;
	
	int other( int u, int i ){
		if( e1[i] == u ) return e2[i];
		return e1[i];
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
		memset( id, -1, sizeof id );
		memset( low, -1, sizeof low );
		ID = 0;
		for( int i=1; i<=n; ++i ){
			if( id[i] == -1 ) dfs(i, i);
		}
	}
	
}

namespace Pseudo {

	int f[10001], count[10001];
	int find( int x ){ return f[x] == x ? x : f[x] = find( f[x] ); }
	
	int g[10001], gount[10001];
	int gind( int x ){ return g[x] == x ? x : g[x] = gind( g[x] ); }
	
	long long query(){
		for( int i=1; i<=n; ++i ){
			f[i] = i;
			g[i] = i;
			count[i] = 1;
			gount[i] = 1;
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
			// else{
				// cout << "Bridge: " << e1[i] << " " << e2[i] << endl;
			// }
		}
		// for( int i=1; i<=n; ++i ){
			// cout << i << ": " << find(i) << " = " << count[ find(i) ] << endl;
		// }
		for( int i=0; i<m; ++i ){
			if( bridge[i] ){
				int a = find( e1[i] );
				int b = find( e2[i] );
				if( count[a] == 1 && count[b] == 1 ){
					int A = gind(a);
					int B = gind(b);
					if( A != B ){
						g[A] = B;
						gount[B] += gount[A];
					}
				}
			}
		}
		long long ans = 0;
		for( int i=1; i<=n; ++i ){
			int a = gind(i);
			if( gount[a] > 1 ){
				// cout << gount[a] << endl;
				ans += (((long long)(gount[a]) * (gount[a]-1)) >> 1);
				gount[a] = 1;
			}
		}
		return ans;
	}
	
}

int main(){
	scanf( "%d", &t );
	while( t-- > 0 ){
		scanf( "%d %d", &n, &m );
		Tarjan::clear();
		for( int i=0; i<m; ++i ){
			scanf( "%d %d", e1+i, e2+i );
			adj[e1[i]].push_back(i);
			adj[e2[i]].push_back(i);
			bridge[i] = false;
		}
		Tarjan::AssignBridges();
		printf( "Case #%d: %lld\n", ++tc, Pseudo::query() );
	}
}
