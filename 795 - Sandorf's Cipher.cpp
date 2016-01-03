/**
	UVa 795 - Sandorf's Cipher
	by Rico Tiongson
	Submitted: October 24, 2013
	Accepted 0.199s C++
	O(n) time
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int pos[] = {
	27, 0, 18, 1, 28, 2,
	19, 29, 9, 30, 3, 10,
	31, 20, 4, 11, 21, 32,
	12, 5, 33, 22, 6, 13,
	34, 23, 14, 35, 15, 7,
	24, 16, 25, 8, 26, 17
};
string s, ans;
char buf[40];
vector<string> v;

int main(){
	while( getline(cin, s) ){
		v.clear();
		for( int i=0; i<s.length(); i+=36 ){
			for( int j=0; j<36 && i+j < s.length(); ++j ){
				buf[pos[j]] = s[i+j];
			}
			v.push_back(buf);
		}
		ans.clear();
		for( int i=v.size()-1; i>=0; --i ){
			ans.append( string( v[i].rbegin(), v[i].rend() ) );
		}
		cout << ans.substr(0, ans.find_last_not_of( '#' ) + 1) << endl;
	}
}
