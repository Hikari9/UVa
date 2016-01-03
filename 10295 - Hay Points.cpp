/**
	UVa 10295 - Hay Points
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.012s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
int main(){
	long M, N, x;
	string s;
	map<string,long> m;
	map<string,long>::iterator it;
	cin >> M >> N;
	while(M--){
		cin >> s >> x;
		m[s] = x;
	}
	while(cin >> s){
		x = 0;
		if(s[0]!='.'){
			do{
				it = m.find(s);
				if(it!=m.end()) x+=it->second;
			} while(cin >> s,s[0]!='.');
		}
		cout << x << endl;
	}
}
