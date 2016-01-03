/**
	UVa 526 - String Distance and Transform Process
	by Rico Tiongson
	Submitted: January 21, 2014
	Accepted 0.159s C++
	O(n^2) time
*/
#include <iostream>
#include <cstring>

#define MX 81
#define INS 0
#define DEL 1
#define REP 2
#define RET 3
#define DX dp[i][j]
#define PR prev[i][j]

using namespace std;

string a, b;

int prev[MX][MX];
int dp[MX][MX];


int DP( int i, int j ){
	
	// exists
	if( DX != -1 ) return DX;
	
	// edges
	if( i == a.length() ){
		PR = INS;
		return DX = DP( i, j+1 ) + 1;
	}
	if( j == b.length() ){
		PR = DEL;
		return DX = DP( i+1, j ) + 1;
	}
	
	int value = MX;
	int temp;
	
	
	
	// try inserting
	temp = DP( i, j+1 ) + 1;
	if( temp < value ){
		value = temp;
		PR = INS;
	}
	
	// try deleting
	temp = DP( i+1, j ) + 1;
	if( temp < value ){
		value = temp;
		PR = DEL;
	}
	
	// try retaining
	if( a[i] == b[j] ){
		temp = DP( i+1, j+1 );
		if( temp < value ){
			value = temp;
			PR = RET;
		}	
	}
	// try replacing
	else{
		temp = DP( i+1, j+1 ) + 1;
		if( temp < value ){
			value = temp;
			PR = REP;
		}	
	}
	
	return DX = value;
	
}

void track(){
	int cnt = 1;
	int i = 0, j = 0;
	int ins = 0;
	while( PR != -1 ){
		switch( PR ){
			case INS:
				cout << cnt++ << " Insert " << i+1+ins << "," << b[j] << endl;
				j++, ins++;
				break;
			case DEL:
				cout << cnt++ << " Delete " << i+1+ins << endl;
				i++, ins--;
				break;
			case REP:
				cout << cnt++ << " Replace " << i+1+ins << "," << b[j] << endl;
			case RET:
				i++, j++;
				break;			
		}
	}
}

int main(){
	bool first = true;
	while( getline( cin, a ) && getline( cin, b ) ){
		if( first ) first = false;
		else cout << endl;
		memset( dp, -1, sizeof dp );
		memset( prev, -1, sizeof prev );
		dp[a.length()][b.length()] = 0;
		cout << DP(0, 0) << endl;
		track();
	}
}
