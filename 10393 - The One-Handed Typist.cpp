/**
	UVa 10393 - The One-Handed Typist
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.016s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
#include<set>
using namespace std;
map<char,int> m;
set<string> ans;
set<string>::iterator it;
int F,N,x;
string s;
bool f[11],ok;
int main(){
	f[0] = false;
	m['q'] = m['a'] = m['z'] = 1;
	m['w'] = m['s'] = m['x'] = 2;
	m['e'] = m['d'] = m['c'] = 3;
	m['r'] = m['f'] = m['v'] = m['t'] = m['g'] = m['b'] = 4;
	m[' '] = 5; //only consider 5
	m['y'] = m['h'] = m['n'] = m['u'] = m['j'] = m['m'] = 7;
	m['i'] = m['k'] = m[','] = 8;
	m['o'] = m['l'] = m['.'] = 9;
	m['p'] = m[';'] = m['/'] = 10;
	while(cin >> F >> N){
		for(int i=1;i<11;i++) f[i] = true;
		while(F--){
			cin >> x;
			f[x] = false;
		}
		if(!f[5] && f[6]) //switch to 5 for access
			f[5] = true;
		cin.ignore();
		ans.clear();
		x=0;
		while(N--){
			cin >> s;
			ok = true;
			for(int i=0;i<s.length();i++){
				if(!f[m[s[i]]]){
					ok = false;
					break;
				}
			}
			if(ok){
				if(x<s.length()){
					x = s.length();
					ans.clear();
				}
				if(x==s.length()) ans.insert(s);
			}
		}
		cout << ans.size() << endl;
		for(it=ans.begin();it!=ans.end();it++) cout << *it << endl;
	}
}
