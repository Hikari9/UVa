/**
	UVa 11192 - Group Reverse
	by Rico Tiongson
	Submitted: May 23, 2013
	Accepted 0.032s C++
	O(n/2) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int i,n;
string s;
int main(){
	while(cin >> n,n){
		cin >> s;
		n = s.length()/n;
		if(s.length()%n>0) n++;
		for(i=n;i<s.length();i+=n) reverse(s.begin()+i-n, s.begin()+i);
		reverse(s.begin()+i-n,s.end());
		cout << s << endl;
	}
}
