/**
	UVa 164 - String Computer
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.189s C++
	O(n^2) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 2000000000
#define DEL 0
#define INS 1
#define CHANGE 2
#define RETAIN 3
using namespace std;

int dp[25][25];
int prev[25][25];
string a, b;

int dx[] = { 1, 0, 1, 1 };
int dy[] = { 0, 1, 1, 1 };

int DP( int i, int j ){
	if( i == a.length() && j == b.length() ) return 0;
	if( ~dp[i][j] ) return dp[i][j];
	if( j == b.length() ){
		prev[i][j] = DEL;
		return dp[i][j] = DP( i+1, j ) + 1;
	}
	if( i == a.length() ){
		prev[i][j] = INS;
		return dp[i][j] = DP( i, j+1 ) + 1;
	}
	int ans = INF;
	int temp;
	temp = DP( i+1, j ) + 1;
	if( temp < ans ){
		ans = temp;
		prev[i][j] = DEL;
	}
	temp = DP( i, j+1 ) + 1;
	if( temp < ans ){
		ans = temp;
		prev[i][j] = INS;
	}
	temp = DP( i+1, j+1 ) + ( a[i] != b[j] );
	if( temp < ans ){
		ans = temp;
		prev[i][j] = ( a[i] == b[j] ? RETAIN : CHANGE );
	}
	return dp[i][j] = ans;
}

string cmd[] = { "DELETE", "INSERT", "CHANGE", "RETAIN" };

int main(){
	while( cin >> a >> b ){
		memset( dp, -1, sizeof dp );
		memset( prev, -1, sizeof prev );
		DP(0, 0);
		int x = 0;
		int y = 0;
		int off = 1;
		int p = prev[x][x];
		while( p != -1 ){
			// cout << cmd[p] << endl; /*
			switch(p){
				case INS:
					printf( "I%c%02d", b[y], off++ );
					break;
				case DEL:
					printf( "D%c%02d", a[x], off );
					break;
				case CHANGE:
					printf( "C%c%02d", b[y], off++ );
					break;
				case RETAIN:
					++off;
					break;
			}
			// */
			x += dx[p];
			y += dy[p];
			p = prev[x][y];
		}
		cout << "E" << endl;
	}
}
