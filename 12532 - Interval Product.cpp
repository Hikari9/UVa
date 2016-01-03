/**
	UVa 12532 - Interval Product
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.758s C++
	O(2^((log(n)+1)+1)) time
*/
#include<iostream>
using namespace std;
int n,q,x[100005],tree[400005],a,b;
char c;
void _makeTree(int node, int lo, int hi) {
	if(lo == hi){
		tree[node] = x[lo];
		return;
	}
	int mid = (lo+hi)/2;
	_makeTree(2*node, lo, mid);
	_makeTree(2*node + 1, mid + 1, hi);
	tree[node] = tree[2*node] * tree[2*node+1];
}
void makeTree(){
	int n4=n*4;
	for(int i=0;i<=n4;i++) tree[i]=1;
	_makeTree(1,0,n-1);
}
int _query(int node, int lo, int hi, int i, int j) {
	if(hi < i || lo > j) return 1;
	if(lo >= i && hi <= j) return tree[node];
	int mid = (lo + hi) / 2;
	return _query(2*node, lo, mid, i, j) * _query(2*node+1, mid + 1, hi, i, j);
}
int query(int i, int j) {
	return _query(1, 0, n - 1, i, j);
} 
void _update(int node, int ind, int val, int lo, int hi) {
	if(ind < lo || ind > hi) return;
	if(lo == hi) {
		tree[node] = val;
		return;
	}
	int mid = (lo + hi) / 2;
	_update(2*node, ind, val, lo, mid);
	_update(2*node + 1, ind, val, mid + 1, hi);
	tree[node] = tree[2*node] * tree[2*node+1];
}
void update(int ind, int val) {
	_update(1, ind, val, 0, n - 1);
}
int main() {
   while(cin >> n >> q) {
      for(int i = 0; i < n; ++i) {
         cin >> x[i];
         if(x[i]>0) x[i] = 1;
         if(x[i]<0) x[i] = -1;
      }
      makeTree();
      while(q--) {
         cin >> c >> a >> b;
         if(c == 'C') {
            if(b > 0) b = 1;
            if(b < 0) b = -1;
            update(--a, b);
            x[a] = b;
         }
		 else {
			switch(query(--a,--b)){
				case -1: cout.put('-'); break;
				case 1: cout.put('+'); break;
				case 0: cout.put('0');
			}
         }
      }
      cout << endl;
   }
}
