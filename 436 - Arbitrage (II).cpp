/**
	UVa 436 - Arbitrage (II)
	by Rico Tiongson
	Submitted: October 18, 2013
	Accepted 0.039s C++
	O(n^3) time
*/
#include<iostream>
#include<map>
using namespace std;

int n, m, tc;
double path[35][35];
map<string, int> id;

void FloydWarshall(){
	for( int k=0; k<n; ++k ){
		for( int i=0; i<n; ++i ){
			for( int j=0; j<n; ++j ){
				path[i][j] = max( path[i][j], path[i][k] * path[k][j] );
			}
		}
	}
}

int main(){
	while( cin >> n, n ){
		for( int i=0; i<n; ++i ){
			for( int j=0; j<n; ++j ){
				path[i][j] = 0.0;
			}
			path[i][i] = 1.0;
		}
		id.clear();
		for( int i=0; i<n; ++i ){
			string s;
			cin >> s;
			id[s] = i;
		}
		cin >> m;
		for( int i=0; i<m; ++i ){
			string a, b;
			double d;
			int x, y;
			cin >> a >> d >> b;
			x = id[a];
			y = id[b];
			path[x][y] = max( path[x][y], d );
		}
		FloydWarshall();
		bool arbitrage = false;
		for( int i=0; i<n; ++i ){
			if( path[i][i] > 1.0 ){
				arbitrage = true;
				break;
			}
		}
		cout << "Case " << ++tc << ": " << (arbitrage ? "Yes" : "No") << endl;
	}
}
