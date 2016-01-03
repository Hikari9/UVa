/**
	UVa 343 - What Base Is This?
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.029s C++
	O(36) time
*/
#include<iostream>
#include<map>
#include<cctype>
using namespace std;
typedef unsigned long long lag;
string a,b;
char maxBase;
lag base[37],temp;
map<lag,int> m;
map<lag,int>::iterator it;
lag toDec(const string& s,int Base){
	lag res = 0uLL;
	for(int i=0;i<s.length();i++){
		res *= Base;
		if(isdigit(s[i])) res += s[i]-'0';
		else res += s[i]-'7'; //offset+10
	}
	return res;
}
void minimize(int& ref, int Base){
	if(!ref || Base<ref) ref = Base;
}
bool found(){
	for(int i=maxBase;i<37;i++){
		it = m.find(base[i]);
		if(it!=m.end()){
			cout << a << " (base " << i << ") = " << b << " (base " << it->second << ')' << endl;
			return true;
		}
	}
	return false;
}
int main(){
	while(cin >> a >> b){
		m.clear();
		maxBase='1';
		for(int i=0;i<b.length();i++) maxBase = max(maxBase,b[i]);
		if(isdigit(maxBase)) maxBase-='/';
		else maxBase-='6';
		for(int i=maxBase;i<37;i++) minimize( m[toDec(b,i)], i );
		maxBase='1';
		for(int i=0;i<a.length();i++) maxBase = max(maxBase,a[i]);
		if(isdigit(maxBase)) maxBase-='/';
		else maxBase-='6';
		for(int i=maxBase;i<37;i++) base[i] = toDec(a,i);
		if( !found() ) cout << a << " is not equal to " << b << " in any base 2..36" << endl;
	}
}
