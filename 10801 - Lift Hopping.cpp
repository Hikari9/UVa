/**
	UVa 10801 - Lift Hopping
	by Rico Tiongson
	Submitted: May 20, 2013
	Accepted 0.016s C++
	O(E(n+m)logn) time
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 2147483647
using namespace std;
struct edge{
	int w;
	bool floors[101];
	void reset(){
		fill(floors,floors+101,false);
		cin >> w;
	}
	void addfloors(){
		int x;
		string s;
		getline(cin,s);
		istringstream sin(s);
		while(sin >> x) floors[x] = true;
	}
} E[5];
struct node{
	int path;
	bool v;
	void reset(){
		v = false;
		path = INF;
	}
} G[101];
struct cmp{
	bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)const{
		return rhs.second < lhs.second;
	}
};
int n,k,hold;
int ABS(int x){
	return x<0?-x:x;
}
void dijkstra(){
	int Min;
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
	pq.push( make_pair(0,0) );
	while(!pq.empty()){
		Min = pq.top().first;
		pq.pop();
		if(!G[Min].v){
			if(Min==k) break;
			G[Min].v = true;
			for(int i=0;i<n;i++){
				if(E[i].floors[Min]){ //if elevator available
					for(int j=1;j<101;j++){ //add other stuff
						if(E[i].floors[j] && !G[j].v){
							hold = G[Min].path+E[i].w*ABS(j-Min);
							if(j!=k) hold+=60;
							if(G[j].path > hold){
								G[j].path = hold;
								pq.push( make_pair(j,hold) );
							}
						}
					}
				}
			}
		}
	}
}
int main(){
	G[0].path = 0;
	while(cin >> n >> k){
		G[0].v = false;
		for(int i=1;i<101;i++) G[i].reset();
		for(int i=0;i<n;i++) E[i].reset();
		cin.ignore();
		for(int i=0;i<n;i++) E[i].addfloors();
		dijkstra();
		if(G[k].path==INF) cout << "IMPOSSIBLE" << endl;
		else cout << G[k].path << endl;
	}
}
