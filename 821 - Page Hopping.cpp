/**
	UVa 821 - Page Hopping
	by Rico Tiongson
	Submitted: May 13, 2013
	Accepted 0.038s C++
	O(logn) Index + O(n^2) time
*/
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define INF 2147483647
using namespace std;
int a,b,iCount,sum,r=0;
struct node{
	int path;
	bool v;
	vector<node*> fr;
	void connect(node& rhs){
		fr.push_back(&rhs);
	}
	void clear(){
		fr.clear();
	}
	void reset(){
		path = INF;
		v = false;
	}
}G[100],*p,*p2;
int bfs(node& Start){
	for(int i=0;i<iCount;i++) G[i].reset();
	int res=0;
	Start.v = true;
	Start.path = 0;
	queue<node*> q;
	q.push(&Start);
	while(!q.empty()){
		p = q.front();
		q.pop();
		res+=p->path;
		for(int i=0;i<p->fr.size();i++){
			p2 = p->fr[i];
			if(!p2->v){
				p2->v = true;
				p2->path = p->path+1;
				q.push(p2);
			}
		}
	}
	return res;
}
map<int,int> Index;
pair<map<int,int>::iterator,bool> Inserter[2];
int main(){
	cout.precision(3);
	cout << fixed;
	while(cin >> a >> b,a||b){
		iCount=0;
		Index.clear();
		do{
			Inserter[0] = Index.insert( pair<int,int>( a, iCount ) );
			if(Inserter[0].second) G[iCount++].clear();
			Inserter[1] = Index.insert( pair<int,int>( b, iCount ) );
			if(Inserter[1].second) G[iCount++].clear();
			G[Inserter[0].first->second].connect(G[Inserter[1].first->second]);
		} while(cin >> a >> b,a||b);
		sum=0;
		for(int i=0;i<iCount;i++) sum+=bfs(G[i]);
		cout << "Case " << ++r << ": average length between pages = " << double(sum)/(iCount*(iCount-1)) << " clicks" << endl;
	}
}
