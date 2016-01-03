/**
	UVa 493 - Rational Spiral
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.152s C++
	O(n) time
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int abs( int x ){
	if( x<0 ) return -x;
	return x;
}
int gcd( int a, int b ){
	if( !a || !b ) return 1;
	if( a<0 ) a = -a;
	if( b<0 ) b = -b;
	int temp;
	while(a){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
struct fraction{
	int num, den;
	void normalize(){
		if( den<0 ){
			den = -den;
			num = -num;
		}
		int g = gcd(num,den);
		num /= g;
		den /= g;
		if( !num ) den = 1;
	}
	fraction(): num(0), den(1) {}
	fraction( int x ): num(x), den(1) {}
	fraction( int n, int d ): num(n), den(d) { normalize(); }
	void print() const{
		cout << num << " / " << den << endl;
	}
	bool operator<( const fraction& _ )const{
		if( num!=_.num ) return num < _.num;
		return den > _.den;
	}
} f;
vector<fraction> v;
bool s[1500][1500];
// set<fraction> s;
int dx[] = { 1, 0, -1, 0, 0 };
int dy[] = { 0, -1, 0, 1, 1 };
int w, x, y, z, i, dir(3);
void simulate(){
	while( v.size() <= z ){
		if( dir==4 ){
			dir = 0;
			++w;
		}
		if( abs(x)==w && abs(y)==w )
			++dir;
		x += dx[dir];
		y += dy[dir];
		if(!x) continue;
		f = fraction(y,x);
		// if( s.insert(f).second ) v.push_back(f);
		if( !s[f.num+750][f.den+750] ){
			s[f.num+750][f.den+750] = true;
			v.push_back(f);
		}
	}
}
int main(){
	while( cin >> z ){
		if( z >= v.size() ){
			v.reserve(z+1);
			simulate();
		}
		v[z].print();
	}
	
}
