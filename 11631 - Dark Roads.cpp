/**
	UVa 11631 - Dark Roads
	by Rico Tiongson
	Submitted: May 1, 2013
	Accepted 0.782s C++
	O(logn) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int f[200015],m,sum;
int find(const int& x){
	return f[x]==x?x:f[x]=find(f[x]);
}
struct node{
	int x,y,w;
	node():x(0),y(0),w(0){}
	void in(){cin>>x>>y>>w;sum+=w;}
	bool operator<(const node& rhs)const{
		return w<rhs.w;
	}
} l[200015];
int main(){
	int n,a,b,i,d;
	while(cin >> m >> n,m||n){
		for(i=0;i<m;i++) f[i]=i;
		sum=0;
		for(d=0;d<n;d++) l[d].in();
		sort(l,l+n);
		d=0;
		for(i=m;d<n&&i>1;d++){
			a = find(l[d].x);
			b = find(l[d].y);
			if(a!=b){
				f[a] = b;
				sum-=l[d].w;
				i--;
			}
		}
		cout << sum << endl;
	}
}
