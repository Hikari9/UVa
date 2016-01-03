/**
	UVa 10222 - Decode the Mad man
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted: 0.009s C++
	O(n) time
*/
#include<iostream>
#include<cctype>
using namespace std;
int main(){
	string d("`1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./"),s;
	int find;
	while(getline(cin,s)){
		for(int i=0;i<s.length();i++){
			find = d.find(tolower(s[i]));
			if(find>=d.length()) cout.put(s[i]);
			else cout.put(d[find-2]);
		}
		cout << endl;
	}
}
