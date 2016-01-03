/**
	UVa 10067 - Playing with Wheels
	by Rico Tiongson
	Submitted: October 27, 2013
	Accepted 0.122s C++
	O(|V| + E) time
*/
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

struct state{
	int a[4];
	state() {}
	state( const state& s ){
		for( int i=0; i<4; ++i ) a[i] = s[i];
	}
	state( int A, int B, int C, int D ){
		a[0] = A;
		a[1] = B;
		a[2] = C;
		a[3] = D;
	}
	void in(){
		for( int i=0; i<4; ++i )
			scanf( "%d", a+i );
	}
	int& operator[]( int i ){
		return a[i];
	}
	int operator[]( int i ) const {
		return a[i];
	}
	bool operator==( const state& s ) const {
		for( int i=0; i<4; ++i ){
			if( a[i] != s[i] ) return false;
		}
		return true;
	}
};

ostream& operator << ( ostream& out, const state& s ){
	return out << s[0] << " " << s[1] << " " << s[2] << " " << s[3];
}

int t, n;
bool vis[10][10][10][10];
state start, end, forbidden;

bool& visited( const state& s ){
	return vis[s[0]][s[1]][s[2]][s[3]];
}

bool inRange( const state& s ){
	for( int i=0; i<4; ++i ){
		if( s[i] < 0 || s[i] > 9 ) return false;
	}
	return true;
}

int bfs(){
	if( visited(start) || visited(end) ) return -1;
	if( start == end ) return 0;
	queue<state> q;
	queue<int> d;
	q.push(start);
	d.push(0);
	visited(start) = true;
	while( !q.empty() ){
		state s = q.front();
		int w = d.front() + 1; d.pop();
		for( int i=0; i<4; ++i ){
			for( int j=-1; j<2; j+=2 ){
				s[i] = (s[i] + j + 10) % 10;
				if( !visited(s) ){
					visited(s) = true;
					if( s==end ){
						return w;
					}
					q.push(s);
					d.push(w);
				}
				s[i] = (s[i] - j + 10) % 10;
			}
		}
		q.pop();
	}
	return -1;
}

int main(){
	scanf( "%d", &t );
	while(t--){
		start.in();
		end.in();
		scanf( "%d", &n );
		memset( vis, 0, sizeof vis );
		while(n--){
			forbidden.in();
			visited(forbidden) = true;
		}
		printf( "%d\n", bfs() );
	}
}
