/**
	UVa 11286 - Conformity
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.152s C++
	O(5nlogn) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<vector<int>,int> m;
map<vector<int>,int>::iterator it;
int n, i, mx, c;
vector<int> v(5);
int main(){
	while( cin >> n, n ){
		m.clear();
		while( n-- ){
			for( i=0; i<5; ++i )
				cin >> v[i];
			sort( v.begin(), v.end() );
			++m[v];
		}
		c = mx = 0;
		for( it=m.begin(); it!=m.end(); ++it ){
			if( it->second > mx ){
				mx = it->second;
				c = 1;
			}
			else if( it->second==mx ) ++c;
		}
		cout << c*mx << endl;
	}
}
