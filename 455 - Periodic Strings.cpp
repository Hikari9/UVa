/**
	UVa 455 - Periodic Strings
	by Rico Tiongson
	Submitted: May 20, 2013
	Accepted 0.015s C++
	O(logn) time
*/
#include<iostream>
using namespace std;
int n;
bool f(false);
string s;
bool ok(unsigned l){
	string cmp = s.substr(0,l);
	for(unsigned i=l;i<s.size();i+=l){
		if(cmp!=s.substr(i,l)) return false;
	}
	return true;
}
unsigned period(){
	for(unsigned i=1,len=s.size()/2+1;i<len;i++){
		if(s.size()%i==0 && ok(i)) return i;
	}
	return s.size();
}
int main(){
	cin >> n;
	while(n--){
		if(f) cout << endl;
		else f = true;
		cin >> s;
		cout << period() << endl;
	}
}
