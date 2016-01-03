/**
	UVa 908 - Re-connecting Computer Sites
	by Rico Tiongson
	Submitted: May 1, 2013
	Accepted 0.019s C++
	O(2logn) time
*/
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> f(1000009);
int find(int x){
	return f[x]==-1?x:f[x]=find(f[x]);
}
struct node{
	int x,y,w;
	node(){cin>>x>>y>>w;}
	bool operator<(const node& rhs)const{
		return w>rhs.w;
	}
};
int main(){
	int n,m,k,a,b,c,sum;
	bool fir=true;
	while(cin >> n){
		if(fir) fir=false;
		else cout << endl;
		fill(f.begin(),f.begin()+n+1,-1);
		sum=0;
		for(int i=1;i<n;i++){
			cin >> a >> b >> c;
			sum+=c;
		}
		cout << sum << endl;
		priority_queue<node> pq;
		cin >> k;
		while(k--) pq.push(node());
		cin >> m;
		for(int i=0;i<m;i++) pq.push(node());
		sum=0;
		while(n>1 && !pq.empty()){
			a = find(pq.top().x);
			b = find(pq.top().y);
			if(a!=b){
				n--;
				f[a]=b;
				sum+=pq.top().w;
			}
			pq.pop();
		}
		cout << sum << endl;
	}
}
