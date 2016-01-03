/**
	UVa 10330 - Power Transmission
	by Rico Tiongson
	Submitted: July 5, 2014
	Accepted 0.059s C++
	MaxFlow
*/
#include <iostream>
#include <queue>
#include <cstring>
#define INF 2147483647
using namespace std;

int n;
int flow[250][250], prev[250];

int bfs( int src, int sink ){
	queue<int> q;
	for( int i=0; i<2*n; ++i ){
		prev[i] = -2;
	}
	q.push( src );
	prev[src] = -1;
	while( !q.empty() ){
		int u = q.front(); q.pop();
		// cout << u << " ";
		if( u == sink ){
			int cf = INF;
			for( int i=sink; prev[i] != -1; i = prev[i] ){
				cf = min( cf, flow[prev[i]][i] );
				// cout << prev[i] << " " << i << flow[prev[i]][i] << endl;
			}
			return cf;
		}
		for( int i=0; i<2*n; ++i ){
			if( prev[i] == -2 && flow[u][i] > 0 ){
				q.push(i);
				prev[i] = u;
			}
		}
	}
	return 0;
}

int maxFlow( int src, int sink ){
	int cf, tot = 0;
	while( cf = bfs(src, sink) ){
		tot += cf;
		// cout << cf << endl;
		for( int i=sink; prev[i] != -1; i=prev[i] ){
			flow[prev[i]][i] -= cf;
			flow[i][prev[i]] += cf;
		}
	}
	return tot;
}

int main(){
	while( cin >> n ){
		n += 2;
		memset( flow, 0, sizeof flow );
		flow[0][n] = INF;
		flow[n-1][2*n-1] = INF;
		for( int i=1; i<n-1; ++i ){
			int cost;
			cin >> cost;
			flow[i][i+n] = cost;
		}
		int m;
		cin >> m;
		while( m-- > 0 ){
			int i, j, cost;
			cin >> i >> j >> cost;
			flow[i+n][j] += cost;
		}
		int b, d;
		cin >> b >> d;
		while( b-- > 0 ){
			int node;
			cin >> node;
			flow[n][node] = INF;
		}
		while( d-- > 0 ){
			int node;
			cin >> node;
			flow[node+n][n-1] = INF;
		}
		
		// for( int i=0; i<2*n; ++i ){
			// for( int j=0; j<2*n; ++j ){
				// cout << flow[i][j] << " ";
			// }
			// cout << endl;
		// }
		cout << maxFlow(0, 2*n-1) << endl;
		
	}
}
