/**
	UVa 10518 - How Many Calls?
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.026s C++
	O(?) time
*/
#include<iostream>
#include<vector>
#define mx 10001
using namespace std;
long long n;
int b, tc;
vector<int> f[mx];
int main(){
	while( cin >> n >> b, n || b ){
		if( b<2 ){
			cout << "Case " << ++tc << ": " << n << ' ' << b << " 0" << endl;
			continue;
		}
		if( f[b].empty() ){
			// start bottom-up
			f[b].push_back( 1 );
			f[b].push_back( 1 );
			do{
				f[b].push_back( f[b].back() + f[b][f[b].size()-2] + 1 );
				f[b].back() %= b;
			} while( f[b].back()!=1 || f[b][f[b].size()-2]!=1 ); // get cycle
			f[b].pop_back();
			f[b].pop_back();
		}
		cout << "Case " << ++tc << ": " << n << ' ' << b << ' ' << f[b][n%f[b].size()] << endl;
	}
}
