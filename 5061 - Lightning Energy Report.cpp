#include <iostream>
#include <cstring>
#include <vector>
#define N 50001
using namespace std;

int t, n, q, tc;
int a, b, c;
int x[N], y[N];
int level[N], parent[N], energy[N];
vector<int> adj[N];

int& other( int node, int edge ){
	if( x[edge] == node ) return y[edge];
	return x[edge];
}

void makeTree( int node, int depth ){
	level[node] = depth;
	for( int i=0; i<adj[node].size(); ++i ){
		int nextNode = other( node, adj[node][i] );
		if( level[nextNode] == -1 ){
			parent[nextNode] = node;
			makeTree( nextNode, depth + 1 );
		}
	}
}

void applyEnergy(){
	while( a >= 0 && a < n && b >= 0 && b < n && level[a] < level[b] ){
		energy[b] += c;
		b = parent[b];
	}
	while( a >= 0 && a < n && b >= 0 && b < n && level[a] > level[b] ){
		energy[a] += c;
		a = parent[a];
	}
	while( a >= 0 && a < n && b >= 0 && b < n && a != b ){
		energy[a] += c;
		energy[b] += c;
		a = parent[a];
		b = parent[b];
	}
	if( a >= 0 && a < n && b >= 0 && b < n )
		energy[a] += c;
}

int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i=0; i<n; ++i ) adj[i].clear();
		for( int i=0; i<n-1; ++i ){
			cin >> x[i] >> y[i];
			if( x[i] >= 0 && x[i] < n && y[i] >= 0 && y[i] < n ){
				adj[x[i]].push_back(i);
				adj[y[i]].push_back(i);
			}
		}
		memset( level, -1, sizeof level );
		parent[0] = -1;
		makeTree(0, 0);
		
		memset( energy, 0, sizeof energy );
		
		cin >> q;
		while( q-- ){
			cin >> a >> b >> c;
			applyEnergy();
		}
		
		cout << "Case #" << ++tc << ":" << endl;
		
		for( int i=0; i<n; ++i ){
			cout << energy[i] << endl;
		}
		
	}
}
