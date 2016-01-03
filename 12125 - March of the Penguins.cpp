/**
	UVa 12125 - March of the Penguins
	by Rico Tiongson
	Submitted: July 4, 2014
	Accepted 1.982s C++
	MaxFlow
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#define INF 2000000000

using namespace std;

int n, t;
double d;
double x[105], y[105];

int cap[205][205], flow[205][205], prev[205];

int bfs( int source, int sink ){
	queue<int> q;
	q.push(source);
	for( int i=0; i<2*n; ++i ){
		prev[i] = -2;
	}
	prev[source] = -1;
	while( !q.empty() ){
		int x = q.front(); q.pop();
		if( x == sink ){
			int cf = INF;
			for( int i=sink; prev[i] != -1; i=prev[i] ){
				cf = min( cf, flow[prev[i]][i] );
			}
			return cf;
		}
		for( int i=0; i<2*n; ++i ){
			if( prev[i] == -2 && flow[x][i] ){
				prev[i] = x;
				q.push(i);
			}
		}
	}
	return 0;
}

int maxFlow( int source, int sink ){
	memcpy( flow, cap, sizeof flow );
	int cf, tot = 0;
	while( cf = bfs(source, sink) ){
		tot += cf;
		for( int i=sink; prev[i] != -1; i=prev[i] ){
			flow[prev[i]][i] -= cf;
			flow[i][prev[i]] += cf;
		}
	}
	return tot;
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> d;
		++n;
		memset( cap, 0, sizeof cap );

		int penguins = 0;
		for( int i=1; i<n; ++i ){
			int num, m;
			cin >> x[i] >> y[i] >> num >> m;
			cap[i][i+n] = m;
			cap[n][i] = num;
			penguins += num;
		}
		for( int i=1; i<n; ++i ){
			for( int j=i+1; j<n; ++j ){
				double h = hypot( x[i] - x[j], y[i] - y[j] );
				if( h <= d + 1e-7 ){
					cap[i+n][j] = INF;
					cap[j+n][i] = INF;
				}
			}
		}
		cap[0][n] = INF;
		bool found = false;
		for( int i=1; i<n; ++i ){
			if( maxFlow(0, i) == penguins ){
				if( !found ) found = true;
				else cout << " ";
				cout << i-1;
			}
		}
		if( !found ) cout << -1;
		cout << endl;
		
	}
}
