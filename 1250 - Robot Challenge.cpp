/**
	UVa 1250 - Robot Challenge
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.132 C++
	O(n^2) time
*/
#include<iostream>
#include<cmath>
using namespace std;
struct node{
	int x,y;
	double path;
	int pen;
	void in(){
		cin >> x >> y >> pen;
	}
}End;
double Dist(const node& a, const node& b){
	int x=a.x-b.x,y=a.y-b.y;
	return sqrt(x*x+y*y);
}
int main(){
	int n;
	node N[1002];
	int pen[1002];
	node* mn;
	pen[0]=0;
		N->x=0;
		N->y=0;
		N->pen=0;
		N->path=0;
	End.x=100;
	End.y=100;
	End.pen=0;
	End.path=0;
	while(cin >> n,n){
		for(int i=1;i<=n;i++){
			N[i].in();
			pen[i] = pen[i-1] + N[i].pen;
		}
		N[++n] = End;
		for(int j=1;j<=n;j++){
			N[j].path = pen[j-1]+Dist(N[0],N[j])+1.0;
		}
		for(int i=1;i<n;i++){
			mn = &N[i+1];
			for(int j=i+1;j<=n;j++){
				N[j].path = min(N[j].path,N[i].path+pen[j-1]-pen[i]+Dist(N[i],N[j])+1.0);
				if(N[j].path<mn->path)
					mn = &N[j];
			}
			if(mn==&N[n]) break;
		}
		cout.precision(3);
		cout << fixed << N[n].path << endl;
	}
}
