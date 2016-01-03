/**
	UVa 497 - Strategic Defense Initiative
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.019s C++
	O(n^2) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int t, x, i, j, mx, mxi;
char c, buf[10000];
vector<int> v, prev, dp;
void getPrev( int x ){
	if(x==-1) return;
	getPrev(prev[x]);
	cout << v[x] << endl;
}
int main(){
	gets(buf);
	sscanf( buf, "%d", &t );
	gets(buf);
	while(t--){
		v.clear();
		while( gets(buf) && buf[0] ){
			sscanf( buf, "%d", &x );
			v.push_back(x);
		}
		prev.assign( v.size(), -1 );
		dp.assign( v.size(), -1 );
		for( i=0; i<v.size(); ++i ){
			if( dp[i]==-1 ) dp[i] = 1;
			for( j=i+1; j<v.size(); ++j ){
				if( v[i] < v[j] ){
					if( dp[j] < dp[i]+1 ){
						dp[j] = dp[i]+1;
						prev[j] = i;
					}
				}
			}
		}
		mx = 0;
		mxi = 0;
		for( i=0; i<v.size(); ++i ){
			if( mx < dp[i] ){
				mx = dp[i];
				mxi = i;
			}
		}
		cout << "Max hits: " << mx << endl;
		if( mx ) getPrev(mxi);
		if(t) cout << endl;
	}
}
