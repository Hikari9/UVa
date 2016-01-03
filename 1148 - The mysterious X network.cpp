/**
	UVa 1148 - The mysterious X network
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.225s C++
	O(|V| + E) time
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> edge;

int t, n, c, nc, d, c1, c2;
unsigned path[100005];
vector<int> camarade[100005];

int bfs(){
	memset( path, -1, sizeof path );
	queue<edge> q;
	path[c1] = 0;
	q.push( edge(c1, 0) );
	while( !q.empty() ){
		int u = q.front().first;
		int w = q.front().second + 1; q.pop();
		for( int i=0; i<camarade[u].size(); ++i ){
			int v = camarade[u][i];
			if( w < path[v] ){
				if( v == c2 ) return w - 1;
				q.push( edge(v, path[v] = w) );
			}
		}
	}
	return -1;
}

int main(){
	scanf( "%d", &t );
	while(t--){
		scanf( "%d", &n );
		for( int i=0; i<n; ++i ) camarade[i].clear();
		for( int i=0; i<n; ++i ){
			scanf( "%d %d", &c, &nc );
			camarade[i].reserve( camarade[i].size() + nc );
			for( int j=0; j<nc; ++j ){
				scanf( "%d", &d );
				camarade[i].push_back(d);
			}
		}
		scanf( "%d %d", &c1, &c2 );
		printf( "%d %d %d\n", c1, c2, bfs() );
		if(t) putchar('\n');
	}
}
