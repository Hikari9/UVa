/**
	UVa 11094 - Continents
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.019s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int m, n, X, Y, i, j, c, ans;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
string s[22];
char land;
bool inRange( int x ){
	return x>=0 && x<m;
}
void dfs( int x, int y ){
	if( inRange( x ) ){
		if( y==n ) y=0;
		else if( y==-1 ) y=n-1;
		if( s[x][y]==land ){
			++c;
			s[x][y] = '\n';
			for( int k=0; k<4; ++k ){
				dfs( x+dx[k], y+dy[k] );
			}
		}
	}
}
int main(){
	while( cin >> m >> n ){
		while( cin.get()!='\n' );
		for( i=0; i<m; ++i ){
			getline( cin, s[i] );
		}
		cin >> X >> Y;
		land = s[X][Y];
		c = 0;
		dfs( X, Y );
		ans = 0;
		for( i=0; i<m; ++i ){
			for( j=0; j<n; ++j ){
				if( s[i][j]==land ){
					c = 0;
					dfs( i, j );
					ans = max( c, ans );
				}
			}
		}
		cout << ans << endl;
	}
}
