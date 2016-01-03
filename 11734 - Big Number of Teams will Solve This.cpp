/**
	UVa 11734 - Big Number of Teams will Solve This
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.016s C++
	O(2n) time
*/
#include<iostream>
using namespace std;
int t;
string s,s2;
string trim(const string& S){
	string buf;
	for(int i=0;i<S.length();i++){
		if(S[i]!=' ') buf.push_back(S[i]);
	}
	return buf;
}
int main(){
	cin >> t;
	cin.ignore();
	for(int i=1;i<=t;i++){
		getline(cin,s);
		getline(cin,s2);
		cout << "Case " << i << ": ";
		if(s==s2) cout << "Yes" << endl;
		else if(trim(s)==s2) cout << "Output Format Error" << endl;
		else cout << "Wrong Answer" << endl;
	}
}
