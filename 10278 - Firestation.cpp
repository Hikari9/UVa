/**
	UVa 10278 - Firestation
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted: 0.168s C++
	O(n^3) time
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;
const int INF(2147483647);
int t,F,n,x,y,z,mx,mn,mxf;
struct edge;
struct node{
	int path;
	bool v;
	vector<edge> frontier;
	void reset(){v=false;path=INF;}
	void clear(){frontier.clear();}
}g[501],*p;
struct edge{
	int id,weight;
	edge(){}
	edge(int i,int w):id(i),weight(w){}
	bool operator<(const edge& b)const{
		return b.weight<weight;
	}
}E;
void dikjstra(int s){
	for(int i=1;i<=n;i++) g[i].reset();
	priority_queue<edge> q;
	q.push(edge(0,0));
	while(!q.empty()){
		p = &g[q.top().id];
		q.pop();
		if(!p->v){
			p->v = true;
			for(int i=0;i<p->frontier.size();i++){
				E = p->frontier[i];
				E.weight+=p->path;
				if(!g[E.id].v && g[E.id].path>E.weight){
					g[E.id].path=E.weight;
					q.push(E);
				}
			}
		}
	}
	mx=g[1].path;
	for(int i=2;i<s;i++){
		if(mx<g[i].path) mx=g[i].path;
	}
	for(int i=s+1;i<=n;i++){
		if(mx<g[i].path) mx=g[i].path;
	}
	if(mx<mn){
		mn = mx;
		mxf = s;
	}
}
int main(){
	char c[50];
	cin >> t;
	g[0].path=0;
	while(t--){
		cin >> F >> n;
		g[0].clear();
		for(int i=0;i<F;i++){
			cin >> x;
			g[0].frontier.push_back(edge(x,0));
		}
		cin.get();
		for(int i=1;i<=n;i++) g[i].clear();
		while(cin.getline(c,50),c[0]!='\0'){
			istringstream(c) >> x >> y >> z;
			g[x].frontier.push_back(edge(y,z));
			g[y].frontier.push_back(edge(x,z));
		}
		mn=INF;
		mxf=1;
		for(int i=1;i<=n;i++){
			g[0].frontier.push_back(edge(i,0));
			g[0].v=false;
			dikjstra(i);
			g[0].frontier.pop_back();
		}
		cout << mxf << endl;
		if(t) cout << endl;
	}
}
