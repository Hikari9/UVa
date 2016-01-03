/**
	UVa 11849 - CD
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 1.342s C++
	O(2(n+m)-1) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000000], b[1000000], c[1000000];
int main(){
	int n,m;
	while(cin >> n >> m,n||m){
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=0;i<m;i++) cin >> b[i];
		cout << set_intersection(a,a+n,b,b+m,c)-c << endl;
	}
}
