/**
	UVa 815 - Flooded!
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.052s C++
	O(2nlogn) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r=0;
double x[1001],W,level;
bool found;
int main(){
	x[0] = 0.;
	cout.precision(2);
	cout << fixed;
	while(cin >> m >> n,m||n){
		m*=n;
		for(int i=1;i<=m;i++) cin >> x[i];
		cin >> W;
		sort(x+1,x+m+1);
		found = false;
		for(int i=1;i<m;i++){
			level = (i)*(x[i+1]-x[i])*100;
			if(W>level) W-=level;
			else{
				found = true;
				if(!W){
					level = x[i-1];
					W = 100.*(i-1)/m;
				}
				else{
					level = W/(i)/100. + x[i];
					W = 100.*i/m;
				}
				break;
			}
		}
		if(!found){
			level = W/m/100. + x[m];
			W = 100.;
		}
		cout << "Region " << ++r << endl;
		cout << "Water level is " << level << " meters." << endl;
		cout << W << " percent of the region is under water." << endl << endl;
	}
}
