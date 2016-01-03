/**
	UVa 2056 - Lazy Math Instructor
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.009s C++
	O( nlognloglogn ) time
*/
#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
int n, i;
struct term;
typedef map<term,int> poly; //coef
ostream& operator<<( ostream& out, poly x );
poly::iterator it, it2;
struct term{ //degrees
	int c[26];
	term(){
		memset( c, 0, sizeof c );
	}
	term( char _ ){
		memset( c, 0, sizeof c );
		c[_-'a'] = 1;
	}
	term( const term& _ ){
		memcpy( c, _.c, sizeof c );
	}
	bool operator<( const term& _ )const{
		for( i=0; i<26; ++i ){
			if( c[i] != _.c[i] ) return c[i] > _.c[i];
		}
		return false;
	}
	bool operator==( const term& _ )const{
		for( i=0; i<26; ++i ){
			if( c[i] != _.c[i] ) return false;
		}
		return true;
	}
	term& operator*=( const term& _ ){
		for( i=0; i<26; ++i ){
			c[i] += _.c[i];
		}
		return *this;
	}
	term operator*( const term& _ )const{
		term COPY( *this );
		return COPY*=_;
	}
};
ostream& operator<<( ostream& out, const term& _ ){
	for( i=0; i<26; ++i ){
		if( _.c[i] ){
			out.put( i+'a' );
			if( _.c[i]!=1 ){
				out << '^' << _.c[i];
			}
		}
	}
	return out;
}
poly& operator+=( poly& x, poly& y ){
	for( it=y.begin(); it!=y.end(); ++it ){
		x[ it->first ] += it->second;
	}
	return x;
}
poly operator+( const poly& x, poly& y ){
	poly COPY( x );
	return COPY+=y;
}
poly& operator-=( poly& x, poly& y ){
	for( it=y.begin(); it!=y.end(); ++it ){
		x[ it->first ] -= it->second;
	}
	return x;
}
poly operator-( const poly& x, poly& y ){
	poly COPY( x );
	return COPY-=y;
}
poly operator*( poly& x, poly& y ){
	poly res;
	// cout << x << " vs " << y << endl;
	for( it=x.begin(); it!=x.end(); ++it ){
		for( it2=y.begin(); it2!=y.end(); ++it2 ){
			// cout << (it->first * it2->first) << endl;
			res[ it->first * it2->first ] += it->second * it2->second;
		}
	}
	return res;
}
poly& operator*=( poly& x, poly& y ){
	return x = (x*y);
}
poly& operator-( poly& x ){
	for( it=x.begin(); it!=x.end(); ++it ){
		it->second = -it->second;
	}
}
struct obj{
	char c, sn;
	poly p;
	obj( char _, char _s ): c(_), sn(_s), p() {}
	obj( const poly& _, char _s ): c(0), sn(_s), p(_) {}
};

poly Polynomial( const string& s ){
	int x, y;
	list<obj> l;
	char sn = '+';
	poly temp;
	for( int j=0; j<s.size(); ++j ){
		switch( s[j] ){
			case '+':
				sn = '+';
				break;
			case '-':
				sn = '-';
				break;
			case '*':
				sn = '*';
				break;
			case '(':
				// find next
				y = 1;
				for( x=j+1; x<s.size(); ++x ){
					if( s[x]=='(' ) ++y;
					else if( s[x]==')' ){
						if( !--y ) break;
					}
				}
				// x = s.find( ')', j );
				// cout << s.substr( j+1, x-j-1 ) << endl;
				// system("PAUSE");
				l.push_back( obj( Polynomial( s.substr( j+1, x-j-1 ) ), sn ) );
				j = x;
				break;
			default:
				if( islower(s[j]) ){
					temp.clear();
					temp[term(s[j])] = 1;
					l.push_back( obj( temp, sn ) );
					sn = '*';
				}
				else if( isdigit(s[j]) ){
					/* // constant
					y = 0;
					// parse int
					for( x=j; x<s.size() && isdigit( s[x] ); ++x ){
						y *= 10;
						y += (s[x]-'0');
					}
					j = x-1;*/
					temp.clear(); 
					temp[term()] = s[j]-'0';
					l.push_back( obj( temp, sn ) );
					sn = '*';
				}
		}
	}
	// multiply
	if( l.empty() ) return poly();
	list<obj>::iterator lit = l.begin(), lit2;
	lit2 = lit++;
	// cout << l.front().p << l.back().p << endl;
	while( lit != l.end() ){
		if( lit->sn=='*' ){
			// cout << lit2->p << '*' << lit->p << " = " << ( lit2->p * lit->p ) << endl;
			lit2->p *= lit->p;
			lit = l.erase( lit );
		}
		else{
			lit2 = lit++;
		}
	}
	// add subtract
	temp.clear();
	for( lit=l.begin(); lit!=l.end(); ++lit ){
		if( lit->sn=='+' ) temp += lit->p;
		else temp -= lit->p;
	}
	// normalize
	for( it=temp.begin(); it!=temp.end(); ){
		if( !it->second ) temp.erase( it++ );
		else ++it;
	}
	return temp;
}
bool valid( const string& s ){
	int y=0;
	for( i=0; i<s.size(); ++i ){
		if( s[i]=='(' ) ++y;
		else if( s[i]==')' ) --y;
	}
	return !y;
}
istream& operator>>( istream& in, poly& x ){
	string buf;
	getline( in, buf );
	transform( buf.begin(), buf.end(), buf.begin(), ::tolower );
	if( valid(buf) ) x = Polynomial( buf );
	else x.clear();
	return in;
}
ostream& operator<<( ostream& out, poly x ){
	for( it=x.begin(); it!=x.end(); ++it ){
		out << it->second << it->first << ' ';
	}
	return out;
}
bool operator==( poly& x, poly& y ){
	if( x.size() != y.size() ) return false;
	for( it=x.begin(), it2=y.begin(); it!=x.end(); ++it, ++it2 ){
		if( *it != *it2 ) return false;
	}
	return true;
}
poly a, b;
int main(){
	cin >> n;
	cin.ignore();
	while( n-- ){
		cin >> a >> b;
		if( a.empty() || b.empty() ){
			cout << "NO" << endl;
			continue;
		}
		// cout << a << endl << b << endl;
		cout << ((a==b)?("YES"):("NO")) << endl;
	}
	// cout << Polynomial("a*2-(a+c)+((a+c+e)*2)") << endl;
}
