/**
	UVa 10261 - Ferry Loading
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.535s C++
	O(n^2logn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
using namespace std;
int t, K, x;
vector<map<int, int> > dp;
map<int, int>::iterator it, it2;

vector<int> car;

int main(){
	scanf( "%d",  &t );
	while(t--){
		scanf( "%d", &K );
		K *= 100;
		car.clear();
		dp.clear();
		while( scanf( "%d", &x ) == 1 ){
			if( x == 0 ) break;
			car.push_back(x);
			dp.push_back( map<int, int>() );
		}
		if( car.empty() ){
			puts( "0" );
			if( t ) putchar( '\n' );
			continue;
		}
		if( car[0] <= K ){
			dp[0][car[0]] = 0;
			dp[0][0] = car[0];
		}
		for( int k=1; k<car.size(); ++k ){
			for( it = dp[k-1].begin(); it != dp[k-1].end(); ++it ){
				if( it->first + car[k] <= K ){
					dp[k][it->first + car[k]] = it->second;
				}
				if( it->second + car[k] <= K ){
					dp[k][it->first] = it->second + car[k];
				}
			}
		}
		int last = -1;
		for( int i=car.size()-1; i>=0; --i ){
			if( !dp[i].empty() ){
				last = i;
				break;
			}
		}
		printf( "%d\n", last + 1 );
		if( last >= 0 ){
			it = dp[last].begin();
			vector<bool> ans;
			while( last > 0 ){
				it2 = dp[last-1].find( it->first - car[last] );
				if( it2 != dp[last-1].end() ){
					// port
					ans.push_back(true);
					it = it2;
				}
				else{
					// starboard
					it2 = dp[last-1].find( it->first );
					ans.push_back(false);
					it = it2;
				}
				--last;
			}
			if( last == 0 ){
				ans.push_back( it->second == 0 );
			}
			for( int i=ans.size()-1; i>=0; --i ){
				puts( ans[i] ? "port" : "starboard" );
			}
		}
		if(t) putchar( '\n' );
	}
}
