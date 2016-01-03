/**
	UVa 116 - Unidirectional TSP
	by Rico Tiongson
	Submitted: June 18, 2013
	Accepted 0.145s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long lag;
lag i, j, r, c, cur, ar[2][12][102], mn, mni;
bool ans[12][102];
void input(){
	for( i=0; i<r; ++i ) for( j=0; j<c; ++j ) scanf("%lld",&ar[0][i][j]);
}
lag dfs( const lag& x, const lag& y ){
	lag up, down, UP, MID, DOWN, MIN;
	if( y==c-1 || ans[x][y] ) return ar[0][x][y];
	ans[x][y] = true;
	up = (x-1+r)%r;
	down = (x+1)%r;
	UP = dfs( up, y+1 ); //one up
	MID = dfs( x, y+1 ); //mid
	DOWN = dfs( down, y+1 ); //one down
	MIN = up;
	if( UP>MID ){
		UP = MID;
		MIN = x;
	}
	else if( UP==MID && MIN>x ){
		UP = MID;
		MIN = x;
	}
	if( UP>DOWN  ){
		UP = DOWN;
		MIN = down;
	}
	else if( UP==DOWN && MIN>down ){
		UP = DOWN;
		MIN = down;
	}
	ar[0][x][y] += UP;
	ar[1][x][y] = MIN;
	return ar[0][x][y];
}
void next( const lag& x, const lag& y ){
	if( y==c-1 ) printf( " %lld",x+1 );
	else{
		if(y) putchar(' ');
		printf( "%lld",x+1 );
		next( ar[1][x][y], y+1 );
	}
}
void calculate(){
	mn = dfs(0,0);
	mni = 0;
	for( i=1; i<r; ++i ){
		cur = dfs( i, 0 );
		if( cur<mn ){
			mn = cur;
			mni = i;
		}
	}
	if( c==1 ){
		printf("%lld\n%lld\n",mni+1,mn);
	}
	else{
		next(mni,0);
		printf("\n%lld\n",mn);
	}
}
int main(){
	while( cin >> r >> c ){
		input();
		memset( ans, 0, sizeof(ans) );
		calculate();
	}
}
