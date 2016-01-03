/**
	UVa 434 - Matty's Blocks
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 0.025s C++
	O(n^2 + nlogn) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

int t, k;
int front[10], side[10];

int g[10][10], maxNum, M, N;

void print( int a[10][10] = g, int f[10] = front, int s[10] = side ){
	cout << endl;
	cout << "  ";
	for( int i=0; i<k; ++i ){
		cout << s[i];
	}
	cout << endl << endl;
	for( int i=0; i<k; ++i ){
		cout << f[i] << " ";
		for( int j=0; j<k; ++j ){
			cout << a[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
	
}

void MakeLayout(){
	memset( g, 0, sizeof g );
	for( int i=0; i<k; ++i ){
		for( int j=0; j<k; ++j ){
			g[i][j] = front[i];
		}
	}
	// layer out
	maxNum = 0;
	for( int j=0; j<k; ++j ){
		for( int i=0; i<k; ++i ){
			g[i][j] = min( g[i][j], side[j] );
			maxNum += g[i][j];
		}
	}
	// print(g,front,side);
	// flatten
	N = 0;
	map<int, int> F, S;
	for( int i=0; i<k; ++i ){
		F[front[i]]++;
		S[side[i]]++;
	}
	for( map<int, int>::iterator it = F.begin(); it != F.end(); ++it ){
		N += it->first * max( it->second, S[it->first] );
		// S[it->first] = 0;
		S.erase(it->first);
	}
	for( map<int, int>::iterator it = S.begin(); it != S.end(); ++it ){
		N += it->first * it->second;
	}
	M = maxNum - N;
}

int main(){
	cin >> t;
	while(t--){
		cin >> k;
		for( int i=0; i<k; ++i )
			cin >> front[i];
		for( int i=0; i<k; ++i )
			cin >> side[i];
		// sort( front, front + k );
		// sort( side, side + k );
		MakeLayout();
		cout << "Matty needs at least " << N << " blocks, and can add at most " << M << " extra blocks." << endl;
	}
}
