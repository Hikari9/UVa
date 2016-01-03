/**
	UVa 10534 - Wavio Sequence
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.102s C++
	O(n+2nlogn) time
*/
#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#define MX 10001
using namespace std;
int INC[MX], DEC[MX];
vector<int> increasing, decreasing;
vector<int>::iterator lb;
int n, a[MX], i, mx;
int main(){
	while( scanf("%d",&n)==1 ){
		for( i=0; i<n; ++i ){
			scanf( "%d", a+i );
		}
		increasing.clear();
		decreasing.clear();
		for( i=0; i<n; ++i ){
			lb = lower_bound( increasing.begin(), increasing.end(), a[i] );
			if( lb==increasing.end() ){
				increasing.push_back( a[i] );
				INC[i] = increasing.size();
			}
			else{
				*lb = a[i];
				INC[i] = (int)(lb-increasing.begin()) + 1;
			}
		}
		for( i=n-1; i>=0; --i ){
			lb = lower_bound( decreasing.begin(), decreasing.end(), a[i] );
			if( lb==decreasing.end() ){
				decreasing.push_back( a[i] );
				DEC[i] = decreasing.size();
			}
			else{
				*lb = a[i];
				DEC[i] = (int)(lb-decreasing.begin()) + 1;
			}
		}
		mx = 0;
		for( i=0; i<n; ++i ){
			// cout << INC[i] << " " << DEC[i] << endl;
			mx = max( mx, 2*min(INC[i],DEC[i])-1 );
		}
		printf( "%d\n", mx );
	}
}
