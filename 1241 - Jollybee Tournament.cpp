/**
	UVa 1241 - Jollybee Tournament
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.019s C++
	O(2^n) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int t, n, m, i, x, ans;
int a[1025], temp[1025], lim;
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		lim = (1<<n);
		ans = 0;
		memset( a, 0, sizeof a );
		while(m--){
			cin >> x;
			a[x-1] = 1;
		}
		while(n--){
			memset( temp, 0, sizeof temp );
			lim >>= 1;
			for( i=0; i<lim; ++i ){
				if( a[i<<1] ^ a[(i<<1)+1] ) ++ans;
				temp[i] = ( a[i<<1] & a[(i<<1)+1] );
			}
			memcpy( a, temp, sizeof a );
		}
		cout << ans << endl;
	}
}
