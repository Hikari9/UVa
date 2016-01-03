/**
	UVa 12160 - Unlock the Lock
	by Rico Tiongson
	Submitted: May 13, 2013
	Accepted 0.025s C++
	O(n<=10000) time
*/
#include<iostream>
#include<queue>
using namespace std;
int t=0,L,U,R,l[10000],r[10],x;
int bfs(){
	if(L==U) return l[L]=0;
	for(int i=0;i<10000;i++) l[i]=-1;
	l[L] = 0;
	queue<int> q;
	q.push(L);
	while(!q.empty()){
		L = q.front();
		q.pop();
		for(int i=0;i<R;i++){
			x = L+r[i];
			if(x>9999) x-=10000;
			if(l[x]==-1){
				l[x] = l[L]+1;
				if(x==U) return l[U];
				q.push(x);
			}
		}
	}
	return -1;
}
int main(){
	while(cin >> L >> U >> R,L||U||R){
		for(int i=0;i<R;i++) cin >> r[i];
		cout << "Case " << ++t << ": ";
		if(bfs()==-1) cout << "Permanently Locked" << endl;
		else cout << l[U] << endl;
	}
}
