/**
	UVa 10109 - Solving Systems of Linear Equations
	by Rico Tiongson
	Submitted: January 23, 2014
	Accepted 0.422s C++
	O(n^3) time
*/
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;
template<class T>
T gcd( T a, T b ){
	if( a == 0 ) return b;
	if( b == 0 ) return a;
	if( a < 0 ) a = -a;
	if( b < 0 ) b = -b;
	T temp;
	while( b > 0 ){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

template<class T>
T lcm( T a, T b ){
	return a / gcd(a,b) * b;
}

template<class T>
struct fraction {
	T num, den;
	// static
	// constructors
	fraction(): num(0), den(1) {}
	fraction( T n, T d = 1 ){
		if( n == 0 ){
			num = 0;
			den = 1;
			return;
		}
		if( d < 0 ){
			n = -n;
			d = -d;
		}
		T g = gcd(n, d);
		num = n/g;
		den = d/g;
	}
	
	// unary
	bool operator!() const{ return num == 0; }
	fraction& operator-() const{ num = -num; return *this; }
	fraction abs() const{
		return num < 0 ? fraction(-num, den) : *this;
	}
	
	// arithmetic
	fraction operator+( fraction f ) const{
		T low = lcm(den, f.den);
		return fraction( num * (low / den) + f.num * (low / f.den), low );
	}
	fraction operator-( fraction f ) const{
		T low = lcm(den, f.den);
		return fraction( num * (low / den) - f.num * (low / f.den), low );
	}
	fraction operator*( fraction f ) const{
		T g1 = gcd(num, f.den);
		T g2 = gcd(f.num, den);
		return fraction( (num/g1) * (f.num/g2), (den/g2) * (f.den/g1) );
	}
	fraction operator/( fraction f ) const{
		return *this * fraction(f.den, f.num);
	}
	
	fraction& operator+=( fraction f ){ return *this = (*this + f); }
	fraction& operator-=( fraction f ){ return *this = (*this - f); }
	fraction& operator*=( fraction f ){ return *this = (*this * f); }
	fraction& operator/=( fraction f ){ return *this = (*this / f); }
	
	bool operator < ( fraction f ) const {
		return num * f.den < f.num * den;
	}
	bool operator > ( fraction f ) const {
		return f < *this;
	}
	bool operator == ( fraction f ) const {
		return num == f.num && den == f.den;
	}
	bool operator != ( fraction f ) const {
		return !( *this == f );
	}
	
	friend std::ostream& operator << ( std::ostream& out, fraction<T> f ){
		out << f.num;
		if( f.den != 1 ) out << "/" << f.den;
		return out;
	}
	
};

typedef fraction<int> Fraction;
using namespace std;
typedef long long lag;

typedef fraction<lag> FR;
char buf[1005];
istream& operator >> ( istream& in, FR& f ){
	in >> buf;
	// int fn = s.find( "/" );
	lag x, y;
	if( sscanf( buf, "%lld/%lld", &x, &y ) == 2 ){
		f = FR(x, y);
	}
	else{
		sscanf( buf, "%lld", &x );
		f = FR(x);
	}
	return in;
}

int tc, m, n;

vector<vector<FR> > mat;
vector<FR> b, ans;

int gauss(){
	int id = 0, rank = 0;
	for( int p=0; p<m; ++p ){
		if( id >= n ) break;
		int nonzero = -1;
		for( int i=p; i<m; ++i ){
			if( mat[i][id].num != 0 ){
				nonzero = i;
				break;
			}
		}
		if( nonzero == -1 ){
			id++;
			p--;
			continue;
		}
		if( nonzero != p ){
			mat[nonzero].swap( mat[p] );
			swap( b[p], b[nonzero] );
		}
		rank++;
		// singularize
		for( int i=id+1; i<n; ++i ){
			mat[p][i] /= mat[p][id];
		}
		b[p] /= mat[p][id];
		mat[p][id] = FR(1,1);
		
		for( int i=0; i<m; ++i ){
			if( i == p ) continue;
			FR alpha = mat[i][id] / mat[p][id];
			b[i] -= alpha * b[p];
			for( int j=id; j<n; ++j ){
				mat[i][j] -= alpha * mat[p][j];
			}
		}
		id++;
	}
	
	for( int i=0; i<m; ++i ){
		if( b[i].num == 0 ) continue;
		bool zero = true;
		for( int j=0; j<n; ++j ){
			if( mat[i][j].num != 0 ){
				zero = false;
				break;
			}
		}
		if( zero )
			return -1;
	}
	// return 1;
	// solution!
	if( rank != n ) return n - rank;
	ans.resize(n);
	for( int i=n-1; i>=0; --i ){
		ans[i] = b[i];
	}
	for( int i=0; i<n; ++i ){
		cout << "x[" << i+1 << "] = " << ans[i] << endl;
	}
	return 0;
}

int main(){
	bool first = true;
	while( cin >> tc, tc ){
		if( first ) first = false;
		else cout << endl;
		cout << "Solution for Matrix System # " << tc << endl;
		cin >> n >> m;
		mat.assign(m, vector<FR>(n));
		b.resize(m);
		for( int i=0; i<m; ++i ){
			for( int j=0; j<n; ++j ){
				cin >> mat[i][j];
			}
			cin >> b[i];
		}
		int x = gauss();
		if( x == -1 ) cout << "No Solution." << endl;
		else if( x != 0 ) cout << "Infinitely many solutions containing " << x << " arbitrary constants." << endl;
	}
}
