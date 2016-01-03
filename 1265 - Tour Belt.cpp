/**
	UVa 1265 - Tour Belt
	by Rico Tiongson
	Submitted: May 3, 2014
	Accepted 0.175s C++
	Modified Kruskals
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long lag;
typedef map<int, vector<int>, greater<int> > MAP;

int f[5001], c[5001];
lag ans;

int find( int x ){
	return f[x] == x ? x : f[x] = find( f[x] );
}

int t, n, m;
int x[5001], y[5001];
bool pending[5001];

vector< pair<int, int> > adj[5001];
vector<int> mod, group[5001];
MAP M;

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset( adj, 0, sizeof adj );
		for( int i=1; i<=n; ++i ){
			f[i] = i;
			c[i] = 1;
			adj[i].clear();
			group[i].clear(); group[i].push_back(i);
			pending[i] = false;
		}
		ans = 0;
		M.clear();
		for( int i=0; i<m; ++i ){
			int u, v, w;
			cin >> u >> v >> w;
			x[i] = u;
			y[i] = v;
			M[w].push_back(i);
			adj[u].push_back( make_pair(v,w) );
			adj[v].push_back( make_pair(u,w) );
		}
		for( MAP::iterator it = M.begin(); it != M.end(); ++it ){
			mod.clear();
			for( int i=0; i<it->second.size(); ++i ){
				int aa = x[it->second[i]];
				int bb = y[it->second[i]];
				int a = aa;
				int b = bb;
				a = find(a);
				b = find(b);
				if( a != b ){
					// if( c[b] < c[a] ) swap(a, b);
					f[a] = b;
					c[b] += c[a];
					group[b].insert( group[b].end(), group[a].begin(), group[a].end() );
					group[a].clear();
					mod.push_back(b);
				}
				else if( pending[b] ) mod.push_back(b);
				// end:;
			}
			for( int i=0; i<mod.size(); ++i ){
				int a = find(mod[i]);
				if( c[a] > 0 ){
					bool ok = true;
					for( int j=0; j<group[a].size(); ++j ){
						int u = group[a][j];
						for( int k=0; k<adj[u].size(); ++k ){
							int v = adj[u][k].first;
							int w = adj[u][k].second;
							if( w < it->first && find(v) == a ){
								pending[a] = true;
								// cout << it->first << " " << w << " => " << v << " " << find(v) << endl;
								ok = false;
								break;
							}
						}
						if(!ok) break;
					}
					if(ok){
						pending[a] = false;
						ans += c[a];
					}
					c[a] = -c[a];
				}
			}
			for( int i=0; i<mod.size(); ++i ){
				int a = find(mod[i]);
				if( c[a] < 0 ) c[a] = -c[a];
			}
		}
		cout << ans << endl;
	}
}
