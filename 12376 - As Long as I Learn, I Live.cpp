/**
	UVa 12376 - As Long as I Learn, I Live
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.136s C++
	O(n) time
*/
#include<iostream>
#include<cstring>
using namespace std;
int t, tc;
int n, m, l[105], i, u, v, current, ans, mx, mxi;
bool adj[105][105];
void maxpath(){
	current = ans = 0;
	while(true){
		mx = 0;
		mxi = -1;
		for( i=0; i<n; ++i ){
			if( adj[current][i] ){
				if( mx < l[i] ){
					mx = l[i];
					mxi = i;
				}
			}
		}
		ans += mx;
		if( mxi==-1 ) break;
		current = mxi;
	}
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		memset( adj, 0, sizeof adj );
		for( i=0; i<n; ++i ){
			cin >> l[i];
		}
		for( i=0; i<m; ++i ){
			cin >> u >> v;
			adj[u][v] = 1;
		}
		
		maxpath();
		cout << "Case " << ++tc << ": ";
		cout << ans << " " << current << endl;
	}
}

