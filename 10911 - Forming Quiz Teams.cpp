/**
	UVa 10911 - Forming Quiz Teams
	by Rico Tiongson
	Submitted: May 21, 2013
	Accepted 0.415s C++
	O(2^n) time
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point{
	int x,y;
	Point(){}
	Point(int X,int Y):x(X),y(Y){}
} G[20];
int n,n2,a,b,mxbit,r(0);
double d[20][20],bits[65536]; //bitset array
string s;
double Dist(const Point& lhs, const Point& rhs){
	double x=lhs.x-rhs.x, y=lhs.y-rhs.y;
	return sqrt(x*x+y*y);
}
double DP(int x){
	if(x==mxbit) return 0.0;
	else if(bits[x]==-1){ //get new bit
		double mn = HUGE_VAL;
		for(int i=0,i1=1;i<n2;i++,i1*=2){
			if(!(x&i1)){ //no unique bits
				for(int j=i+1,j1=i1*2;j<n2;j++,j1*=2){
					if(!(x&j1)) mn = min(mn,d[i][j]+DP(x|i1|j1)); //DP for union of bitsets
				}
			}
		}
		bits[x] = mn;
	}
	return bits[x];
}
int main(){
	cout.precision(2);
	cout << fixed;
	while(cin >> n,n){
		n2 = n<<1;
		for(int i=0;i<n2;i++) cin >> s >> G[i].x >> G[i].y;
		for(int i=0;i<n2;i++){
			for(int j=i+1;j<n2;j++){
				d[i][j] = d[j][i] = Dist(G[i],G[j]);
			}
		}
		mxbit = 1<<n2;
		fill(bits,bits+mxbit,-1); //unvisit
		mxbit--;
		cout << "Case " << ++r << ": " << DP(0) << endl;
	}
}
