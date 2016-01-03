/**
	UVa 10407 - Simple Division
	by Rico Tiongson
	Submitted: August 30, 2013
	Accepted 0.025s C++
	O(n^2) time
*/
#include<cstdio>
#include<vector>
using namespace std;
int gcd( int a, int b ){
	int temp;
	while( b ){
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

vector<int> v;
int x, i, j;

int main(){
	while( scanf( "%d", &x )==1, x ){
		v.clear();
		v.push_back(x);
		while( scanf( "%d", &x )==1, x ){
			v.push_back(x);
		}
		x = 0;
		for( i=1; i<v.size(); ++i ){
			for( j=0; j<i; ++j ){
				if( v[i]!=v[j] ){
					x = gcd(x,v[i]>v[j] ? v[i]-v[j] : v[j]-v[i]);
				}
			}
		}
		printf( "%d\n", x );
	}
}
