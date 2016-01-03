/**
	UVa 12372 - Packing for Holiday
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.016s C++
	O(3) time
*/
#include<iostream>
using namespace std;
int main(){
	int t,a,x;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> a;
		x = a;
		cin >> a;
		x = max(x,a);
		cin >> a;
		x = max(x,a);
		cout << "Case " << i << ": ";
		if(x>20) cout << "bad" << endl;
		else cout << "good" << endl;
	}
}
