/**
	UVa 10408 - Farey sequences
	by Rico Tiongson
	Submitted: August 11, 2013
	Accepted 0.386s C++
	O(2n^2logn) pregen
*/
#include<iostream>
#include<set>
#include<cstring>
#include<cmath>
// #include<ctime>
using namespace std;
struct cmp{
	bool operator()( const pair<int,int>& a, const pair<int,int>& b ) const{
		return a.first*b.second< b.first*a.second;
	}
};
int gcd( int a, int b ){
	int temp;
	while( b ){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
set<pair<int,int>, cmp> farey;
set<pair<int,int>, cmp>::iterator it;
int main(){
	for( int i=1; i<1001; ++i ){
		for( int j=i+1; j<1001; ++j ){
			if( gcd(i,j)==1 ) 
				farey.insert( make_pair(i,j) );
		}
	}
	farey.insert( farey.end(), make_pair(1,1) );
	int a, b;
	while( cin >> a >> b ){
		for( it=farey.begin(); it!=farey.end(); ++it ){
			if( it->second <= a ){
				if(--b==0) break;
			}
		}
		cout << it->first << '/' << it->second << endl;
	}
}
