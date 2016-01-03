/**
	UVa 10684 - The jackpot
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.192s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int x[10001],n,k;
int kadane(){
	int mx=x[0], mxend = x[0];
	for(int i=1;i<n;i++){
		if(mxend<0) mxend = x[i];
		else mxend += x[i];
		if(mxend>mx){
			mx = mxend;
		}
	}
	return mx;
}
int main(){
	while(cin >> n,n){
		for(int i=0;i<n;i++) cin >> x[i];
		k = kadane();
		if(k>0) cout << "The maximum winning streak is " << k << '.' << endl;
		else cout << "Losing streak." << endl;
	}
}
