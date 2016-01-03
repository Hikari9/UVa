/**
	UVa 696 - How Many Knights
	by Rico Tiongson
	Submitted: November 2, 2013
	Accepted 0.159s C++
	O(1) time
*/
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int ans, n, m;

int main(){
	while( cin >> n >> m, n || m ){
		if( n <= 1 || m <= 1 )
			ans = n * m;
	
		else if( n > 2 && m > 2 )
			ans = ((n*m) >> 1) + ((n*m)&1);
			
		else if( n == 2 ){
			int div = m / 4;
			int mod = m % 4;
			ans = div * 4;
			if( mod >= 2 ) ans += 4;
			else if( mod == 1 ) ans += 2;
		}
		
		else if( m == 2 ){
			int div = n / 4;
			int mod = n % 4;
			ans = div * 4;
			if( mod >= 2 ) ans += 4;
			else if( mod == 1 ) ans += 2;
		}
		
		cout << ans << " knights may be placed on a " << n << " row " << m << " column board." << endl;
	}
}
