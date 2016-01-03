/**
	UVa 11479 - Is this the easiest problem?
	by Rico Tiongson
	Submitted: May 16, 2013
	Accepted 0.009s C++
	O(5) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long x[3],n,r=0;
	cin >> n;
	while(r++<n){
		cin >> x[0] >> x[1] >> x[2];
		sort(x,x+3);
		cout << "Case " << r << ": ";
		if(x[0]<=0||x[0]+x[1]<=x[2]) cout << "Invalid" << endl;
		else{
			if(x[0]==x[1] && x[1]==x[2]) cout << "Equilateral" << endl;
			else if(x[0]==x[1]||x[1]==x[2]) cout << "Isosceles" << endl;
			else cout << "Scalene" << endl;
		}
	}
}
