/**
	UVa 476 - Points in Figures: Rectangles
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.075s C++
	O(n) time
*/
#include<iostream>
#include<vector>
using namespace std;
struct rect{
	double x[2],y[2];
	rect(){
		cin >> x[0] >> y[1] >> x[1] >> y[0];
	}
};
int main(){
	char r;
	vector<rect> v;
	while(cin >> r,r!='*')
		v.push_back(rect());
	double x, y;
	int n=0;
	bool ok;
	while(cin >> x >> y, x!=9999.9 && y!=9999.9){
		n++;
		ok = false;
		for(int i=0;i<v.size();i++){
			if( x > v[i].x[0] && x < v[i].x[1] && y > v[i].y[0] && y < v[i].y[1] ){
				cout << "Point " << n << " is contained in figure " << i+1 << endl;
				ok = true;
			}
		}
		if(!ok) cout << "Point " << n << " is not contained in any figure" << endl;
	}
}
