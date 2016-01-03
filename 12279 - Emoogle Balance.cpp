/**
	UVa 12279 - Emoogle Balance
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.019s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int main(){
	int n,x,X,r=0;
	while(cin >> n,n){
		X=0;
		for(int i=0;i<n;i++){
			cin >> x;
			if(x) X++;
			else X--;
		}
		cout << "Case " << ++r << ": " << X << endl;
	}
}
