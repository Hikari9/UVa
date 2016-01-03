/**
	UVa 10591 - Happy Number
	by Rico Tiongson
	Submitted: May 7, 2013
	Accepted 0.019s C++
	O(nlogn) time
*/
#include<iostream>
#include<set>
using namespace std;
int main(){
	int n,x,y,t,r=0;
	cin >> t;
	set<int> s;
	pair<set<int>::iterator,bool> checker;
	while(r++<t){
		cin >> n;
		cout << "Case #" << r << ": " << n << " is a";
		s.clear();
		while((checker=s.insert(n)).second){
			x=0;
			while(n!=0){
				y=n%10;
				x+=y*y;
				n/=10;
			}
			n=x;
		}
		if(*checker.first==1) cout << " Happy number." << endl;
		else cout << "n Unhappy number." << endl;
	}
}
