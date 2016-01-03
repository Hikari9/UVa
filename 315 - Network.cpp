/**
	UVa 315 - Network
	by Rico Tiongson
	Submitted: May 27, 2013
	Accepted 0.132s C++
	O(n^2) time
*/
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;
int n,k,x;
bool b[105][105],v[105],ok;
string s;
void dfs(int c){
	v[c] = true;
	for(int i=1;i<k;i++){
		if(b[c][i] && !v[i]) dfs(i);
	}
	for(int i=k+1;i<=n;i++){
		if(b[c][i] && !v[i]) dfs(i);
	}
}
bool critical(int c){
	for(int i=1;i<c;i++){
		if(!v[i]) return true;
	}
	for(int i=c+1;i<=n;i++){
		if(!v[i]) return true;
	}
	return false;
}
int articulate(){
	if(n==1) return 0;
	for(int i=1;i<=n;i++) v[i] = false;
	k=1;
	dfs(2);
	int ans = critical(1);
	for(k=2;k<=n;k++){
		for(int i=1;i<=n;i++) v[i] = false;
		dfs(1);
		if(critical(k)) ans++;
	}
	return ans;
}
int main(){
	while(cin >> n,n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) b[i][j] = false;
		}
		while(cin >> k,k){
			getline(cin,s);
			istringstream buf(s);
			while(buf >> x){
				if(k!=x) b[k][x] = b[x][k] = true;
			}
		}
		cout << articulate() << endl;
	}
}
