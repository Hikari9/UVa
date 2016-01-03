/**
	UVa 11078 - Open Credit System
	by Rico Tiongson
	Submitted: May 9, 2013
	Accepted 0.276s C++
	O(n) time
*/
#include<iostream>
#define nINF -2147483647
using namespace std;
int main(){
	int t,n,x[100001],mx,mn,MAX;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> x[0];
		mn = mx = x[0];
		for(int i=1;i<n;i++) cin >> x[i];
		int MAX = nINF;
		for(int i=1;i<n;i++){
			MAX = max(MAX, max(mx-x[i],mn-x[i]));
			mx = max(x[i],mx);
			mn = min(x[i],mn);
		}
		cout << MAX << endl;
	}
}
