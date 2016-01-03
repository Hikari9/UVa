/**
	UVa 11203 - Can you decide it for ME?
	by Rico Tiongson
	Submitted: August 4, 2013
	Accepted 0.016s C++
	O(n) time
*/
#include<iostream>
using namespace std;
int n, i, F;
string s;
bool M, E;
bool theorem(){
	M = E = false;
	int f[3] = {0,0,0};
	F = 0;
	for( i=0; i<s.size(); ++i ){
		switch( s[i] ){
			case 'M':
				if( M ) return false;
				M = true;
				++F;
				break;
			case 'E':
				if( E || !M ) return false;
				E = true;
				++F;
				break;
			case '?':
				++f[F];
				break;
			default:
				return false;
		}
	}
	return f[0]>0 && f[1]>0 && f[2]>1 && f[1]==(f[2]-f[0]);
}
int main(){
	cin >> n;
	cin.ignore();
	while( n-- ){
		cin >> s;
		
		if( theorem() ) cout << "theorem" << endl;
		else cout << "no-theorem" << endl;
	}
}
