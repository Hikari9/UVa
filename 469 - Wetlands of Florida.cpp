/**
	UVa 469 - Wetlands of Florida
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.099s C++
	O(V+|E|) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int t, n, m, i, j, C;
char c[105][105];
bool v[105][105];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
inline bool inRange( int x, int y ){
	return x>=0 && x<n && y>=0 && y<m;
}
inline bool check( int x, int y ){
	if( inRange(x,y) && !v[x][y] && c[x][y]=='W' ){
		v[x][y] = true;
		return true;
	}
	return false;
}
int dfs( int x, int y ){
	if( !inRange(x,y) || c[x][y]!='W' ) return 0;
	memset( v, 0, sizeof v );
	stack< pair<int,int> > st;
	st.push( make_pair(x,y) );
	v[x][y] = true;
	C = 0;
	while( !st.empty() ){
		x = st.top().first;
		y = st.top().second;
		st.pop();
		++C;
		for( i=0; i<8; ++i ){
			if( check( x+dx[i], y+dy[i] ) ){
				st.push( make_pair( x+dx[i], y+dy[i] ) );
			}
		}
	}
	return C;
}
int main(){
	gets(c[0]);
	sscanf( c[0], "%d", &t );
	gets(c[0]);
	while(t--){
		n = 0;
		while(true){
			gets( c[n] );
			// cout << c[n] << endl;
			// return 0;
			if( c[n][0]!='L' && c[n][0]!='W' )
				break;
			++n;
		}
		// cout << n << endl;
		m = strlen( c[0] );
		// return 0;
		do{
			if( !c[n][0] ) break;
			sscanf( c[n], "%d %d", &i, &j );
			// puts( c[n] );
			printf( "%d\n", dfs(i-1,j-1) );
			// return 0;
		} while( gets(c[n]) );
		if(t) putchar('\n');
	}
}
