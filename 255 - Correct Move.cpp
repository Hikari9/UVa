/**
	UVa 255 - Correct Move
	by Rico Tiongson
	Submitted: October 17, 2013
	Accepted 0.495s C++
	O(?) time
*/
#include<iostream>
#include<cstring>
using namespace std;

int a, b, c;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool inRange( int x, int y ){
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int main(){
	while( cin >> a >> b >> c ){
		bool board[8][8];
		memset( board, 0, sizeof board );
		int kx = a/8;
		int ky = a%8;
		int qx = b/8;
		int qy = b%8;
		int mx = c/8;
		int my = c%8;
		if( a==b || !inRange(kx, ky) || !inRange(qx, qy) ){
			cout << "Illegal state" << endl;
			continue;
		}
		for( int i=0; i<4; ++i ){
			int nx = qx + dx[i];
			int ny = qy + dy[i];
			while( inRange(nx, ny) ){
				if( nx == kx && ny == ky ) break;
				board[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
		}
		if( !inRange(mx, my) || !board[mx][my] ){
			cout << "Illegal move" << endl;
			continue;
		}
		for( int i=0; i<4; ++i ){
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if( inRange(nx, ny) ) board[nx][ny] = 0;
		}
		if( !board[mx][my] ){
			cout << "Move not allowed" << endl;
			continue;
		}
		// make new queen
		qx = mx;
		qy = my;
		memset( board, 0, sizeof board );
		for( int i=0; i<4; ++i ){
			int nx = qx + dx[i];
			int ny = qy + dy[i];
			while( inRange(nx, ny) ){
				if( nx == kx && ny == ky ) break;
				board[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
		}
		bool kingCanMove = false;
		for( int i=0; i<4; ++i ){
			int nx = kx + dx[i];
			int ny = ky + dy[i];
			if( inRange(nx, ny) && !board[nx][ny] ){
				kingCanMove = true;
				break;
			}
		}
		if( kingCanMove ) cout << "Continue" << endl;
		else cout << "Stop" << endl;
	}
}
