/**
	UVa 11063 - B2-Sequence
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.015s C++
	O(2n^2logn) time
*/
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int b[105], i, j, n, tc, start, end;
bool bad;
set<int> v;
int main(){
	while( cin >> n ){
		v.clear();
		bad = false;
		for( i=0; i<n; ++i ){
			cin >> b[i];
			v.insert( b[i] );
		}
		if( v.size() != n || !equal( v.begin(), v.end(), b ) ){
			bad = true;
			goto end;
		}
		v.clear();
		if( b[0]<1 || b[n-1]>10000 ){
			bad = true;
			goto end;
		}
		for( i=0; i<n; ++i ){
			for( j=i; j<n; ++j ){
				if( !v.insert( b[i]+b[j] ).second ){
					bad = true;
					goto end;
				}
			}
		}
		end:
		cout << "Case #" << ++tc << ": It is ";
		if(bad) cout << "not ";
		cout << "a B2-Sequence.\n" << endl;
	}
}
