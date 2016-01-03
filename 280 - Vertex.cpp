/**
	UVa 280 - Vertex
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.322s C++
	O(n) time
*/
#include<iostream>
#include<vector>
using namespace std;
struct node{
	bool v;
	vector<int> fr;
	void reset(){ v = false; }
	void clear(){ fr.clear(); }
} G[101];
int n,v,x,c;
void DFS(int Index){
	for(int i=0;i<G[Index].fr.size();i++){
		if(!G[G[Index].fr[i]].v){
			G[G[Index].fr[i]].v = true;
			c++;
			DFS(G[Index].fr[i]);
		}
	}
}
void dfs(){
	for(int i=1;i<=n;i++) G[i].reset();
	c=0;
	DFS(x);
	cout << n-c;
	for(int i=1;i<=n;i++){
		if(!G[i].v) cout << ' ' << i;
	}
	cout << endl;
}
int main(){
	while(cin >> n,n){
		for(int i=1;i<=n;i++) G[i].clear();
		while(cin >> v,v){
			while(cin >> x,x) G[v].fr.push_back(x);
		}
		cin >> v;
		for(int i=0;i<v;i++){
			cin >> x;
			dfs();
		}
	}
}
