/**
	UVa 459 - Graph Connectivity
	by Rico Tiongson
	Submitted: May 1, 2013
	Accepted 0.012s C++
	O(logn) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int f[26],c;
int find(int x){
	return f[x]==-1?x:f[x]=find(f[x]);
}
int count(){
	int res=0;
	for(int i=0;i<c;i++){
		if(f[i]==-1) res++;
	}
	return res;
}
int main(){
	int t,a,b;
	char d[3];
	cin >> t;
	cin.get();
	cin.get();
	while(t--){
		c = cin.get()-64;
		cin.get();
		fill(f,f+c,-1);
		while(cin.getline(d,3),d[0]!='\0'){
			a=find(d[0]-'A');
			b=find(d[1]-'A');
			if(a!=b) f[a]=b;
		}
		cout << count() << endl;
		if(t) cout << endl;
	}
}
