/**
	UVa 990 - Diving for Gold
	by Rico Tiongson
	Submitted: October 21, 2013
	Accepted 0.022s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int t, w, n;
int d[35], v[35];
int dp[35][1005];
vector<int> treasures;
void recover( int i, int dep ){
	if( dep <= 0 ) return;
	if( dp[dep][i] == dp[dep-1][i] ){
		recover(i, dep-1);
	}
	else{
		treasures.push_back(dep);
		recover(i - 3*w*d[dep], dep-1);
	}
}
int main(){
	bool first = true;
	while( cin >> t >> w ){
		if(first) first = false;
		else cout << endl;
		cin >> n;
		for( int i=1; i<=n; ++i ){
			cin >> d[i] >> v[i];
		}
		memset( dp[0], 0, sizeof dp[0] );
		for( int i=1; i<=n; ++i ){
			int lim = min( 3*w*d[i], t + 1 );
			for( int j=0; j<lim; ++j ){
				dp[i][j] = dp[i-1][j];
			}
			for( int j=lim; j<=t; ++j ){
				dp[i][j] = max( dp[i-1][j], dp[i-1][j-lim] + v[i] );
			}
		}
		int mxi = 0;
		for( int j=1; j<=t; ++j ){
			if( dp[n][j] > dp[n][mxi] ){
				mxi = j;
			}
		}
		treasures.clear();
		recover(mxi, n);
		cout << dp[n][mxi] << endl;
		cout << treasures.size() << endl;
		for( int i=treasures.size()-1; i>=0; --i ){
			int j = treasures[i];
			cout << d[j] << " " << v[j] << endl;
		}
	}
}
