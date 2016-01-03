/**
	UVa 610 - Street Directions
	by Rico Tiongson
	Submitted: OCtober 26, 2013
	Accepted 0.245s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MX 1001
using namespace std;

int n, m;
int low[MX], id[MX], ID;
vector<int> adj[MX];
bool vis[MX][MX];

vector< pair<int, int> > bridges, nonbridges;

void dfs( int parent, int u ){
	id[u] = low[u] = ID++;
	for( int i=0; i<adj[u].size(); ++i ){
		int v = adj[u][i];
		if( id[v] == -1 ){
			dfs(u, v);
			low[u] = min( low[u], low[v] );
			if( low[v] == id[v] )
				bridges.push_back( make_pair(u, v) );
			else{
				if( !vis[u][v] ){
					vis[u][v] = vis[v][u] = true;
					nonbridges.push_back( make_pair(u, v) );
				}
			}
		}
		else if( parent != v ){
			low[u] = min( low[u], id[v] );
			if( !vis[u][v] ){
				vis[u][v] = vis[v][u] = true;
				nonbridges.push_back( make_pair(u, v) );
			}
		}
	}
}

void Tarjan(){
	memset( low, -1, sizeof low );
	memset( id, -1, sizeof id );
	memset( vis, 0, sizeof vis );
	bridges.clear();
	nonbridges.clear();
	ID = 0;
	for( int i=1; i<=n; ++i ){
		if( id[i] == -1 )
			dfs(-1, i);
	}
	// for( int i=1; i<=n; ++i ){
		// cout << i << ": " << id[i] << " " << low[i] << endl;
	// }
}

int tc;

int main(){
	while( cin >> n >> m, n || m ){
		for( int i=1; i<=n; ++i )
			adj[i].clear();
		while(m--){
			int i, j;
			cin >> i >> j;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		Tarjan();
		cout << ++tc << endl << endl;
		// vector< pair<int, int> > ans;
		for( int i=0; i<bridges.size(); ++i ){
			int a = bridges[i].first;
			int b = bridges[i].second;
			// ans.push_back( make_pair(a, b) );
			// ans.push_back( make_pair(b, a) );
			cout << a << " " << b << endl;
			cout << b << " " << a << endl;
		}
		for( int i=0; i<nonbridges.size(); ++i ){
			int a = nonbridges[i].first;
			int b = nonbridges[i].second;
			// ans.push_back( make_pair(a, b) );
			cout << a << " " << b << endl;
		}
		// sort( ans.begin(), ans.end() );
		// for( int i=0; i<ans.size(); ++i ){
			// cout << ans[i].first << " " << ans[i].second << endl;
		// }
		cout << "#" << endl;
	}
}
