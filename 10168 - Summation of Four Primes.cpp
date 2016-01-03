/**
	UVa 10168 - Summation of Four Primes
	by Rico Tiongson
	Submitted: June 10, 2013
	Accepted 0.032s C++
	O(sqrt(n)) time
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> p;
int lim,lim2,n,ans[3];
void addprime( int x ){
	lim = sqrt(x) + 1;
	for( int i=1; p[i] < lim; ++i ){
		if( x%p[i]==0 ) return;
	}
	p.push_back( x );
}
bool isPrime( int x ){
	if(x==1) return false;
	lim2 = sqrt(x)+1;
	for(int i=0;p[i]<lim2;++i){
		if(x%p[i]==0) return false;
	}
	return true;
}
bool goldbach( int x ){
	lim = x/2 + 1;
	for( int i=0; p[i] < lim; ++i ){
		if( isPrime( x-p[i] ) ){
			ans[1] = p[i];
			ans[2] = x-p[i];
			return true;
		}
	}
	return false;
}
int main(){
	p.push_back(2);
	p.push_back(3);
	for( int i=5; i<3162; i+=4 ){
		addprime( i );
		addprime( i+=2 );
	}
	while( cin >> n ){
		if(n<8) cout << "Impossible." << endl;
		else{
			if(n%2){
				ans[0] = 3;
				n-=5;
			}
			else{
				ans[0] = 2;
				n-=4;
			}
			if( goldbach(n) ) cout << "2 " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
			else cout << "Impossible." << endl;
		}
	}
}
