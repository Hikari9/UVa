/**
	UVa 859 - Chinese Checkers
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.032s C++
	O(|V| + E) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
	int x, y, w;
	point() {}
	point( int X, int Y, int W ): x(X), y(Y), w(W) {}
	bool operator < ( const point& p ) const {
		return x > p.x || ( x == p.x && y < p.y );
	}
	
};

int l, c, p, a, b;
int board[1005][1005];
bool first = true;

bool inRange( int x, int y ){
	return x > 0 && y > 0 && x <= l && y <= c;
}
int dx[] = {
	2, 2, 2, 0, 0
};
int dy[] = {
	-2, 0, 2, -2, 2
};
int dx2[] = {
	0, 1, 0
};
int dy2[] = {
	-1, 0, 1
};


int qp, id;
vector<point> q;

void bfs(){
	// id = 0;
	// id = (board[a][b] & 1);
	q.clear();
	q.push_back( point(a, b, 0) );
	// printf( "%d %d\n", a + dx[id][0], b + dy[0] );
	for( qp=0; qp<q.size(); ++qp ){
		a = q[qp].x;
		b = q[qp].y;
		int w = q[qp].w + 1;
		for( int i=0; i<5; ++i ){
			int nx = a + dx[i];
			int ny = b + dy[i];
			if( !inRange(nx, ny) || board[nx][ny] || !board[a + (dx[i]/2)][b + (dy[i]/2)] ) continue;
			board[nx][ny] = 1;
			q.push_back( point(nx, ny, w) );
		}
	}
	// one step
	a = q[0].x;
	b = q[0].y;
	for( int i=0; i<3; ++i ){
		int nx = a + dx2[i];
		int ny = b + dy2[i];
		if( !inRange(nx, ny) || board[nx][ny] ) continue;
		board[nx][ny] = 1;
		q.push_back( point(nx, ny, 1) );
	}
}

int main(){
	while( scanf( "%d %d", &l, &c ) == 2 ){
		if( !first ) putchar('\n');
		else first = false;
		memset( board, 0, sizeof board );
		p = c << 1;
		for( int i=0; i<p; ++i ){
			scanf( "%d %d", &a, &b );
			board[a][b] = 1;
		}
		for( int i=0; i<p; ++i ){
			scanf( "%d %d", &a, &b );
			board[a][b] = 2;
		}
		
		scanf( "%d %d", &a, &b );
		bfs();
		sort( q.begin() + 1, q.end() );
		for( int i=1; i<q.size(); ++i ){
			printf( "%d %d %d\n", q[i].x, q[i].y, q[i].w );
		}
	}
}