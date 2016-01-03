/**
	UVa 11597 - Spanning Subtree
	by Rico Tiongson
	Submitted: September 21, 2013
	Accepted 0.015s C++
	O(1) time
*/
#include<iostream>
using namespace std;
int n, tc;
int main(){
	while( cin >> n, n ){
		cout << "Case " << ++tc << ": " << (n>>1) << endl;
	}
}
