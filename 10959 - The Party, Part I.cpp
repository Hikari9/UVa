/**
	UVa 10959 - The Party, Part I
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.015s C++
	O(|V| + E) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> edge;
int t, p, d, a, b;
unsigned path[1001];
vector<int> adj[1001];
void bfs(){
	memset( path, -1, sizeof path );
	path[0] = 0;
	queue<edge> q;
	q.push( edge(0, 0) );
	while( !q.empty() ){
		int u = q.front().first;
		int w = q.front().second + 1;
		q.pop();
		for( int i=0; i<adj[u].size(); ++i ){
			int v = adj[u][i];
			if( w < path[v] ){
				q.push( edge(v, path[v] = w) );
			}
		}
	}
}
int main(){
	scanf( "%d", &t );
	while( t-- ){
		scanf( "%d %d", &p, &d );
		for( int i=0; i<p; ++i ) adj[i].clear();
		for( int i=0; i<d; ++i ){
			scanf( "%d %d", &a, &b );
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bfs();
		for( int i=1; i<p; ++i ){
			printf( "%d\n", path[i] );
		}
		if(t) putchar('\n');
	}
}
