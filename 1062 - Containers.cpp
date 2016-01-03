/**
	UVa 1062 - Containers
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.016s C++
	O(n^2) time
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
	int r=0;
	string s;
	vector<stack<char> > v;
	while(cin >> s,s[0]!='e'){
		v.clear();
		v.push_back(stack<char>());
		v[0].push(s[0]);
		for(int i=1;i<s.size();i++){
			//find stack
			int mn=30, mni;
			//first:distance second:index
			for(int j=0;j<v.size();j++){
				if(v[j].top()>=s[i] && mn > v[j].top()-s[i]){
					mn = v[j].top()-s[i];
					mni = j;
				}
			}
			if(mn==30){
				//new stack
				v.push_back(stack<char>());
				v.back().push(s[i]);
			}
			else{
				v[mni].push(s[i]);
			}
		}
		cout << "Case " << ++r << ": " << v.size() << endl;
	}
}
