/**
	UVa 1235 - Anti Brute Force Lock
	by Rico Tiongson
	Submitted: June 1, 2013
	Accepted 0.085s C++
	O(4n + (n-1)log(n)) time
*/
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define mx 10000
#define INF 2147483647
using namespace std;

int f[mx]; // for union find
// bool vis[mx];

int find(int x){
	if(f[x]==x) return x;
	else return f[x] = find( f[x] );
}

struct edge{
	int i, j, w;
	edge(){}
	edge(int I, int J, int W): i(I), j(J), w(W) {}
	bool operator< (const edge& rhs) const{
		return rhs.w < w;
	}
};
int t,n,x;
priority_queue<edge> pq;
int kruskals(){
	int a, b, ans=0;
	// for(int i=0; i<mx; i++)
		// f[i] = i;
	while( n>1 ){
		const edge& E = pq.top();
		a = find(E.i);
		b = find(E.j);
		if( a!=b ){
			f[a] = b;
			// cerr << E.i << '*' << E.j << '*' << E.w << endl;
			ans += E.w;
			--n;
		}
		pq.pop();
	}
	return ans;
}
int digs[501][4],v[501],sum,mn;
char buf[6];
// vector<int> v;
int parse(int i, int j){
	sum = 0;
	for(int k=0;k<4;++k){
		x = abs(digs[i][k]-digs[j][k]);
		if(x>5) x = 10-x;
		sum+=x;
		// sum += min(abs(digs[i][k] - digs[j][k]),10-abs(digs[i][k] - digs[j][k]));
	}
	// cerr << i << ' ' << j << ' ' << sum << endl;
	return sum;
}
int main(){
	// cin >> t;
	scanf("%d",&t);
	while( t ){
		pq = priority_queue<edge>();
		// v.clear();
		scanf("%d",&n);
		// cin >> n;
		for(int i=0;i<n;++i){
			// cin >> buf;
			scanf("%s",buf);
			v[i] = atoi(buf);
			// v.push_back(atoi(buf));
			for(int j=0;j<4;++j) digs[i][j] = buf[j]-'0';
		}
		//get digs
		f[0] = 0;
		mn = INF;
		for(int i=0;i<n;++i){
			f[ v[i] ] = v[i];
			sum = 0;
			for(int k=0;k<4;++k){
				if(digs[i][k]>5) sum+=10-digs[i][k];
				else sum+=digs[i][k];
				// sum += min( digs[i][k], 10-digs[i][k] );
				// sum += min(abs(digs[i][k] - digs[j][k]),abs(10+digs[i][k] - digs[j][k]));
			}
			mn = min(sum,mn);
			// pq.push(edge(0,v[i],sum));
			// pq.push( edge(0,v[i],min(digs[i][0],10-digs[i][0])+min(digs[i][1],10-digs[i][1])+min(digs[i][2],10-digs[i][2])+min(digs[i][3],10-digs[i][3])) );
			for(int j=i+1;j<n;++j){
				pq.push( edge( v[i], v[j], parse(i,j) ) );
			}
		}
		// cout << kruskals()+mn << endl;
		printf("%d\n",kruskals()+mn);
		--t;
	}
}
