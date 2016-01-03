/**
	UVa 11512 - GATTACA
	by Rico Tiongson
	Submitted: June 16, 2013
	Accepted 1.005s C++
	O(?) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char buf[1024], acgt[] = "ACGT";
int n, i, id, mx, Index['T'+1], next[1000001][4], count[1000001];
string s;
// suffix tree array
void clear( int x ){
	count[x] = 0;
	memset( next[x], -1, sizeof( next[x] ) );
	// for( int j=0; j<4; ++j ) next[x][j] = -1;
}
void clear(){ id = 0; clear( 0 ); }
void insert( int start, int end ){
	++count[ start ];
	if( !buf[end] ) return;
	int& ref = next[ start ][ Index[ (int)buf[end] ] ];
	if( ref==-1 ) clear( ref=(++id) );
	insert( ref, end+1 );
}
void dfs( int x, int d ){
	buf[d] = '\0';
	if( d>s.size() && count[x]>1 ){
		mx = count[x];
		s = buf;
	}
	for( int j=0; j<4; ++j ){
		if( next[x][j]!=-1 ){
			buf[d] = acgt[j];
			dfs( next[x][j], d+1 );
		}
	}
}
int main(){
	Index['A'] = 0;
	Index['C'] = 1;
	Index['G'] = 2;
	Index['T'] = 3;
	scanf("%d",&n);
	getchar();
	while( n ){
		gets(buf);
		clear();
		for( i=0; buf[i]; ++i ) insert( 0, i );
		mx = 0;
		s.clear();
		dfs( 0, 0 );
		if( s.empty() ) puts("No repetitions found!");
		else cout << s << ' ' << mx << endl;
		--n;
	}
}
