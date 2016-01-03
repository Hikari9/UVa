/**
	UVa 11108 - Tautology
	by Rico Tiongson
	Submitted: July 26, 2013
	Accepted 0.016s C++
	O(n * 2^32) time
*/
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string in, s;
int i, pbit;
bool valid[256];
bool tautology(){
	if( s[i]>='p' && s[i]<='t' ){
		++i;
		return ( pbit & (1<<(s[i-1]-'p')) )!=0;
	}
	bool A, B;
	++i;
	switch( s[i-1] ){
		case 'K':
			A = tautology();
			B = tautology();
			return A && B;
			break;
		case 'A':
			A = tautology();
			B = tautology();
			return A || B;
			break;
		case 'N':
			return !tautology();
			break;
		case 'C':
			A = tautology();
			B = tautology();
			return A<=B;
			break;
		case 'E':
			A = tautology();
			B = tautology();
			return A==B;
			break;
			
	}
}
int main(){
	memset( valid, 0, sizeof valid );
	valid['p'] = true;
	valid['q'] = true;
	valid['r'] = true;
	valid['s'] = true;
	valid['t'] = true;
	valid['K'] = true;
	valid['A'] = true;
	valid['N'] = true;
	valid['C'] = true;
	valid['E'] = true;
	// cout << boolalpha;
	while( getline( cin, in ), in[0]!='0' ){
		s.clear();
		for( i=0; i<in.size(); ++i ){
			if( valid[in[i]] ) s.push_back( in[i] );
		}
		// cout << s << endl;
		for( pbit=0; pbit<32; ++pbit ){
			i = 0;
			// cout << pbit << ' ';
			if( !tautology() ) break;
		}
		// cout << endl;
		if( pbit==32 ) cout << "tautology" << endl;
		else cout << "not" << endl;
		
	}
}
