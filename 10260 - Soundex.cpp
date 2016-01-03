/**
	UVa 10260 - Soundex
	by Rico Tiongson
	Submtited: May 23, 2013
	Accepted 0.039s C++
	O(n) time
*/
#include<iostream>
using namespace std;
string s;
char x[] = "01230120022455012623010202";
int main(){
	while(cin >> s){
		//start
		for(int i=0;i<s.length();i++) s[i]-='A';
		if(x[s[0]]!='0') cout << x[s[0]];
		for(int i=1;i<s.length();i++){
			if(x[s[i]]!='0' && x[s[i]]!=x[s[i-1]]) cout << x[s[i]];
		}
		cout << endl;
	}
}
