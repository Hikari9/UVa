/**
	UVa 11710 - Expensive subway
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.515s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
#define INF 1000000000
using namespace std;
struct edge{
	int i, j, w;
	edge() {}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator < ( const edge& e ) const {
		return w > e.w;
	}
};

map<string, int> id;
priority_queue<edge> pq;
vector<pair<int, int> > adj[405];
int n, s, c, x, f[405];

char s1[15], s2[15];

int find( int X ){
	return f[X] == -1 ? X : f[X] = find( f[X] );
}

int Kruskals(){
	n = s;
	
	if( s <= 1 ) return 0;
	int ans = 0;
	memset( f, -1, sizeof f );
	for( int i=0; i<n; ++i ){
		adj[i].clear();
	}
	while( !pq.empty() ){
		int a = find( pq.top().i );
		int b = find( pq.top().j );
		if( a != b ){
			f[a] = b;
			ans += pq.top().w;
			if( --s <= 1 ) return ans;
			adj[pq.top().i].push_back( make_pair( pq.top().j, pq.top().w ) );
			adj[pq.top().j].push_back( make_pair( pq.top().i, pq.top().w ) );
		}
		pq.pop();
	}
	return -1;
}


int main(){
	while( scanf("%d %d", &s, &c) == 2 && ( s || c ) ){
		id.clear();
		for( int i=0; i<s; ++i ){
			scanf( "%s", s1 );
			id[s1] = i;
		}
		pq = priority_queue<edge>();
		for( int i=0; i<c; ++i ){
			scanf( "%s %s %d", s1, s2, &x );
			int a = id[s1];
			int b = id[s2];
			pq.push( edge(a, b, x) );
		}
		scanf( "%s", s1 );
		int ans = Kruskals();
		if( ans == -1 ) puts("Impossible");
		else{
			printf( "%d\n", ans );
		}
	}
}
