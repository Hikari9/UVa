/**
	UVa 599 - The Forrest for the Trees
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.858s C++
	O(logn) time
*/
#include<iostream>
#include<map>
using namespace std;
int f[26],t,a,b;
int find(int x){
	return f[x]==x ? x : f[x] = find(f[x]);
}
int main(){
	string c;
	map<int,int> m;
	map<int,int>::iterator it;
	cin >> t;
	while(t--){
		for(int i=0;i<26;i++) f[i] = i;
		m.clear();
		while(true){
			cin >> c;
			if(c[0]=='*') break;
			f[find(c[1]-'A')] = find(c[3]-'A');
		}
		cin >> c;
		for(int i=0;i<c.size();i+=2) m[find(c[i]-'A')]++;
		a = b = 0;
		for(it = m.begin(); it!=m.end();it++){
			if(it->second>1) a++;
			else b++;
		}
		cout << "There are " << a << " tree(s) and " << b << " acorn(s)." << endl;
	}
}
