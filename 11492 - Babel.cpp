/**
	UVa 11492 - Babel
	by Rico Tiongson
	Submitted: May 19, 2013
	Accepted 0.262s C++
	O(28(n+E)logn) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 2147483647
using namespace std;
struct edge{
	unsigned i,w,c;
	edge(){}
	edge(unsigned i_, unsigned w_, unsigned c_): i(i_), w(w_), c(c_) {}
	bool operator<(const edge& rhs) const{
		return rhs.w < w;
	}
} E;
struct node{
	int path[28];
	bool v[28];
	vector<edge> fr;
	node(){
		fill(path,path+28,INF);
		fill(v,v+28,false);
	}
};
unsigned n,T,Index;
int ans,w2;
vector<node> G;
int dijkstra(){
	//start at 0, end at T
	if(!T) return -1;
	fill(G[0].path,G[0].path+28,0);
	priority_queue<edge> pq;
	pq.push( edge(0,0,0) );
	while(!pq.empty()){
		E = pq.top();
		pq.pop();
		if(E.i==T) return E.w;
		if(!G[E.i].v[E.c]){
			G[E.i].v[E.c] = true;
			for(unsigned j=0;j<G[E.i].fr.size();j++){
				edge& E2 = G[E.i].fr[j];
				w2 = E.w + E2.w;
				if(w2 < G[E2.i].path[E2.c] && E.c!=E2.c){
					G[E2.i].path[E2.c] = w2;
					pq.push( edge(E2.i,w2,E2.c) );
				}
			}
		}
	}
	return -1;
}
int main(){
	map<string,int> m;
	pair<map<string,int>::iterator,int> it,it2;
	string a,b,e;
	while(cin >> n, n){
		m.clear();
		G.clear();
		Index = 0;
		cin >> a;
		G.push_back( node() );
		m[a] = Index++;
		cin >> b;
		it = m.insert( pair<string,int>(b,Index) );
		if(it.second){
			G.push_back( node() );
			Index++;
		}
		T = it.first->second;
		for(unsigned i=0;i<n;i++){
			cin >> a >> b >> e;
			it = m.insert( pair<string,int>(a,Index) );
			if(it.second){
				G.push_back( node() );
				Index++;
			}
			it2 = m.insert( pair<string,int>(b,Index) );
			if(it2.second){
				G.push_back( node() );
				Index++;
			}
			e[0]-='`';
			G[it.first->second].fr.push_back( edge(it2.first->second,e.size(),e[0]) );
			G[it2.first->second].fr.push_back( edge(it.first->second,e.size(),e[0]) );
		}
		ans = dijkstra();
		if(ans==-1) cout << "impossivel" << endl;
		else cout << ans << endl;
	}
}
