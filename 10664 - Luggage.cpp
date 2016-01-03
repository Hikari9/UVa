/**
	UVa 10664 - Luggage
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.012s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
#include<sstream>
using namespace std;
int m, n[25], sz, i, j, total, mx;
bool ok[25][105];
string line;
int main(){
	// initialize containers
	cin >> m;
	cin.ignore();
	while( m-- ){
		getline( cin, line );
		istringstream buf(line);
		total = 0;
		n[0] = 0; // for empty line
		for( sz=0; buf>>n[sz]; ++sz ) total+=n[sz];
		if( total&1 ){
			cout << "NO" << endl;
			continue;
		}
		memset( ok, 0, sizeof ok );
		ok[0][ n[0] ] = true;
		mx = total/2;
		for( i=1; i<sz; ++i ){
			for( j=0; j<n[i]; ++j ) ok[i][j] = ok[i-1][j];
			for( ; j<=mx; ++j )
				ok[i][j] = (ok[i-1][j]||ok[i-1][j-n[i]]);
		}
		cout << ( ok[sz-1][mx] ? "YES" : "NO" ) << endl;
	}
}
