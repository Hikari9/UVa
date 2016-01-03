/**
	UVa 202 - Repeating Decimals
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#include<map>
using namespace std;
int a, b, k, i, j;
map<int,int> vis;
string d;
int main(){
	while( cin >> a >> b ){
		cout << a << '/' << b << " = " << a/b << '.';
		a %= b;
		vis.clear();
		d.clear();
		// vis.insert( make_pair(0,vis.size()) );
		while( true ){
			if( !vis.insert( make_pair(a,vis.size()) ).second ) break;
			a *= 10;
			k = a/b;
			a -= k*b;
			
			d.push_back( k + '0' );
		}
		// cout << "[" << d << "]" <<  endl;
		j = vis[a];
		k = vis.size()-j;
		// cout << "[" << j << "]";
		for( i=0; i<j; ++i ) cout << d[i];
		cout << '(';
		if( d.size()-j > 50 ){
			for( j+=50; i<j; ++i ) cout << d[i];
			cout << "...";
		}
		else{
			for( ; i<d.size(); ++i ) cout << d[i];
		}
		cout << ')' << endl << "   ";
		cout << k << " = number of digits in repeating cycle\n" << endl;
	}
}
