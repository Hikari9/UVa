/**
	UVa 700 - Date Bugs
	by Rico Tiongson
	Submitted: August 20, 2013
	Accepted 0.019s C++
	O(n^2) time
*/
#include<iostream>
using namespace std;
int n, i, tc, mx;
int y[21], a[21], b[21], x[21];
bool found;
int main(){
	while( cin >> n, n ){
		mx = 0;
		for( i=0; i<n; ++i ){
			cin >> y[i] >> a[i] >> b[i];
			mx = max(a[i],mx);
		}
		cout << "Case #" << ++tc << ":\n";
		while( mx<10000 ){
			for( i=0; i<n; ++i ){
				x[i] = (mx-a[i])%(b[i]-a[i])+a[i];
			}
			found = true;
			for( i=0; i<n; ++i ){
				if( y[i]!=x[i] ){
					found = false;
					break;
				}
			}
			if(found) break;
			++mx;
		}
		if(found)
			cout << "The actual year is " << mx << ".\n" << endl;
		else
			cout << "Unknown bugs detected.\n" << endl;
	}
}
