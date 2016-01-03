/**
	UVa 10858 - Unique Factorization
	by Rico Tiongson
	Submitted: July 5, 2013
	Accepted 0.029s C++
	O(m sqrt n) time
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n, lim, sz, temp[35];
vector<int> factors;
vector<vector<int> > out;
void factorize(){
	factors.clear();
	lim = sqrt(n)+1;
	sz = 0;
	for( int i=2; i<lim; ++i  ){
		if( n%i==0 ){
			factors.push_back( i );
			temp[sz] = n/i;
			++sz;
		}
	}
	if( !sz ) return;
	if( factors.back()==temp[sz-1] ) --sz;
	while( sz ){
		factors.push_back( temp[--sz] );
	}
}
void addfactors( int x ){
	if( x==1 ){
		if( sz>1 )
		out.push_back( vector<int>(temp,temp+sz) );
		return;
	}
	for( int i=(sz ? (int)(lower_bound(factors.begin(),factors.end(),temp[sz-1])-factors.begin()) : 0 ); i<factors.size(); ++i ){
		if( x%factors[i]==0 ){
			temp[sz] = factors[i];
			++sz;
			addfactors( x/factors[i] );
			--sz;
		}
	}
}
int main(){
	int i, j;
	scanf("%d",&n);
	while( n ){
		factorize();
		// print();
		out.clear();
		addfactors( n );
		cout << out.size() << endl;
		for( i=0; i<out.size(); ++i ){
			printf("%d", out[i][0]);
			for( j=1; j<out[i].size(); ++j ){
				printf(" %d", out[i][j]);
			}
			putchar('\n');
		}
		scanf("%d",&n);
	}
}
