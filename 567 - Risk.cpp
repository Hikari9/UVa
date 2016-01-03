/**
	UVa 567 - Risk
	by Rico Tiongson
	Submitted: May 2, 2013
	Accepted 0.542s C++
	O(n) time
*/
#include<iostream>
#include<queue>
using namespace std;
int n,x,a,b,r=0;
struct node{
	int path;
	bool visited;
	vector<node*> frontier;
	void reset(){
		visited=false;
		path=-1;
	}
	void clear(){
		frontier.clear();
	}
} G[21],*p,*p2;
int bfs(){
	queue<node*> q;
	q.push(&G[a]);
	G[a].visited = true;
	G[a].path=0;
	while(!q.empty()){
		p = q.front();
		for(int i=0;i<p->frontier.size();i++){
			p2=p->frontier[i];
			if(!p2->visited){
				if(p2==&G[b]) return p->path+1;
				p2->visited=true;
				p2->path = p->path+1;
				q.push(p2);
			}
		}
		q.pop();
	}
	return -1;
}
int main(){
	while(cin >> n){
		cout << "Test Set #" << ++r << endl;
		for(int i=1;i<21;i++) G[i].clear();
		for(int j=0;j<n;j++){
			cin >> x;
			G[1].frontier.push_back(&G[x]);
			G[x].frontier.push_back(&G[1]);
		}
		for(int i=2;i<20;i++){
			cin >> n;
			for(int j=0;j<n;j++){
				cin >> x;
				G[i].frontier.push_back(&G[x]);
				G[x].frontier.push_back(&G[i]);
			}
		}
		cin >> n;
		while(n--){
			cin >> a >> b;
			for(int i=1;i<21;i++) G[i].reset();
			if(a<10) cout << ' ';
			cout << a << " to ";
			if(b<10) cout << ' ';
			cout << b << ": " << bfs() << endl;
		}
		cout << endl;
	}
}
