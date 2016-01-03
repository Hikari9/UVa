/**
	UVa 10700 - Camel trading
	by Rico Tiongson
	Submitted: June 9, 2014
	Accepted 0.032s C++
	DP
*/
#include <iostream>
#include <vector>
// #include <limits>
#include <cstring>
using namespace std;
typedef long long lag;

vector<lag> num;
vector<char> op;

lag mx[25][25], mn[25][25];

lag toLag( const string& s ){
	lag x = 0;
	for( int i=0; i<s.length(); ++i ){
		x = x * 10 + s[i] - '0';
	}
	return x;
}

lag f( lag a, lag b, char o ){
	if( o == '+' ) return a + b;
	return a * b;
}

lag MIN( int a, int b ){
	if( a > b ) return 10000000000000000LL;
	if( a == b ) return num[a];
	if( mn[a][b] != -1 ) return mn[a][b];
	lag m = 10000000000000000LL;
	for( int j=a+1; j<=b; ++j ){
		m = min( m, f( MIN(a, j-1), MIN(j, b), op[j-1] ) );
	}
	return mn[a][b] = m;
}

lag MAX( int a, int b ){
	if( a > b ) return 0;
	if( a == b ) return num[a];
	if( mx[a][b] != -1 ) return mx[a][b];
	lag m = 0;
	for( int j=a+1; j<=b; ++j ){
		m = max( m, f( MAX(a, j-1), MAX(j, b), op[j-1] ) );
	}
	return mx[a][b] = m;
}

int main(){
	int n;
	string s, buffer;
	cin >> n;
	while( n-- ){
		cin >> s;
		num.clear();
		op.clear();
		buffer.clear();
		for( int i=0; i<s.length(); ++i ){
			if( s[i] == '*' || s[i] == '+' ){
				num.push_back( toLag(buffer) );
				buffer.clear();
				op.push_back( s[i] );
			}
			else{
				buffer.push_back( s[i] );
			}
		}
		num.push_back( toLag(buffer) );
		// cout << num.size() << " " << op.size() << endl;
		// for( int i=0; i<num.size(); ++i ){
			// if( i < op.size() )
				// cout << num[i] << " " << op[i] << " ";
			// else
				// cout << num[i] << endl;
		// }
		memset( mx, -1, sizeof mx );
		memset( mn, -1, sizeof mn );
		cout << "The maximum and minimum are " << MAX(0, num.size()-1) << " and " << MIN(0, num.size()-1) << ".\n";
		// cout << "mn: " << MIN(0, num.size()-1) << endl;
		// cout << "mx: " << MAX(0, num.size()-1) << endl;
		// cout << f( MAX(0, 1), MAX(2, 4), op[1] ) << endl;
	}
}
