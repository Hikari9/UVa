/**
	UVa 11377 - Airport Setup
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.042s C++
	O(n) time
*/
#include<iostream>
#include<list>
#include<vector>
using namespace std;
struct node{
	bool v, notAirport;
	vector<int> fr;
	void clear(){
		fr.clear();
		notAirport = true;
	}
	void reset(){
		v = false;
	}
}G[2001];
int t,n,m,k,a,x,b;
int bfs(){
	if(a==b) return 0;
	list<pair<int,int> > q;
	for(int i=1;i<=n;i++) G[i].reset();
	G[a].v = true;
	q.push_back(pair<int,int>(a,G[a].notAirport));
	while(!q.empty()){
		a = q.front().first;
		x = q.front().second;
		q.pop_front();
		for(int i=0;i<G[a].fr.size();i++){
			m = G[a].fr[i];
			if(!G[m].v){
				if(m==b) return x+G[b].notAirport;
				G[m].v = true;
				if(G[m].notAirport) q.push_back(pair<int,int>(m,x+1)); //add airport
				else q.push_front(pair<int,int>(m,x));
			}
		}
	}
	return -1;
}
int main(){
	cin >> t;
	for(int r=1;r<=t;r++){
		cout << "Case " << r << ':' << endl;
		cin >> n >> m >> k;
		for(int i=1;i<=n;i++) G[i].clear();
		while(k--){
			cin >> a;
			G[a].notAirport = false;
		}
		while(m--){
			cin >> a >> b;
			G[a].fr.push_back(b);
			G[b].fr.push_back(a);
		}
		cin >> k;
		while(k--){
			cin >> a >> b;
			cout << bfs() << endl;
		}
		cout << endl;
	}
}
