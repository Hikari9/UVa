/**
	UVa 11549 - Calculator Conundrum
	by Rico Tiongson
	Submitted: July 13, 2013
	Accepted 0.708s C++
	O(?) time
*/
#include<iostream>
#include<set>
using namespace std;
int t, n, ten[] = {
	0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999
};
long long k;
set<int, greater<int> > s;
int main(){
	cin >> t;
	while( t-- ){
		cin >> n >> k;
		s.clear();
		while( s.insert( k ).second ){
			k *= k;
			while( k > ten[n] ) k/=10;
		}
		cout << *s.begin() << endl;
	}
}
