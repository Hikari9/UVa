/**
	UVa 11857 - Driving Range
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 2.132s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct edge{
	int i, j, w;
	edge() {}
	edge( int I, int J, int W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
};
priority_queue<edge> pq;
int n, m, f[1000001], a, b, w;
int find( int x ){
	return f[x]==-1 ? x : (f[x]=find(f[x]));
}
int kruskals(){
	w = 0;
	while( !pq.empty() && n>1 ){
		const edge& E = pq.top();
		a = find(E.i);
		b = find(E.j);
		if( a!=b ){
			f[a] = b;
			w = E.w;
			--n;
		}
		pq.pop();
	}
	if( n>1 ) return -1;
	return w;
}
int main(){
	while( cin >> n >> m, n||m ){
		memset( f, -1, n<<2 );
		pq = priority_queue<edge>();
		while( m-- ){
			cin >> a >> b >> w;
			pq.push( edge(a,b,w) );
		}
		if( kruskals()==-1 )
			cout << "IMPOSSIBLE" << endl;
		else
			cout << w << endl;
	}
}
