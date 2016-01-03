/**
	UVa 11059 - Maximum Product
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.016s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int main(){
	int n,r=0;
	long long x[18],mx,temp;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> x[i];
		mx = 0;
		for(int i=0;i<n;i++){
			temp = 1;
			for(int j=i;j<n;j++){
				temp*=x[j];
				mx = max(temp,mx);
			}
		}
		cout << "Case #" << ++r << ": The maximum product is " << mx << '.' << endl << endl;
	}
}
