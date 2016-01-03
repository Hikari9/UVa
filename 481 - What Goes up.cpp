/**
	UVa 481 - What Goes Up
	by Rico Tiongson
	Submitted: June 23, 2013
	Accepted 0.049s C++
	O( nlogk ) time
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<int> v, lis;
int i, j, k, mid;
void LIS( vector<int>& a ){
	int next[ a.size() ];
	if( a.empty() ) return;
	lis.push_back( 0 );
	for( i=1; i<a.size(); ++i ){
		if( a[ lis.back() ] < a[i] ){
			next[i] = lis.back();
			lis.push_back( i );
		}
		else{
			for( j=0, k=lis.size()-1; j<k; ){
				mid = (j+k)/2;
				if( a[ lis[mid] ] < a[i] ) j = mid+1;
				else k = mid;
			}
			if( a[i] < a[ lis[j] ] ){
				if( j ) next[i] = lis[j-1];
				lis[j] = i;
			}
		}
	}
	// store index
	for( j=lis.size(), k=lis.back(); j--; k = next[k] )
		lis[j] = k;
}
int main(){
	while( scanf("%d",&i)!=EOF ) v.push_back( i );
	LIS( v );
	printf( "%d\n-\n",lis.size() );
	for( i=0; i<lis.size(); ++i )
		printf( "%d\n", v[lis[i]] ); // through index of lis
}
