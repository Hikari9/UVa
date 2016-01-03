/**
	UVa 11345 - Rectangles
	by Rico Tiongson
	Submitted: Feb 2, 2014
	Accepted 0.052s C++
	O(n) time
*/
#include <iostream>
using namespace std;

int n, m;
int a, b, c, d;
int e, f, g, h;

int main(){
	cin >> n;
	for( int tc=1; tc<=n; ++tc ){
		cin >> m;
		e = -10001;
		f = -10001;
		g = 10001;
		h = 10001;
		for( int i=0; i<m; ++i ){
			cin >> a >> b >> c >> d;
			e = max(e, a);
			f = max(f, b);
			g = min(g, c);
			h = min(h, d);
		}
		cout << "Case " << tc << ": ";
		if( e < g && f < h ){
			cout << (g-e) * (h-f) << endl;
		}
		else{
			cout << "0" << endl;
		}
	}
}
