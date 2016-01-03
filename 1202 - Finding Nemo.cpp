/**
	UVa 1202 - Finding Nemo
	by Rico Tiongson
	Submitted: December 6, 2013
	Accepted 0.075s C++
	O(n^2) time
*/
#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-7
#define FREE 0
#define WALL 1
#define DOOR 2
using namespace std;

struct edge{
	int x, y, d;
	edge() {}
	edge( int X, int Y, int D ): x(X), y(Y), d(D) {}
};

int wall[405][405];

bool inRange( int x, int y ){
	return x >= 0 && y >= 0 && x < 405 && y < 405;
}

int path[405][405];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int bfs( int nemox, int nemoy ){
	for( int i=0; i<405; ++i ){
		for( int j=0; j<405; ++j ){
			path[i][j] = 2147483647;
		}
	}
	path[nemox][nemoy] = 0;
	deque<edge> q;
	q.push_back( edge(nemox, nemoy, 0) );
	int ans = 2147483647;
	while( !q.empty() ){
		int x = q.back().x;
		int y = q.back().y;
		int d = q.back().d;
		q.pop_back();
		for( int k=0; k<4; ++k ){
			int wx = x + dx[k];
			int wy = y + dy[k];
			int nx = wx + dx[k];
			int ny = wy + dy[k];
			if( !inRange(wx, wy) ){
				ans = min( ans, d );
				continue;
			}
			if( wall[wx][wy] == WALL ) continue;
			switch( wall[wx][wy] ){
				case DOOR:
					if( !inRange(nx, ny) ){
						ans = min( ans, d+1 );
					}
					else if( path[nx][ny] > d + 1 ){
						path[nx][ny] = d + 1;
						q.push_front( edge(nx, ny, d + 1) );
					}
					break;
				case FREE:
					if( !inRange(nx, ny) ){
						ans = min( ans, d );
					}
					else if( path[nx][ny] > d ){
						path[nx][ny] = d;
						q.push_back( edge(nx, ny, d) );
					}
					break;
			}			
		}
	}
	return ans == 2147483647 ? -1 : ans;
}

int main(){
	int m, n;
	int x, y, d, t;
	double nx, ny;
	while( cin >> m >> n, m != -1 && n != -1 ){
		memset( wall, 0, sizeof wall );
		while( m-- > 0 ){
			cin >> x >> y >> d >> t;
			x <<= 1;
			y <<= 1;
			t <<= 1;
			if( d == 0 ){
				for( int i=1; i<t; i+=2 ){
					wall[x+i][y] = WALL;
				}
			}
			else{
				for( int i=1; i<t; i+=2 ){
					wall[x][y+i] = WALL;
				}
			}
		}
		while( n-- > 0 ){
			cin >> x >> y >> d;
			x <<= 1;
			y <<= 1;
			if( d == 0 ){
				wall[x+1][y] = DOOR;
			}
			else{
				wall[x][y+1] = DOOR;
			}
		}
		cin >> nx >> ny;
		x = (int)( floor(nx)*2 + eps ) + 1;
		y = (int)( floor(ny)*2 + eps ) + 1;
		if( !inRange(x, y) ){
			cout << "0" << endl;
			continue;
		}
		cout << bfs(x, y) << endl;
	}
}
