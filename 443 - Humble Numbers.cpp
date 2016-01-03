/**
	UVa 443 - Humble Numbers
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.175s C++
	O(nlogn) time
*/
#include<iostream>
#include<vector>
#include<set>
// #include<ctime>
using namespace std;
set<long long> h;
set<long long>::iterator it, it2;
const char* suffix( int x ){
	switch( x%100 ){
		case 11:
		case 12:
		case 13:
			return "th";
		default:
		switch( x%10 ){
			case 1: return "st";
			case 2: return "nd";
			case 3: return "rd";
			default: return "th";
		}
	}
}
int main(){
	h.insert(2);
	h.insert(3);
	h.insert(5);
	h.insert(7);
	for( it=h.begin(); it!=h.end(); ++it ){
		for( it2=h.begin(); ; ++it2 ){
			if( *it * (*it2)>2000000001LL ) break;
			h.insert( *it * (*it2) );
			if( it2==h.end() ) break;
		}
	}
	h.insert(1);
	vector<long long> v(h.begin(),h.end());
	int n;
	while( cin >> n, n ){
		cout << "The " << n << suffix(n) << " humble number is " << v[n-1] << "." << endl;
	}
}
