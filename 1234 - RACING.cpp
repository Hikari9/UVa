/**
	UVa 1234 - RACING
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.352s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int f[10005];
int find( int x ){
	return f[x] == -1 ? x : f[x] = find( f[x] );
}

struct edge{
	int u, v, w;
	edge() {}
	edge( int U, int V, int W ): u(U), v(V), w(W) {}
	bool operator < ( const edge& e ) const {
		return w < e.w;
	}
};

int t, n, m;
int a, b, c;
priority_queue<edge> pq;

int Kruskals(){
	memset( f, -1, sizeof f );
	int ans = 0;
	while( n > 1 ){
		a = find( pq.top().u );
		b = find( pq.top().v );
		c = pq.top().w;
		pq.pop();
		if( a != b ){
			f[a] = b;
			ans += c;
			--n;
		}
	}
	
	return ans;
	
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		pq = priority_queue<edge>();
		int total = 0;
		while(m--){
			cin >> a >> b >> c;
			pq.push( edge(a,b,c) );
			total += c;
		}
		cout << total - Kruskals() << endl;
	}
}
