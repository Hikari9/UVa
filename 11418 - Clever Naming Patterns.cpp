/**
	UVa 11418 - Clever Naming Patterns
	by Rico Tiongson
	Submitted: Feb 27, 2014
	Accepted 0.019s C++
	Edmond's Karp (maxflow)
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <queue>
#include <algorithm>
#define INF 2147483647

using namespace std;

void normalize( string& s ){
	transform( s.begin(), s.end(), s.begin(), ::tolower );
	s[0] = toupper( s[0] );
	// cout << s << endl;
}

int N, n, k;
const int s = 0;
const int t = 27;
int flow[t<<1][t<<1];
string name[t<<1][t<<1];

int prev[t<<1];
int bottle[t<<1];

bool bfs(){
	memset( prev, -1, sizeof prev );
	queue<int> q;
	q.push( s );
	prev[s] = s;
	bottle[s] = INF;
	while( !q.empty() ){
		int u = q.front(); q.pop();
		for( int i=0; i<t+1+n; ++i ){
			if( flow[u][i] == 0 || prev[i] != -1 ) continue;
			prev[i] = u;
			bottle[i] = min( bottle[u], flow[u][i] );
			if( i == t ) return true;
			q.push( i );
		}
	}
	return false;
}

void EdmondsKarp(){
	while( bfs() ){
		int b = bottle[t];
		int v = t;
		while( prev[v] != v ){
			int u = prev[v];
			flow[u][v] -= b;
			flow[v][u] += b;
			v = u;
		}
	}
}

int main(){
	cin >> N;
	for( int tc=1; tc<=N; ++tc ){
		memset( flow, 0, sizeof flow );
		cin >> n;
		for( int i=0; i<n; ++i ){
			cin >> k;
			flow[s][i+t+1] = 1;
			flow[i+1][t] = 1;
			for( int j=0; j<k; ++j ){
				string str;
				cin >> str;
				normalize(str);
				int letter = str[0] - 'A' + 1;
				if( letter <= n ){
					flow[i+t+1][letter] = 1;
					name[i+t+1][letter] = str;
				}
			}
		}
		EdmondsKarp();
		cout << "Case #" << tc << ":\n";
		for( int i=1; i<=n; ++i ){
			for( int j=0; j<n; ++j ){
				if( flow[j+t+1][i] == 0 && flow[i][j+t+1] != 0 ){
					cout << name[j+t+1][i] << endl;
					break;
				}
			}
		}
	}
}
