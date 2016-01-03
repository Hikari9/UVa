/**
	UVa 10480 - Sabotage
	by Rico Tiongson
	Submitted: July 6, 2014
	Accepted 0.012s C++
	Min cut / Max flow
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
typedef long long lag;

using namespace std;
const lag INF = numeric_limits<lag>::max();

int n, m;
lag flow[55][55], cap[55][55];
int prev[55];

lag bfs(int source, int sink) {
	queue<int> q;
	q.push(source);
	memset( prev, -1, sizeof prev );
	prev[source] = -2;
	while( !q.empty() ){
		int x = q.front(); q.pop();
		if( x == sink ){
			lag cf = INF;
			for( int i=sink; prev[i] != -2; i = prev[i] ){
				cf = min( cf, flow[prev[i]][i] );
			}
			return cf;
		}
		for( int i=1; i<=n; ++i ){
			if( prev[i] == -1 && flow[x][i] > 0 ){
				q.push(i);
				prev[i] = x;
			}
		}
	}
	return 0;
}

lag maxFlow(int source, int sink) {
	lag cf, tot=0;
	while( cf = bfs(source, sink) ){
		for( int i=sink; prev[i] != -2; i = prev[i] ){
			flow[prev[i]][i] -= cf;
			flow[i][prev[i]] += cf;
		}
		tot += cf;
	}
	return tot;
}

vector<pair<int, int> > collectCuts( int source ){
	queue<int> q;
	memset( prev, -1, sizeof prev );
	q.push(source);
	prev[source] = -2;
	vector<pair<int, int> > used;
	while( !q.empty() ){
		int x = q.front(); q.pop();
		for( int i=1; i<=n; ++i ){
			if( prev[i] == -1 ){
				if( flow[x][i] > 0 && flow[i][x] > 0 ){
					prev[i] = x;
					q.push(i);
				}
				else if( (flow[x][i] == 0 || flow[i][x] == 0) && cap[x][i] > 0 ){
					used.push_back( make_pair(min(i,x), max(i,x)) );
				}
			}
		}
	}
	return used;
}

int main() {
	while( cin >> n >> m, n || m ){
		memset( flow, 0, sizeof flow );
		memset( cap, 0, sizeof cap );
		while( m-- ){
			int a, b;
			lag c;
			cin >> a >> b >> c;
			flow[a][b] += c;
			flow[b][a] += c;
			cap[a][b] += c;
			cap[b][a] += c;
		}
		// cout << maxFlow(1, 2) << endl;
		maxFlow(1, 2);
		vector<pair<int, int> > u;
		u = collectCuts(1);
		for( int i=0; i<u.size(); ++i ){
			int a = u[i].first;
			int b = u[i].second;
			if( prev[a] == -1 || prev[b] == -1 )
				cout << a << " " << b << endl;
		}
		cout << endl;
	}
}
