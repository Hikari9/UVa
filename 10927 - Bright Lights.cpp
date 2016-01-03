/**
	UVa 10927 - Bright Lights
	by Rico Tiongson
	Submitted: September 26, 2013
	Accepted 0.425s C++
	O(nlogn) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define MX 100005
using namespace std;
typedef long long lag;
int gcd( int a, int b ){
	if( a<0 ) a = -a;
	if( b<0 ) b = -b;
	int temp;
	while(a){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
struct point{
	int x, y, z;
	bool operator<( const point& p )const{
		// if( z==p.z ){
			return (lag)x*x + (lag)y*y < (lag)p.x*p.x + (lag)p.y*p.y;
		// }
		// return z > p.z;
	}
} p[MX];
bool cmp( const point& a, const point& b ){
	if( a.x==b.x ) return a.y < b.y;
	return a.x < b.x;
}
int n, i, g, tc;
map< pair<int,int>, int > s;
vector<point> ans;
int main(){
	while( cin >> n, n ){
		for( i=0; i<n; ++i ){
			cin >> p[i].x >> p[i].y >> p[i].z;
		}
		sort( p, p+n );
		s.clear();
		ans.clear();
		for( i=0; i<n; ++i ){
			// cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
			g = gcd( p[i].x, p[i].y );
			pair<int,int> pr( p[i].x/g, p[i].y/g );
			if( s.count(pr) ){
				int& r = s[pr];
				// cout << "COUNT: " << r << endl;
				if( r>=p[i].z ) ans.push_back( p[i] );
				r = max( r, p[i].z );
			}
			else{
				s[pr] = p[i].z;
			}
		}
		
		cout << "Data set " << ++tc << ":\n";
		if( ans.empty() ){
			cout << "All the lights are visible." << endl;
		}
		else{
			cout << "Some lights are not visible:" << endl;
			sort( ans.begin(), ans.end(), cmp );
			for( i=0; i<ans.size(); ++i ){
				cout << "x = " << ans[i].x << ", y = " << ans[i].y;
				if( i+1 < ans.size() ) cout << ';';
				else cout << '.';
				cout << endl;
			}
		}
	}
}
