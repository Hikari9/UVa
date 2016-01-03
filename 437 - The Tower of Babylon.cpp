/**
	UVa 437 - The Tower of Babylon
	by Rico Tiongson
	Submitted: September 20, 2013
	Accepted 0.015s C++
	O(3n^2) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
#define MX 35
using namespace std;
struct block{
	private:
		int x, y, z;
	public:
		int length()const{ return x; }
		int width()const{ return y; }
		int height()const{ return z; }
		void normalize(){
			if( x>y ) swap(x,y);
		}
		block() {}
		block( int X, int Y, int Z ): x(X), y(Y), z(Z) {}
		block( const block& _ ): x(_.x), y(_.y), z(_.z) { normalize(); }
		void rotate(){
			swap(x,y);
			swap(y,z);
		}
		void in(){
			cin >> x >> y >> z;
		}
		void out() const{
			cout << x << " " << y << " " << z << endl;
		}
		bool operator<( const block& _ ) const{
			return ( x < _.x || ( x==_.x && y < _.y ) );
		}
} b;
vector<block> v;
int n, i, j, tc, h;
int dp[95];
int main(){
	while( cin >> n, n ){
		v.clear();
		for( i=0; i<n; ++i ){
			b.in();
			for( j=0; j<3; ++j ){
				v.push_back( block(b) );
				b.rotate();
			}
		}
		sort( v.begin(), v.end() );
		memset( dp, -1, sizeof dp );
		for( i=0; i<v.size(); ++i ){
			if( dp[i]==-1 ) dp[i] = v[i].height();
			for( j=i+1; j<v.size(); ++j ){
				if( v[i].length() == v[j].length() ) continue;
				if( v[i].width() < v[j].width() ){
					dp[j] = max( dp[i]+v[j].height(), dp[j] );
				}
			}
		}
		h = 0;
		for( i=0; i<v.size(); ++i ){
			h = max( dp[i], h );
		}
		cout << "Case " << ++tc << ": maximum height = " << h << endl;
	}
}
