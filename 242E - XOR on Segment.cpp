/**
	CodeForces 242E - XOR on Segment
	by Rico Tiongson
	Submitted: November 21, 2013
	Accepted 0.842s C++
	O(nlogn) build + O(logn) time
*/
#include <iostream>
#include <cstring>
using namespace std;
typedef long long lag;

#define LEFT p<<1
#define RIGHT (p<<1) + 1

int n, m, a, b, XOR;
int x[100005];
char cmd;
int st[400005][20];
lag delta[400005];

void pushDelta( int p, int L, int R ){
	if( delta[p] == 0 ) return;
	int len = R - L + 1;
	// push down delta
	if( L != R ){
		delta[LEFT] ^= delta[p];
		delta[RIGHT] ^= delta[p];
	}
	for( int i=0, I=1; I<=delta[p]; ++i, I<<=1 ){
		if( I & delta[p] ){
			// flip sum
			st[p][i] = len - st[p][i];
		}
	}
	delta[p] = 0;
}

void pullDelta( int p ){
	for( int i=0; i<20; ++i ){
		st[p][i] = st[LEFT][i] + st[RIGHT][i];
	}
}

void makeTree( int p = 1, int L = 1, int R = n ){
	if( L > R ) return;
	delta[p] = 0;
	if( L == R ){
		// pseudo-binary
		int mask = x[L];
		for( int i=0; mask; ++i ){
			st[p][i] = ( mask & 1 );
			mask >>= 1;
		}
		return;
	}
	int M = (L+R) >> 1;
	makeTree( LEFT, L, M );
	makeTree( RIGHT, M+1, R );
	pullDelta( p );
}

void update( int p = 1, int L = 1, int R = n ){
	pushDelta( p, L, R );
	if( L > b || R < a ){
		return;
	}
	if( a <= L && R <= b ){
		delta[p] ^= XOR;
		pushDelta( p, L, R );
		return;
	}
	// pushDelta( p, L, R );
	int M = (L+R) >> 1;
	update( LEFT, L, M );
	update( RIGHT, M+1, R );
	pullDelta( p );
}

lag get( int id ){
	lag ans = 0;
	for( int i=19; i>=0; --i ){
		ans = (ans << 1) + st[id][i];
	}
	return ans;
}

lag query( int p = 1, int L = 1, int R = n ){
	pushDelta( p, L, R );
	if( L > b || R < a ) return 0;
	if( a <= L && R <= b ) return get(p);
	int M = (L+R) >> 1;
	lag ans = query( LEFT, L, M ) + query( RIGHT, M+1, R );
	pullDelta( p );
	return ans;
}

int main(){
	memset( st, 0, sizeof st );
	cin >> n;
	for( int i=1; i<=n; ++i ) cin >> x[i];
	makeTree();
	cin >> m;
	while( m-- ){
		cin >> cmd >> a >> b;
		if( cmd == '1' ) cout << query() << endl;
		else{
			cin >> XOR;
			update();
		}
	}
}
