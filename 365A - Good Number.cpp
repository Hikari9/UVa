/**
	CodeForces 365A - Good Number
	by Rico Tiongson
	Submitted: November 22, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include <iostream>
#include <cstring>
using namespace std;
int n, k, cnt;
string a;
bool dig[10];
int main(){
	cin >> n >> k;
	for( int i=0; i<n; ++i ){
		cin >> a;
		cnt++;
		memset( dig, 0, sizeof dig );
		for( int i=0; i<a.length(); ++i ){
			if( '0' <= a[i] && a[i] <= '9' ){
				dig[a[i] - '0'] = true;
			}
		}
		for( int i=0; i<=k; ++i ){
			if( !dig[i] ){
				cnt--;
				break;
			}
		}
	}
	cout << cnt << endl;
}
