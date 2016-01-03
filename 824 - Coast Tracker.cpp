/**
	UVa 824 - Coast Tracker
	by Rico Tiongson
	Submitted: November 1, 2013
	Accepted 0.012s C++
	O(?) time
*/
#include<iostream>
#include<cstring>
#include<map>
#define LAND 1
#define WATER 0
using namespace std;
struct point{
	int x, y;
	point() {}
	point( int X, int Y ): x(X), y(Y) {}
	bool operator < ( const point& p ) const {
		return x < p.x || ( x == p.x && y < p.y );
	}
};
int x, y, d;
map<point, bool> m;

// int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
// int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

bool board[3][3];

int main(){
	while( cin >> x >> y >> d, ~x ){
		m.clear();
		for( int i=0; i<8; ++i ){
			int X, Y;
			bool S;
			cin >> X >> Y >> S;
			m[ point(X, Y) ] = S;
		}
		
		memset( board, 0, sizeof board );
		
		for( int k=0; k<8; ++k ){
			int nx = x + dx[k];
			int ny = y + dy[k];
			bool b;
			if( m.count( point(nx, ny) ) )
				b = m[point(nx, ny)];
			else b = WATER;
			int ix = 1 + dx[k];
			int iy = 1 + dy[k];
			board[ix][iy] = b;
		}
		bool temp[3][3];
		for( int i=0; i<3; ++i ){
			for( int j=0; j<3; ++j ){
				temp[i][j] = board[j][2-i];
			}
		}
		for( int i=0; i<3; ++i ){
			for( int j=0; j<3; ++j ){
				board[i][j] = temp[i][j];
			}
		}
		// for( int i=0; i<3; ++i ){
			// for( int j=0; j<3; ++j ){
				// if( i==1 && j==1 ) cout << d;
				// else cout << board[i][j];
			// }
			// cout << endl;
		// }
		// if( --d == -1 ) d = 7;
		int lol = 64;
		while( lol-- ){
			// if( --d == -1 ) d = 7;
			int nx = 1 + dx[d];
			int ny = 1 + dy[d];
			// cout << nx << " " << ny << endl;
			if( --d == -1 ) d = 7;
			if( board[nx][ny] == WATER ) break;
			
		}
		lol = 64;
		while( lol-- ){
			int nx = 1 + dx[d];
			int ny = 1 + dy[d];
			// cout << nx << " " << ny << endl;
			if( board[nx][ny] == LAND ) break;
			d = (d+1)%8;
		}
		cout << d << endl;
		
	}
}
