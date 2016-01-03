/**
	UVa 11455 - Behold my quadrangle
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.012s C++
	O(1) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long x[4];
int main(){
	cin >> n;
	while(n--){
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		sort(x,x+4);
		if( x[0] <= 0 || x[3] >= x[0] + x[1] + x[2] ){
			cout << "banana" << endl;
		}
		else if( x[0] == x[3] ){
			cout << "square" << endl;
		}
		else if( x[0] == x[1] && x[2] == x[3] ){
			cout << "rectangle" << endl;
		}
		else {
			cout << "quadrangle" << endl;
		}
	}
}
