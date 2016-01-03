/**
	UVa 10326 - The Polynomial Equation
	by Rico Tiongson
	Submitted: August 22, 2013
	Accepted 0.016s C++
	O(n^2) time
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long lag;
int n, i, j;
lag root, temp[55];
vector<lag> f;
bool first;
char sign;
int main(){
	while( cin >> n ){
		f.clear();
		f.push_back( 1LL );
		for( i=0; i<n; ++i ){
			cin >> root;
			root = -root;
			memset( temp, 0, sizeof temp );
			for( j=0; j<f.size(); ++j ){
				temp[j] += f[j]*root;
				temp[j+1] += f[j];
			}
			f.assign( temp, temp+j+1 );
		}
		first = true;
		sign = '+';
		for( i=f.size()-1; i>0; --i ){
			if( f[i] ){
				if( first ) first = false;
				else{
					if( f[i]<0 ){
						f[i] = -f[i];
						sign = '-';
					}
					else sign = '+';
					cout << sign << ' ';
				}
				if( f[i]!=1 ){
					cout << f[i];
				}
				cout << 'x';
				if( i!=1 ){
					cout << '^' << i;
				}
				cout << ' ';
			}
		}
		if( f[0]<0 ){
			f[0] = -f[0];
			sign = '-';
		}
		else sign = '+';
		cout << sign << ' ' << f[0] << " = 0" << endl;
	}
}
