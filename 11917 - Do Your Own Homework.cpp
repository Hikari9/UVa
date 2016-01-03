/**
	UVa 11917 - Do Your Own Homework
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.022s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
int t, n, d, tc;
string s;
map<string,int> m;
map<string,int>::iterator it;
int main(){
	cin >> t;
	while( t-- ){
		m.clear();
		cin >> n;
		while( n-- ){
			cin >> s >> d;
			m[s] = d;
		}
		cin >> d >> s;
		cout << "Case " << ++tc << ": ";
		it = m.find( s );
		if( it==m.end() ){
			cout << "Do your own homework!";
		}
		else if( it->second<=d ){
			cout << "Yesss";
		}
		else if( it->second<=d+5 ){
			cout << "Late";
		}
		else{
			cout << "Do your own homework!";
		}
		cout << endl;
	}
}
