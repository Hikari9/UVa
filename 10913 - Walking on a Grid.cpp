/**
	UVa 10913 - Walking on a Grid
	by Rico Tiongson
	Submitted: August 28, 2013
	Accepted 0.049s C++
	O(n^3) time
*/
#include<iostream>
#include<cstring>
#define MX 80
#define MXK 7
#define INF 1000000000
using namespace std;
int tc, N, K, ans;
int g[MX][MX];
int dp[MX][MX][MXK];
bool used[MX][MX][MXK];

inline bool inRange( int x, int y ){
	return x>0 && y>0 && x<=N && y<=N;
}

int top_down( int i, int j , int k ){
	// cout << i << " " << j << " " << k << endl;
	// if( !inRange(i,j) ) return -INF;

	if( used[i][j][k] ) return dp[i][j][k];
	used[i][j][k] = true;
	dp[i][j][k] = -INF;
	int sum;
	int negs;
	int ans, jj;
	
	if( i==1 ){
		sum = 0;
		negs = k;
		for( jj=j; jj>0; --jj ){
			if( g[i][jj] < 0 )
				--negs;
			if( negs < 0 ) return dp[i][j][k] = -INF;
			sum += g[i][jj];
		}
		dp[i][j][k] = sum;
	}
	else{
		// right
		sum = 0;
		negs = k;
		for( jj=j; jj<=N; ++jj ){
			if( g[i][jj] < 0 )
				--negs;
			if( negs < 0 ) break;
			sum += g[i][jj];
			ans = top_down(i-1,jj,negs);
			if( ans!=INF ){
				dp[i][j][k] = max( dp[i][j][k], ans+sum );
			}
		}
		// left
		sum = 0;
		negs = k;
		for( jj=j; jj>0; --jj ){
			if( g[i][jj] < 0 )
				--negs;
			if( negs < 0 ) break;
			sum += g[i][jj];
			ans = top_down(i-1,jj,negs);
			if( ans!=INF ){
				dp[i][j][k] = max( dp[i][j][k], ans+sum );
			}
		}
		
		
		
	}
	return dp[i][j][k];
	
}

int i, j, k, mx;

int main(){
	while( cin >> N >> K, N||K ){
		for( i=0; i<MX; ++i )
			for( j=0; j<MX; ++j )
				for( k=0; k<MXK; ++k )
					dp[i][j][k] = -INF;

		for( i=1; i<=N; ++i )
			for( j=1; j<=N; ++j )
				cin >> g[i][j];
		
		memset( used, 0, sizeof used );
		dp[1][1][ g[1][1]<0 ] = g[1][1];
		used[1][1][ g[1][1]<0 ] = true;
		
		// mx = -INF;
		mx = max(-INF,top_down(N,N,K) );
		// for( k=0; k<=K; ++k )
			// mx = max(mx,top_down( N, N, k ));
		cout << "Case " << ++tc << ": ";
		if( mx<-INF/2 )
			cout << "impossible" << endl;
		else
			cout << mx << endl;
	}
}
