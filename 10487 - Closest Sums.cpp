/**
	UVa 10487 - Closest Sums
	by Rico Tiongson
	Submitted: June 2, 2013
	Accepted 1.032s C++
	O(mlog( (n)*(n-1)/2 ) ) time
*/
#include<iostream>
#include<set>
using namespace std;
int n,m,x,r=0,a[1001];
set<int> s;
set<int>::iterator it,it2;
int finder(){
	it = s.lower_bound( x );
	if( it==s.begin() ) return *it;
	if( it==s.end() ) return *(--it);
	it2 = it;
	--it2;
	return ( x - *it2 < *it - x ) ? *it2 : *it;
}
int main(){
	while( cin >> n, n ){
		s.clear();
		for( int i=0; i<n; ++i ){
			cin >> a[i];
			for( int j=0;j<i;++j ) s.insert( a[i]+a[j] ); 
		}
		cout << "Case " << ++r << ':' << endl;
		cin >> m;
		while( m ){
			--m;
			cin >> x;
			cout << "Closest sum to " << x <<" is " << finder() << '.' << endl;
		}
	}
}
