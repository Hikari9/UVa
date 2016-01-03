/**
	UVa 10138 - CDVII
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.022s C++
	O(mlogn) time
*/
#include<iostream>
#include<sstream>
#include<cstdio>
#include<map>
using namespace std;
typedef map<int, int> node;

int getTime( const string& buf ){
	int mon, day, hr, min;
	sscanf( buf.c_str(), "%d:%d:%d:%d", &mon, &day, &hr, &min );
	return day * 24 * 60 + hr * 60 + min;
}

int t, cost[24];
string line;

map<string, node> m;
map<string, node>::iterator it;
node::iterator it2, it3;

int ABS( int x ){ return x < 0 ? -x : x; }

double Price( node& n ){
	int ans = 0;
	for( it2 = n.begin(); it2 != n.end(); ++it2 ){
		if( it2->second >= 0 ){
			if( it2 == n.begin() ) continue;
			it3 = it2;
			--it3;
			if( it3->second < 0 ){
				int prev = -it3->second - 1;
				int km = it2->second - prev;
				int pr = cost[(it3->first/60)%24];
				// cout << ((it3->first) / 60)%24 << endl;
				// cout << cost[((it3->first) / 60)%24] << endl;
				ans += 100 + ABS(km * pr);
			}
		}
	}
	return ans == 0 ? 0.00 : (double)(ans+200)/100.0;
}

int main(){
	cout.precision(2);
	cout << fixed;
	cin >> t;
	while(t--){
		for( int i=0; i<24; ++i ) cin >> cost[i];
		cin.ignore();
		m.clear();
		while( getline(cin, line) && !line.empty() ){
			istringstream in(line);
			in >> line;
			node& n = m[line];
			in >> line;
			int tm = getTime(line);
			in >> line;
			int x;
			in >> x;
			n[tm] = ( line[1] == 'n' ? -x - 1 : x );
		}
		for( it = m.begin(); it != m.end(); ++it ){
			double price = Price( it->second );
			if( price == 0.00 ) continue;
			cout << it->first << " $" << Price( it->second ) << endl;
		}
		if(t) cout << endl;
	}
}
