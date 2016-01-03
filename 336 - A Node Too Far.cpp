/**
	UVa 336 - A Node Too Far
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.109s C++
	( O(V)bfs + O(nlogn)index ) time
*/
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
using namespace std;
struct node{
	int id,path;
	bool visited;
	vector<node*> frontier;
	void reset(){path=-1;visited=false;}
	node(){}
	node(int _id):id(_id){reset();}
	bool operator<(const node& rhs)const{
		return id<rhs.id;
	}
}*p;
int nc,a,b,r=0;
list<node> s;
list<node>::iterator it,it2;
list<node>::iterator insert(node temp){ //logarithmic insert
	list<node>::iterator It = lower_bound(s.begin(),s.end(),temp);
	if(It==s.end()) It = s.insert(It,temp);
	else if(It->id!=temp.id) It = s.insert(It,temp);
	return It;
}
void bfs(){
	for(it=s.begin();it!=s.end();it++) it->reset();
	it = lower_bound(s.begin(),s.end(),a);
	it->path=0;
	it->visited=true;
	queue<node*> q;
	q.push(&*it);
	int c=1;
	while(!q.empty()){
		p = q.front();
		q.pop();
		if(p->path<b){
			for(int i=0;i<p->frontier.size();i++){
				if(!p->frontier[i]->visited){
					p->frontier[i]->visited=true;
					p->frontier[i]->path = p->path+1;
					c++;
					q.push(p->frontier[i]);
				}
			}
		}
	}
	cout << s.size()-c << " nodes not reachable from node " << a << " with TTL = " << b << '.' << endl;
}
void Connect(node* lhs, node* rhs){
	lhs->frontier.push_back(rhs);
	rhs->frontier.push_back(lhs);
}
int main(){
	while(cin >> nc,nc){
		s.clear();
		for(int i=0;i<nc;i++){
			cin >> a >> b;
			it = insert(a);
			it2 = insert(b);
			Connect(&(*it),&(*it2));
		}
		while(cin >> a >> b,a||b){
			cout << "Case " << ++r << ": ";
			bfs();
		}
	}
}
