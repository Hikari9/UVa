/**
	UVa 423 - MPI Maelstrom
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted: 0.016s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#define INF 2147483647
using namespace std;
struct node{
	vector<pair<node*,int> > frontier;
	bool v,isIn;
	int path;
	list<node*>::iterator it;
	node():
		v(false), isIn(false), path(INF) {}
} G[100], *p;
int n,a;
char c[15];
bool cmp(const node* lhs, const node* rhs){
	return lhs->path < rhs->path;
}
int dikjstra(){
	list<node*> l;
	pair<node*,int>* Pr;
	G->path = 0;
	l.push_back(G);
	while(!l.empty()){
		p = l.front();
		l.pop_front();
		p->v = true;
		for(int i=0; i<p->frontier.size(); i++){
			Pr = &p->frontier[i];
			if(!Pr->first->v && p->path + Pr->second < Pr->first->path){
				Pr->first->path = p->path + Pr->second;
				if(Pr->first->isIn) l.erase(Pr->first->it); //reinsert
				else Pr->first->isIn = true;
				Pr->first->it = l.insert(lower_bound(l.begin(),l.end(),Pr->first,cmp),Pr->first);
			}
		}
	}
	int mx=0;
	for(int i=1;i<n;i++) mx = max(mx,G[i].path);
	return mx;
}
int main(){
	cin >> n;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			cin >> c;
			if(c[0]!='x'){
				a = atoi(c);
				G[i].frontier.push_back(pair<node*,int>(&G[j],a));
				G[j].frontier.push_back(pair<node*,int>(&G[i],a));
			}
		}
	}
	cout << dikjstra() << endl;
}
