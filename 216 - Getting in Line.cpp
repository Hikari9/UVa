/**
	UVa 216 - Getting in Line
	by Rico Tiongson
	Submitted: October 8, 2013
	Accepted 0.028s C++
	O(n!) time
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#define ASTERISK "**********************************************************"
using namespace std;
int n, x[10], y[10], i, tc;
double sum, mn;
bool v[10];
vector<int> ans, final;
void dfs( int a ){
	if( sum > mn ) return;
	v[a] = true;
	ans.push_back(a);
	if( ans.size()==n ){
		if( sum < mn ){
			mn = sum;
			final = ans;
		}
	}
	else for( int j=0; j<n; ++j ){
		if( !v[j] ){
			double d = hypot( x[a] - x[j], y[a] - y[j] );
			sum += d;
			dfs(j);
			sum -= d;
		}
	}
	ans.pop_back();
	v[a] = false;
}
int main(){
	cout.precision(2);
	cout << fixed;
	while( cin >> n, n ){
		for( i=0; i<n; ++i ){
			cin >> x[i] >> y[i];
		}
		memset( v, 0, sizeof v );
		ans.clear();
		sum = 0.0;
		mn = HUGE_VAL;
		for( i=0; i<n; ++i ){
			dfs(i);
		}
		// cout << mn << endl;
		cout << ASTERISK << endl << "Network #" << ++tc << endl;
		for( i=1; i<final.size(); ++i ){
			cout << "Cable requirement to connect (" << x[final[i-1]] << "," << y[final[i-1]] << ") to (";
			cout << x[final[i]] << "," << y[final[i]] << ") is " << hypot(x[final[i-1]]-x[final[i]],y[final[i-1]]-y[final[i]]) + 16.0 << " feet." << endl;
		}
		cout << "Number of feet of cable required is " << mn + 16.0*(n-1) << "." << endl;
	}
}
