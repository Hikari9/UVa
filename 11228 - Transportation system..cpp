/**
	UVa 11228 - Transportation system.
	by Rico Tiongson
	Submitted: May 13, 2013
	Accepted 0.215s C++
	O(2n) time
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
typedef long long lag;
const lag INF(580472870233178131LL);
int t,n,clust,a,b,c;
lag adj[1001][1001],r,f[1001];
struct edge{
	int i,j;
	lag w;
	edge(){}
	edge(int i_, int j_): i(i_),j(j_) { w = adj[i_][j_]; }
	bool operator<(const edge& rhs)const{
		return rhs.w<w;
	}
} E;
struct node{
	int x,y,state;
} G[1001];
int findState(int x){
	return G[x].state==x ? x : G[x].state = findState(G[x].state);
}
int find(int x){
	return f[x]==x ? x : f[x] = find(f[x]);
}
lag Dist( const node& lhs, const node& rhs ){
	lag X = lhs.x-rhs.x, Y = lhs.y-rhs.y;
	return X*X+Y*Y;
}
void print(priority_queue<edge> q){
	while(!q.empty()){
		cout << q.top().w << ' ';
		q.pop();
	}
	cout << endl;
}
double kruskals(vector<node*>& v){
	priority_queue<edge> pq;
	for(int i=0;i<v.size();i++){
		f[v[i]-G] = v[i]-G;
		for(int j=i+1;j<v.size();j++){
			pq.push( edge( v[i]-G, v[j]-G ) );
		}
	}
	int Edges = v.size()-1;
	double mx=0.;
	while(Edges){
		E = pq.top();
		pq.pop();
		a = find(E.i);
		b = find(E.j);
		if(a!=b){
			f[a] = b;
			Edges--;
			mx += sqrt(E.w);
		}
	}
	return mx;
}
double kruskals2(int Edges){
	priority_queue<edge> pq;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			pq.push( edge( i, j ) );
		}
	}
	double mx=0.;
	while(Edges){
		E = pq.top();
		pq.pop();
		a = find(E.i);
		b = find(E.j);
		if(a!=b){
			f[a] = b;
			Edges--;
			mx += sqrt(E.w);
		}
	}
	return mx;
}

void multiKruskals(){
	double road=0.;
	map<int,vector<node*> > States;
	for(int i=0;i<n;i++) States[findState(i)].push_back( &G[i] );
	for(map<int,vector<node*> >::iterator it=States.begin();it!=States.end();it++) road += kruskals(it->second);
	cout << "Case #" << c << ": " << States.size() << ' ' << road+1e-7 << ' ' << kruskals2(States.size()-1)+1e-7 << endl;
}
int main(){
	cout.precision(0);
	cout << fixed;
	for(int i=0;i<1001;i++) adj[i][i]=0;
	cin >> t;
	for(c=1;c<=t;c++){
		cin >> n >> r;
		r*=r;
		for(int i=0;i<n;i++){
			cin >> G[i].x >> G[i].y;
			G[i].state=i;
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				adj[j][i] = adj[i][j] = Dist(G[i],G[j]);
				if(adj[i][j]<=r) G[findState(i)].state = findState(j);
			}
		}
		 multiKruskals();
	}
}
