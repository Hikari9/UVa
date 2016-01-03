/**
	UVa 10077 - The Stern-Brocot Number System
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.028s C++
	O(logn) time
*/
#include<iostream>
using namespace std;
typedef long long lag;
typedef pair<lag,lag> PAIR;
PAIR L, m, R, x;
lag g, temp;
istream& operator>>( istream& in, PAIR& _ ){
	return in >> _.first >> _.second;
}
ostream& operator<<( ostream& out, const PAIR& _ ){
	return out << _.first << " / " << _.second;
}
bool cross_less( const PAIR& a, const PAIR& b ){
	return a.first * b.second < b.first * a.second;
}
int gcd( lag a, lag b ){
	while( a ){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
int main(){

	while( cin >> x, x.first!=1 || x.second!=1 ){
		g = gcd( x.first, x.second );
		x.first /= g;
		x.second /= g;
		// PAIR xg( x.first/g, x.second/g );
		L.first = R.second = 0;
		L.second = R.first = 1;
		while( true ){
			m.first = L.first + R.first;
			m.second = L.second + R.second;
			g = gcd( m.first, m.second );
			m.first /= g;
			m.second /= g;
			// cout << m << endl;
			if( m==x ){
				break;
			}
			if( cross_less(m,x) ){
				cout << 'R';
				L = m;
			}
			else{
				cout << 'L';
				R = m;
			}
		}
		cout << endl;
		///
	}
}
