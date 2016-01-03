/**
	UVa 318 - Domino Effect
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.019s C++
	O(nlogn) Dijkstra + O(n^2) time
*/
#include<iostream>
#include<queue>
#include<vector>
#define INF 2000000000
using namespace std;
typedef pair<int, int> edge;

int n, m, tc, a, b, c;
double ans;
int path[505];
vector<edge> adj[505];

void Dijkstra(){
	for( int i=2; i<=n; ++i ) path[i] = INF;
	path[1] = 0;
	priority_queue<edge> pq;
	pq.push( edge(1, 0) );
	while( !pq.empty() ){
		int u = pq.top().first;
		int W = pq.top().second;
		pq.pop();
		if( path[u] != W ) continue;
		for( int i=0; i<adj[u].size(); ++i ){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if( path[v] > W + w ){
				path[v] = W + w;
				pq.push( edge(v, path[v]) );
			}
		}
	}
}

void GetLastDomino(){
	a = 1;
	b = -1;
	ans = 0.0;
	for( int i=1; i<=n; ++i ){
		if( path[i] > ans && path[i] != INF ){
			ans = path[i];
			a = i;
		}
	}
	for( int u=1; u<=n; ++u ){
		for( int j=0; j<adj[u].size(); ++j ){
			int v = adj[u][j].first;
			int w = adj[u][j].second;
			int x = path[u]; if( x==INF ) continue;
			int y = path[v]; if( y==INF ) continue;
			if( x < y ) swap(x, y);
			double last = x + (w - (x - y)) / 2.0;
			if( last > ans ){
				a = min( u, v );
				b = max( u, v );
				ans = last;
			}
		}
	}
}

int main(){
	cout.precision(1);
	cout << fixed;
	while( cin >> n >> m, n||m ){
		for( int i=1; i<=n; ++i ) adj[i].clear();
		for( int i=0; i<m; ++i ){
			cin >> a >> b >> c;
			adj[a].push_back( edge(b,c) );
			adj[b].push_back( edge(a,c) );
		}
		Dijkstra();
		GetLastDomino();
		cout << "System #" << ++tc << endl;
		cout << "The last domino falls after " << ans << " seconds,";
		if( b == -1 ) cout << " at key domino " << a << ".\n";
		else cout << " between key dominoes " << a << " and " << b << ".\n";
		cout << endl;
	}
}
