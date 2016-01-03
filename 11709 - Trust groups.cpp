/**
	UVa 11709 - Trust groups
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.725s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#define MX 1005
using namespace std;

int low[MX], id[MX], SSC[MX], n, m, ID, groups;
bool in[MX];
stack<int> st;
map<string, int> name;
vector<int> adj[MX];
char last[15], first[15];

void dfs( int u ){
	id[u] = low[u] = ID++;
	in[u] = true;
	st.push(u);
	for( int i=0; i<adj[u].size(); ++i ){
		int v = adj[u][i];
		if( id[v] == -1 ){
			dfs(v);
			low[u] = min( low[u], low[v] );
		}
		else if( in[v] ){
			low[u] = min( low[u], id[v] );
		}
	}
	// check if root
	if( id[u] == low[u] ){
		int top;
		++groups;
		do{
			top = st.top(); st.pop();
			in[top] = false;
			
		} while( top != u );
	}
}

int Tarjan(){
	memset( low, -1, sizeof low );
	memset( id, -1, sizeof id );
	memset( in, 0, sizeof in );
	ID = 0;
	groups = 0;
	st = stack<int>();
	for( int i=0; i<n; ++i ){
		if( id[i] == -1 ){
			dfs(i);
		}
	}
	return groups;
}

int main(){
	while( scanf( "%d %d", &n, &m ) == 2 && ( n || m ) ){
		name.clear();
		for( int i=0; i<n; ++i ){
			scanf( "%s %s", &last, &first );
			string s1 = (string)last + " " + first;
			name[s1] = i;
			adj[i].clear();
		}
		for( int i=0; i<m; ++i ){
			scanf( "%s %s", &last, &first );
			string s1 = (string)last + " " + first;
			scanf( "%s %s", &last, &first );
			string s2 = (string)last + " " + first;
			int a = name[s1];
			int b = name[s2];
			adj[a].push_back(b);
		}
		printf( "%d\n", Tarjan() );
	}
}
