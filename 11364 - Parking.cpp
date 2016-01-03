/**
	UVa 11364 - Parking
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.012s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int main(){
	int t,n,x[20],mx,mn;
	cin >> t;
	while(t--){
		cin >> n;
		mx = -1;
		mn = 100;
		for(int i=0;i<n;i++){
			cin >> x[i];
			if(x[i]<mn) mn = x[i];
			if(x[i]>mx) mx = x[i];
		}
		cout << 2*(mx-mn) << endl;
	}
}
