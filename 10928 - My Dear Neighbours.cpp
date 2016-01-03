/**
	UVa 10928 - My Dear Neighbours
	by Rico Tiongson
	Submitted: November 2, 2013
	Accepted 0.229s C++
	O(n^2) time
*/
#include<iostream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;

int t, n, neighbors;
bool hasNeighbor[1005];

int main(){
	cin >> t;
	while( t-- && cin >> n ){
		string line;
		getline( cin, line );
		
		vector<int> ans;
		int mnNeighbors = 1000000;
		
		for( int i=1; i<=n; ++i ){
		
			// string line;
			getline( cin, line );
			istringstream stream (line);
			
			memset( hasNeighbor, 0, sizeof hasNeighbor );
			int next, cnt = 0;
			
			while( true ){
				try{
					if( !(stream >> next) ) break;
					if( next == i ||  next < 1 || next > n || hasNeighbor[next] ) continue;
					hasNeighbor[next] = true;
					++cnt;
				}
				catch (...) {}
			}
			
			if( cnt < mnNeighbors ){
				mnNeighbors = cnt;
				ans.clear();
			}
			if( cnt == mnNeighbors ){
				ans.push_back(i);
			}
			
		}
		
		for( int i=0; i<ans.size(); ++i ){
			if( i != 0 ) cout << ' ';
			cout << ans[i];
		}
		
		cout << endl;
		
	}
}
