/**
	UVa 1216 - The Bug Sensor Problem
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.076s C++
	O(mlogn) time
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
typedef long long lag;
struct edge{
	int i, j;
	lag w;
	edge() {}
	edge( int I, int J, lag W ): i(I), j(J), w(W) {}
	bool operator<( const edge& _ )const{
		return _.w < w;
	}
};
lag dist2( lag dx, lag dy ){
	return dx*dx + dy*dy;
}
int find( int );
int t, nmin, n, f[1000001], i, a, b;
lag X[1000001], Y[1000001];
priority_queue<edge> pq;
lag kruskals(){
	memset( f, -1, n*4 );
	lag mindist = 0;
	while( !pq.empty() && n>nmin ){
		const edge& E = pq.top();
		a = find(E.i);
		b = find(E.j);
		if( a!=b ){
			f[a] = b;
			mindist = E.w;
			--n;
		}
		pq.pop();
	}
	return (lag)ceil(sqrt(mindist));
}
int main(){
	cin >> t;
	while( t-- ){
		pq = priority_queue<edge>();
		cin >> nmin;
		n = 0;
		while(true){
			cin >> X[n];
			if( X[n]==-1 ) break;
			cin >> Y[n];
			for( i=0; i<n; ++i ){
				pq.push( edge( i, n, dist2( X[n]-X[i], Y[n]-Y[i] ) ) );
			}
			++n;
		}
		cout << kruskals() << endl;
	}
}
int find( int x ){
	return f[x]==-1 ? x : f[x]=find(f[x]);
}
