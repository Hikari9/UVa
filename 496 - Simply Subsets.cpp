/**
	UVa 496 - Simply Subsets
	by Rico Tiongson
	Submitted: July 23, 2013
	Accepted 0.015s C++
	O(2nlog2n) time
*/
#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<int> u;
vector<int>::iterator uit;
multiset<int> s, v;
multiset<int>::iterator it;
string buf;
int x;
inline bool confused(){
	for( it=v.begin(); it!=v.end(); ++it ){
		if( s.find( *it )!=s.end() ) return true;
	}
	return false;
}
int main(){
	while( getline( cin, buf ) ){
		s.clear();
		v.clear();
		// split
		{
			istringstream in( buf );
			while( in >> x )
				s.insert( x );
		}
		getline( cin, buf );
		// split 2
		{
			istringstream in( buf );
			while( in >> x )
				v.insert( x );
		}
		
		// check if size if the same
		if( s.size() == v.size() ){
			// check if same
			if( s==v )
				cout << "A equals B" << endl;
			else if( confused() )
				cout << "I'm confused!" << endl;
			else
				cout << "A and B are disjoint" << endl;
			// check if disjoint
		}
		else if( s.size() < v.size() ){
			// get set_intersection
			u.resize( s.size() + v.size() );
			uit = set_intersection( s.begin(), s.end(), v.begin(), v.end(), u.begin() );
			u.resize( uit - u.begin() );
			if( u.size()==s.size() ) // subset
				cout << "A is a proper subset of B" << endl;
			else if( u.size() )
				cout << "I'm confused!" << endl;
			else
				cout << "A and B are disjoint" << endl;
		}
		else{
			s.swap( v );
			// get set_intersection
			u.resize( s.size() + v.size() );
			uit = set_intersection( s.begin(), s.end(), v.begin(), v.end(), u.begin() );
			u.resize( uit - u.begin() );
			if( u.size()==s.size() ) // subset
				cout << "B is a proper subset of A" << endl;
			else if( u.size() )
				cout << "I'm confused!" << endl;
			else
				cout << "A and B are disjoint" << endl;
		}
	}
}
