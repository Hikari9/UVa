/**
	UVa 10245 - The Closest Pair Problem
	by Rico Tiongson
	Submitted: May 19, 2013
	Accepted 2.499s C++
	O(n^2) time
*/
#include<iostream>
#include<cmath>
using namespace std;
typedef long double lag;
typedef pair<lag,lag> Point;
lag Dist(const Point& a, const Point& b){
	lag x = a.first-b.first, y = a.second-b.second;
	return x*x + y*y;
}
int main(){
	cout.precision(4);
	cout << fixed;
	unsigned n;
	lag dist;
	Point x[10005];
	while(cin >> n,n){
		dist = 100000001.0;
		for(unsigned i=0;i<n;i++)
			cin >> x[i].first >> x[i].second;
		for(unsigned i=0;i<n;i++){
			for(unsigned j=i+1;j<n;j++){
				dist = min(dist,Dist(x[i],x[j]));
			}
		}
		if(dist==100000001.0) cout << "INFINITY" << endl;
		else cout << sqrt(dist) << endl;
	}
}
