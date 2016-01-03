/**
	UVa 10171 - Meeting Prof. Miguel
	by Rico Tiongson
	Submitted: May 20, 2013
	Accepted 0.009s C++
	O(2(n+m)logn) time
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define INF 10000000
using namespace std;
struct edge{
	int i,w;
	edge(){}
	edge(int i_, int w_): i(i_), w(w_) {}
	bool operator<(const edge& rhs) const{
		return rhs.w < w;
	}
} E;
int n,e,pathY[26],pathM[26],distY[26][26],distM[26][26];
bool v[26];
char a,b,c,d;
template<class arrayType>
void dijkstra(arrayType a, int* G, int Start){
	fill(G,G+26,INF);
	fill(v,v+26,false);
	G[Start] = 0;
	priority_queue<edge> pq;
	pq.push( edge(Start,0) );
	while(!pq.empty()){
		E = pq.top();
		pq.pop();
		if(!v[E.i]){
			v[E.i] = true;
			for(int i=0;i<26;i++){
				if(!v[i] && a[E.i][i]!=INF && G[i] > E.w+a[E.i][i]){
					// cout << "HI" << char(i+'A') << endl;
					G[i] = E.w + a[E.i][i];
					pq.push( edge(i,G[i]) );
				}
			}
		}
	}
}
int main(){
	while(cin >> n,n){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				distY[i][j] = distM[i][j] = INF;
			}
		}
		for(int i=0;i<n;i++){
			cin >> a >> b >> c >> d >> e;
			c-='A';
			d-='A';
			if(a=='Y'){
				distY[c][d] = e;
				if(b=='B') distY[d][c] = e;
			}
			else{
				distM[c][d] = e;
				if(b=='B') distM[d][c] = e;
			}
		}
		cin >> c >> d;
		dijkstra(distY,pathY,c-'A');
		dijkstra(distM,pathM,d-'A');
		e = INF;
		vector<int> q;
		for(int i=0;i<26;i++){
			// cout << pathY[i] << ' ' << pathM[i] << endl;
			if(pathY[i]==INF || pathM[i]==INF) continue;
			pathY[i]+=pathM[i];
			if(pathY[i] < e){
				e = pathY[i];
				q.clear();
				q.push_back(i);
			}
			else if(pathY[i]==e){
				q.push_back(i);
			}
		}
		if(q.empty()) cout << "You will never meet.";
		else{
			cout << e;
			sort(q.begin(),q.end());
			for(int i=0;i<q.size();i++){
				cout << ' ' << char('A'+q[i]);
			}
		}
		cout << endl;
	}
}
