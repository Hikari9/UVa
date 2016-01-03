/**
	UVa 12592 - Slogan Learning of Princess
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.019s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
struct node{
	map<string,node>::iterator partner;
	node() {}
	node( const map<string,node>::iterator& it ): partner( it ) {}
};
map<string,node> slogans;
map<string,node>::iterator it1, it2;
int n, q;
string s;
int main(){
	cin >> n;
	cin.ignore();
	while( n-- ){
		getline( cin, s );
		it1 = slogans.insert( make_pair( s, node() ) ).first;
		getline( cin, s );
		it2 = slogans.insert( make_pair( s, node(it1) ) ).first;
		it1->second.partner = it2;
	}
	cin >> q;
	cin.ignore();
	while( q-- ){
		getline( cin, s );
		cout << slogans.find( s )->second.partner->first << endl;
	}
}
