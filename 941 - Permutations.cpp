/**
	UVa 941 - Permutations
	by Rico Tiongson
	Submitted: July 2, 2013
	Accepted 0.226s C++
	O(nlogn) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
long long n, sz, f[21], c;
int i, j, t, d;
string s, b, ans;
void permutate(){
	ans.clear();
	while( n ){
		i = n/f[ s.size()-1 ];
		// retrieve char at position
		ans += s[i];
		s.erase( i, 1 );
		n %= f[ s.size() ];
		// cout << ans << ' ' << s << endl;
	}
}
int main(){
	f[0] = 1ll;
	for( i=1; i<21; ++i )
		f[i] = f[i-1]*i;
	cin >> t;
	while( t ){
		--t;
		cin >> s >> n;
		sort( s.begin(), s.end() );
		permutate();
		cout << ans << s << endl;
	}
}
