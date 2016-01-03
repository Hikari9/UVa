/**
	UVa 10354 - Avoiding Your Boss
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.045s C++
	O(n^3) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define INF 1000000000
using namespace std;

int p, r, bh, of, yh, m;
int p1, p2, d;
int boss[105][105], me[105][105];
int closed[105];

void FloydWarshall( int path[105][105] ){
	for( int k=1; k<=p; ++k ){
		if( closed[k] ) continue;
		for( int i=1; i<=p; ++i ){
			if( closed[i] ) continue;
			for( int j=1; j<=p; ++j ){
				if( closed[j] ) continue;
				path[i][j] = min( path[i][k] + path[k][j], path[i][j] );
			}
		}
	}
}

int main(){
	while( cin >> p >> r >> bh >> of >> yh >> m ){
		for( int i=1; i<=p; ++i ){
			for( int j=1; j<=p; ++j ){
				boss[i][j] = me[i][j] = INF;
			}
			boss[i][i] = me[i][i] = 0;
		}
		for( int i=0; i<r; ++i ){
			cin >> p1 >> p2 >> d;
			boss[p1][p2] = boss[p2][p1] = me[p1][p2] = me[p2][p1] = d;
		}
		memset( closed, 0, sizeof closed );
		FloydWarshall( boss );
		for( int i=1; i<=p; ++i ){
			if( boss[bh][of] == boss[bh][i] + boss[i][of] ) closed[i] = true;
		}
		if( closed[yh] || closed[m] ){
			cout << "MISSION IMPOSSIBLE." << endl;
			continue;
		}
		FloydWarshall( me );
		int ans = me[yh][m];
		if( ans == INF ){
			cout << "MISSION IMPOSSIBLE." << endl;
		}
		else{
			cout << ans << endl;
		}
	}
}
