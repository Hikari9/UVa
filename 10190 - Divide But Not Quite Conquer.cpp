/**
	UVa 10190 - Divide, But Not Quite Conquer!
	by Rico Tiongson
	Submitted: May 24, 2013
	Accepted 0.012s C++
	O(logbn) time
*/
#include<iostream>
#include<cstdlib>
using namespace std;
long long a,b;
bool dfs(long long x){
	if(a<x) return false;
	else if(x==a){
		cout << x;
		if(x!=1LL) cout << ' ';
		else cout << endl;
		return true;
	}
	else if(dfs(x*b)){
		cout << x;
		if(x!=1LL) cout << ' ';
		else cout << endl;
		return true;
	}
	else return false;
}
int main(){
	while(cin >> a >> b){
		if(a<2LL || b<2LL) cout << "Boring!" << endl;
		else if(!dfs(1LL)) cout << "Boring!" << endl;
	}
}
