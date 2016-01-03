/**
	UVa 614 - Mapping the Route
	by Rico Tiongson
	Submitted: November 1, 2013
	Accepted 0.009s C++
	O(V+E) time
*/
#include<iostream>
#include<cstring>
using namespace std;

int h, w, sx, sy, ex, ey;
bool vis[15][15];
int prev[15][15];
int ans[15][15], c;
bool adj[15][15][15][15];

// w, n, e, s
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool inRange( int x, int y ){
	return x > 0 && y > 0 && x <= h && y <= w;
}
bool doMore;

void dfs( int x, int y ){
	if( x == ex && y == ey ){
		doMore = false;
		return;
	}
	for( int k=0; k<4; ++k ){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if( inRange(nx, ny) && !vis[nx][ny] && adj[x][y][nx][ny] ){
			vis[nx][ny] = true;
			prev[nx][ny] = k;
			dfs(nx, ny);
		}
		if( !doMore ) return;
	}
}

void dfs(){
	memset( prev, -1, sizeof prev );
	memset( vis, 0, sizeof vis );
	doMore = true;
	dfs( sx, sy );
	memset( ans, -1, sizeof ans );
	c = 1;
	int x = ex;
	int y = ey;
	int p;
	while( true ){
		ans[x][y] = c++;
		if( x == sx && y == sy ) break;
		p = (prev[x][y] + 2) % 4;
		if( p == -1 ) break;
		x += dx[p];
		y += dy[p];
	}
}

int tc;

void border(){
	cout << '+';
	for( int j=1; j<=w; ++j ) cout << "---+";
	cout << endl;
}

int main(){
	while( cin >> h >> w >> sx >> sy >> ex >> ey, h || w || sx || sy || ex || ey ){
		memset( adj, 1, sizeof adj );
		
		for( int i=1; i<=h; ++i ){
			for( int j=1; j<=w; ++j ){
				int wall;
				cin >> wall;
				// east wall
				if( wall & 1 )
					adj[i][j] [i][j+1] = adj[i][j+1] [i][j] = 0;
				// south wall
				if( wall & 2 )
					adj[i][j] [i+1][j] = adj[i+1][j] [i][j] = 0;
				
			}
		}
		
		dfs();
		
		cout << "Maze " << ++tc << endl << endl;
		border();
		for( int i=1; i<=h; ++i ){
			// print row
			cout << '|';
			for( int j=1; j<=w; ++j ){
				if( ans[i][j] != -1 ){
					cout.width(3);
					cout.fill(' ');
					cout << right << c-ans[i][j];
				}
				else if( vis[i][j] ){
					cout << "???";
				}
				else{
					cout << "   ";
				}
				if( j == w ) cout << '|';
				else if( !adj[i][j][i][j+1] ) cout << '|';
				else cout << ' ';
			}
			cout << endl;
			if( i != h ){
				cout << '+';
				for( int j=1; j<=w; ++j ){
					if( !adj[i][j][i+1][j] ) cout << "---";
					else cout << "   ";
					cout << '+';
				}
				cout << endl;
			}
			
		}
		border();
		cout << endl << endl;
	}
}
