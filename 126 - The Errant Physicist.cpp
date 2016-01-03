/**
	UVa 126 - The Errant Physicist
	by Rico Tiongson
	Submitted: August 22, 2013
	Accepted 0.015s C++
	O(nlogn) time
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<cctype>
using namespace std;
struct xy{
	int x, y;
	xy() {}
	xy( int X, int Y ): x(X), y(Y) {}
	bool operator<( const xy& _ )const{
		return x>_.x || ( x==_.x && y<_.y );
	}
};
int intAbs( int x ){
	return (x&(-2147483648u)) ? -x : x;
}
string trim( string s ){
	int i;
	for( i=s.length()-1; i>=0; --i ){
		if( s[i]!=' ' ) break;
	}
	return s.substr( 0, i+1 );
}
struct poly{
	map<xy,int> coef;
	poly(): coef() {}
	poly( const poly& _ ): coef( _.coef ) {}
	poly( const string& s ): coef() {
		int c, x, i, j, xCoef, yCoef;
		char sign = '+';
		string term;
		vector<string> v;
		bool flag;
		for( i=0; i<s.size(); ){
			term.clear();
			if( s[i]=='+' || s[i]=='-' ){
				sign = s[i++];
			}
			term.push_back( sign );
			while( i<s.size() && s[i]!='+' && s[i]!='-' ){
				term.push_back( s[i++] );
			}
			v.push_back( term );
			sign = '+';
		}
		for( i=0; i<v.size(); ++i ){
			// get coef
			// get sign first
			c = 1;
			j = 0;
			if( j<v[i].size() && ( v[i][j]=='+' || v[i][j]=='-' ) ){
				if( v[i][j]=='-' ) c = -c;
				++j;
			}
			flag = false;
			x = 0;
			while( j<v[i].size() && isdigit(v[i][j]) ){
				x = x*10 + v[i][j++]-'0';
				flag = true;
			}
			if( flag ) c *= x;
			xCoef = yCoef = 0;
			// parse x and/or y
			if( j<v[i].size() && v[i][j]=='x' ){
				++j;
				flag = false;
				while( j<v[i].size() && isdigit(v[i][j]) ){
					xCoef = xCoef*10 + v[i][j++]-'0';
					flag = true;
				}
				if( !flag ) xCoef = 1;
			}
			if( j<v[i].size() && v[i][j]=='y' ){
				++j;
				flag = false;
				while( j<v[i].size() && isdigit(v[i][j]) ){
					yCoef = yCoef*10 + v[i][j++]-'0';
					flag = true;
				}
				if( !flag ) yCoef = 1;
			}
			if( j<v[i].size() && v[i][j]=='x' ){
				++j;
				flag = false;
				while( j<v[i].size() && isdigit(v[i][j]) ){
					xCoef = xCoef*10 + v[i][j++]-'0';
					flag = true;
				}
				if( !flag ) xCoef = 1;
				
			}
			coef[ xy(xCoef,yCoef) ] += c;
		}
	}
	poly operator*( poly& x ){
		poly ans;
		map<xy,int>::iterator it1, it2;
		for( it1=coef.begin(); it1!=coef.end(); ++it1 ){
			for( it2=x.coef.begin(); it2!=x.coef.end(); ++it2 ){
				ans.coef[ xy( it1->first.x + it2->first.x, it1->first.y + it2->first.y ) ] += it1->second * it2->second;
			}
		}
		for( it1=ans.coef.begin(); it1!=ans.coef.end(); ){
			if( it1->second==0 ) ans.coef.erase( it1++ );
			else ++it1;
		}
		// remove 0 coefficients
		if( ans.coef.empty() ) ans.coef[ xy(0,0) ] = 0;
		return ans;
	}
	string toString(){
		ostringstream a, b;
		map<xy,int>::iterator it;
		char sign = '+';
		for( it=coef.begin(); it!=coef.end(); ++it ){
			// print coefficient
			if( it==coef.begin() ){
				if( intAbs(it->second)==1 && ( it->first.x!=0 || it->first.y!=0 ) ){
					// output only sign
					if( it->second==-1 ){
						b << '-';
						a << ' ';
					}
				}
				else{
					b << it->second;
					a.width( b.tellp() - a.tellp() );
					a.fill(' ');
					a << " ";
				}
			}
			else{
				if( it->second < 0 ){
					b << " - ";
					a << "   ";
				}
				else{
					b << " + ";
					a << "   ";
				}
				if( intAbs(it->second)!=1 || ( it->first.x==0 && it->first.y==0 ) ){
					b << intAbs(it->second);
					a.width( b.tellp() - a.tellp() );
					a.fill(' ');
					a << " ";
				}
			}
			// get x
			if( it->first.x!=0 ){
				a << " ";
				b << "x";
				if( it->first.x!=1 ){
					// exponent
					a << it->first.x;
					b.width( a.tellp() - b.tellp() );
					b.fill(' ');
					b << " ";
				}
			}
			// get y
			if( it->first.y!=0 ){
				a << " ";
				b << "y";
				if( it->first.y!=1 ){
					// exponent
					a << it->first.y;
					b.width( a.tellp() - b.tellp() );
					b.fill(' ');
					b << " ";
				}
			}
		}
		return a.str() + "\n" + b.str();
		// return trim( a.str() ) + "\n" + trim( b.str() );
	}
	string toString2(){
		map<xy,int>::iterator it;
		ostringstream a;
		for( it=coef.begin(); it!=coef.end(); ++it ){
			a << it->second << "x" << it->first.x << "y" << it->first.y << " ";
		}
		return a.str();
	}
};
int main(){
	string a, b;
	while( getline(cin,a), a!="#" ){
		getline(cin,b);
		poly x(a), y(b);
		poly z = x*y;
		cout << z.toString() << endl;
	}
}
