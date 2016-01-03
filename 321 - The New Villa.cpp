/**
	UVa 321 - The New Villa
	by Rico Tiongson
	Submitted: July 19, 2013
	Accepted 0.012s C++
	O(?) time * O(1) graph state
*/
// #include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<bitset>
#define bmask 1024
#define lmask 1023
using namespace std;
bool G[10][10], v[10240];
int L[10], prev[10240], r, d, s, i, a, b, l, li, tc=0;
const int end[11] = {0, 1, 1026, 2052 , 3080, 4112, 5152, 6208, 7296, 8448, 9728};
queue<int> q;
bool input(){
	// cin >> r >> d >> s;
	scanf("%d %d %d", &r, &d, &s);
	return r||d||s;
}
bool makestate( int from, int to ){
	if( v[to] ) return false;
	v[to] = true;
	prev[to] = from;
	q.push( to );
	return true;
}
bool bfs(){
	q = queue<int>();
	v[1] = true;
	q.push( 1 );
	while( !q.empty() ){
		a = q.front();
		q.pop();
		if( a==end[r] ) return true;
		b = (a>>10); // current room number
		l = (a&lmask);
		for( i=0, li=1; i<10; ++i, li<<=1 ){
			if( G[b][i] && (l&li) ){
				makestate(a, (i<<10) | l );
			}
		}
		for( i=0, li=1; i<r; ++i, li<<=1 ){
			if( L[b] & li ){
				// switch light mode 
				if( l & li ){
					if( b!=i ) makestate( a, (b<<10) | ( l&~li ) );
					continue;
				}
				makestate( a, (b<<10) | (l|li) );
			}
		}
	}
	return false;
}
void print( int p ){
	if( prev[p] == -1 ) return;
	print( prev[p] );
	// index
	i = prev[p] ^ p;
	if( i & lmask ){
		// get first occurence
		a = 1;
		for( b=i>>1; b; b>>=1 ) ++a;
		if( i&p )
			printf("- Switch on light in room %d.\n", a);
		else
			printf("- Switch off light in room %d.\n", a);
		return;
	}
	printf("- Move to room %d.\n", (p>>10)+1);
}
int main(){
	while( input() ){
		memset( G, 0, sizeof G );
		memset( L, 0, sizeof L );
		memset( v, 0, sizeof v );
		memset( prev, -1, sizeof prev );
		while( d ){
			scanf("%d %d", &a, &b);
			--a, --b, --d;
			G[a][b] = G[b][a] = true;
		}
		while( s ){
			scanf("%d %d", &a, &b);
			--a, --b, --s;
			L[a] |= (1<<b);
		}
		printf("Villa #%d\n",++tc);
		if( bfs() ){
			// cout << prev[ end[r] ] << endl;
			a = 0;
			for( b=prev[ end[r] ]; b!=-1; b=prev[b] ) ++a;
			printf("The problem can be solved in %d steps:\n", a);
			print(end[r]);
		}
		else{
			puts("The problem cannot be solved.");
		}
		putchar('\n');
	}
}
