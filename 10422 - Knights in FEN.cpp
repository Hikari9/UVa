/**
	UVa 10422 - Knights in FEN
	by Rico Tiongson
	Submitted: October 17, 2013
	Accepted 0.349s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<set>
#include<ctime>

using namespace std;
struct state;
typedef pair<state, int> edge;
struct state{
	char c[5][6];
	state() { memset( c, 0, sizeof c ); }
	state( const state& s ){
		memcpy( c, s.c, sizeof c );
	}
	int* space() const {
		for( int i=0; i<5; ++i ){
			for( int j=0; j<5; ++j ){
				if( c[i][j] == ' ' ){
					int * ans = new int[2];
					ans[0] = i;
					ans[1] = j;
					return ans;
				}
			}
		}
		return NULL;
	}
	bool operator == ( const state& s ) const {
		for( int i=0; i<5; ++i ){
			for( int j=0; j<5; ++j ){
				if( c[i][j] != s.c[i][j] ) return false;
			}
		}
		return true;
	}
	void swapSpace( int x1, int y1, int x2, int y2 ) {
		swap( c[x1][y1], c[x2][y2] );
	}
	void print()const{
		for( int i=0; i<5; ++i ){
			cout << c[i] << endl;
		}
	}
	bool operator < ( const state& s ) const {
		for( int i=0; i<5; ++i ){
			for( int j=0; j<5; ++j ){
				if( c[i][j] != s.c[i][j] ) return c[i][j] < s.c[i][j];
			}
		}
		return false;
	}
} start, target;
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
bool inRange( int x, int y ){ return x >= 0 && y >= 0 && x < 5 && y < 5; }
set<state> vis;
int bfs(){
	vis.clear();
	queue<edge> q;
	q.push( edge(start, 0) );
	vis.insert(start);
	while( !q.empty() ){
		edge& E = q.front();
		if( E.first==target ) return E.second;
		int * xy = E.first.space();
		// cout << xy[0] << " " << xy[1] << endl;
		// cout << E.second << endl;
		// E.first.print();
		// system("PAUSE");
		for( int i=0; i<8; ++i ){
			int nx = xy[0] + dx[i];
			int ny = xy[1] + dy[i];
			if( !inRange(nx, ny) ) continue;
			// make new state
			state New = E.first;
			New.swapSpace( xy[0], xy[1], nx, ny );
			// New.print();
			if( E.second < 10 && vis.insert(New).second )
				q.push( edge(New, E.second + 1) );
		}
		delete xy;
		q.pop();
	}
	return -1;
}

int main(){
	for( int i=0; i<5; ++i ){
		target.c[0][i] = '1';
		target.c[1][i] = ( i < 1 ? '0' : '1' );
		target.c[2][i] = ( i < 2 ? '0' : '1' );
		target.c[3][i] = ( i < 4 ? '0' : '1' );
		target.c[4][i] = '0';
	}
	target.c[2][2] = ' ';
	int n;
	cin >> n;
	cin.ignore();
	while(n--){
		for( int i=0; i<5; ++i )
			gets( start.c[i] );
		// start.print();
		int ans = bfs();
		if( ans == -1 ) cout << "Unsolvable in less than 11 move(s)." << endl;
		else cout << "Solvable in " << ans << " move(s)." << endl;
	}
	// cout << clock() << endl;
}
