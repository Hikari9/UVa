/**
	UVa 10199 - Tourist Guide
	by Rico Tiongson
	Submitted: October 26, 2013
	Accepted 0.029s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#define MX 101
using namespace std;

int n, m, tc;
int low[MX], id[MX], ID;
bool ap[MX];
vector<int> adj[MX];

map<string, int> M;
string S[MX];

void dfs( int u, int v ){
	id[v] = low[v] = ID++;
	int child = 0;
	for( int i=0; i<adj[v].size(); ++i ){
		int w = adj[v][i];
		if( id[w] == -1 ){
			dfs(v, w);
			child++;
			low[v] = min( low[v], low[w] );
			if( u != v && id[v] <= low[w] )
				ap[v] = true;
		}
		else if( w != u )
			low[v] = min( low[v], id[w] );
	}
	if( u == v && child > 1 )
		ap[v] = true;
}

void Tarjan(){
	memset( low, -1, sizeof low );
	memset( id, -1, sizeof id );
	ID = 0;
	memset( ap, 0, sizeof ap );
	for( int i=0; i<n; ++i ){
		if( id[i] == -1 ){
			// cout << i << endl;
			dfs(i, i);
		}
	}
}

int main(){
	string s, t;
	bool first = true;
	while( cin >> n, n ){
		if( !first ) cout << endl;
		else first = false;
		M.clear();
		for( int i=0; i<n; ++i ){
			cin >> S[i];
			M[S[i]] = i;
			adj[i].clear();
		}
		cin >> m;
		while(m--){
			cin >> s >> t;
			int a = M[s];
			int b = M[t];
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// for( int i=0; i<n; ++i ){
			// sort( adj[i].begin(), adj[i].end() );
			// adj[i].erase( unique( adj[i].begin(), adj[i].end() ), adj[i].end() );
		// }
		Tarjan();
		cout << "City map #" << ++tc << ": ";
		set<string> ans;
		for( int i=0; i<n; ++i ){
			// cout << ap[i] << " ";
			if( ap[i] ){
				ans.insert( S[i] );
			}
		}
		cout << ans.size() << " camera(s) found" << endl;
		for( set<string>::iterator it = ans.begin(); it != ans.end(); ++it ){
			cout << *it << endl;
		}
	}
}
