/**
	UVa 10642 - Can You Solve It?
	by Rico Tiongson
	Submitted: Feb 3, 2014
	Accepted 0.019s C++
	O(1) time
*/
#include <iostream>
using namespace std;
typedef long long lag;

lag steps( int y, int x ){
	lag b = x + y;
	lag off = b * (b+1) / 2;
	return off + y;
}

int n, a, b, c, d;

int main(){
	cin >> n;
	
	for( int i=1; i<=n; ++i ){
		cin >> a >> b >> c >> d;
		cout << "Case " << i <<": ";
		cout << steps(c, d) - steps(a, b) << endl;
	}
}
