/**
	UVa 348 - Optimal Array Multiplication Sequence
	AC 0.165s C++
*/
#include<iostream>
#include<cstring>
#define MX 11
using namespace std;

int p[MX]; // 0-based
int dp[MX][MX]; // dp from a to b
int N, tc; // size

int kk[MX][MX];
int par[MX][2];

int top_down( int i, int j ){
	if( i==j ) return 0;
	if( dp[i][j]==-1 ){
		dp[i][j] = 2147483647;
		for( int k=i; k<j; ++k ){
			int prev = top_down(i,k) + top_down(k+1,j) + p[i-1]*p[k]*p[j];
			if( prev < dp[i][j] ){
				kk[i][j] = k;
				dp[i][j] = prev;
			}
		}
	}
	return dp[i][j];
}

void addpar( int i, int j ){
	if( i==j ) return;
	++par[i][0], ++par[j][1];
	if( i==j-1 ) return;
	addpar( i, kk[i][j] );
	addpar( kk[i][j]+1, j );
}



int main(){
	while( cin >> N, N ){
	
		for( int i=1; i<=N; ++i ){
			cin >> p[i-1] >> p[i];
		}
		
		memset( dp, -1, sizeof dp );
		memset( kk, -1, sizeof kk );
		
		for( int i=2; i<=N; ++i )
			dp[i-1][i] = p[i-2] * p[i-1] * p[i];
			
		top_down(1,N);
		// cout << "PUCHA: " << top_down(1,N) << endl;
		
		cout << "Case " << ++tc << ": ";
		
		memset( par, 0, sizeof par );
		addpar(1,N);
		
		for( int i=1; i<=N; ++i ){
			if( i!=1 ) cout << " x ";
			for( int j=0; j<par[i][0]; ++j ){
				cout << '(';
			}
			cout << "A" << i;
			for( int j=0; j<par[i][1]; ++j ){
				cout << ')';
			}
		}
		cout << endl;
		
	}
	
}
