/**
	UVa 1174 - IP-TV
	by Rico Tiongson
	Submitted: May 12, 2013
	Accepted 0.119s C++
	O(nlogn) time
*/
#include<iostream>
#include<queue>
#include<map>
using namespace std;
struct edge{
	int i,j,w;
	edge(){}
	edge(int a, int b, int c): i(a), j(b), w(c) {}
	bool operator< (const edge& rhs) const{ return rhs.w < w; }
} E;
int f[2005],t,m,n,iCount,Cost,a,b;
map<string,int> Index;
pair<map<string,int>::iterator,bool> it1,it2;
priority_queue<edge> pq;
int find(int x){
	return f[x]==-1?x:f[x]=find(f[x]);
}
int kruskals(){
	Cost = 0;
	m--;
	while(m){
		E = pq.top();
		pq.pop();
		a = find(E.i);
		b = find(E.j);
		if(a!=b){
			f[a]=b;
			Cost+=E.w;
			m--;
		}
	}
	return Cost;
}
int main(){
	cin >> t;
	char in[2][10];
	while(t--){
		cin >> m >> n;
		iCount=0;
		Index.clear();
		while(!pq.empty()) pq.pop();
		for(int i=0;i<m;i++) f[i]=-1;
		while(n--){
			cin >> in[0] >> in[1] >> Cost;
			it1 = Index.insert( pair<string,int>(in[0],iCount) );
			if(it1.second) iCount++;
			it2 = Index.insert( pair<string,int>(in[1],iCount) );
			if(it2.second) iCount++;
			pq.push( edge( it1.first->second, it2.first->second, Cost ) );
		}
		cout << kruskals() << endl;
		if(t) cout << endl;
	}
}
