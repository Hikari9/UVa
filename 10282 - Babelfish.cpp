/**
	UVa 10282 - Babelfish
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.922s C++
	O(logn) time
*/
#include<iostream>
#include<map>
using namespace std;
int main(){
	string e,f;
	map<string,string> m;
	map<string,string>::iterator it;
	while(cin >> e >> f){
		m[f] = e;
		if(cin.ignore().peek()=='\n') break;
	}
	while(cin >> f){
		it = m.find(f);
		if(it==m.end()) cout << "eh" << endl;
		else cout << it->second << endl;
	}
}
