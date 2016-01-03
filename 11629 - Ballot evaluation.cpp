/**
	UVa 11629 - Ballot evaluation
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.192s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
map<string,int> m;
int p, g, tc, sum, x;
string s, cmd;
double d;
int main(){
	cin >> p >> g;
	while( p-- ){
		cin >> s >> d;
		m[s] = (int)(d*10.0+1e-6);
	}
	while( tc<g ){
		cin >> s;
		sum = m[s];
		while( cin >> cmd, cmd=="+" ){
			cin >> s;
			sum += m[s];
		}
		cin >> x;
		x *= 10;
		cout << "Guess #" << ++tc << " was ";
		if( cmd=="<" ){
			if( sum>=x ) cout << "in";
		}
		else if( cmd=="<=" ){
			if( sum>x ) cout << "in";
		}
		else if( cmd==">" ){
			if( sum<=x ) cout << "in";
		}
		else if( cmd==">=" ){
			if( sum<x ) cout << "in";
		}
		else if( cmd=="=" ){
			if( sum!=x ) cout << "in";
		}
		cout << "correct." << endl;
	}
}
