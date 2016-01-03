/**
	UVa 10276 - Hanoi Tower Troubles Again!
	by Rico Tiongson
	Submitted: May 5, 2013
	Accepted: 0.015s C++
	O(1) time [pre-gen DFS]
*/
#include<iostream>
using namespace std;
int main(){
	int t,x,n[]={0,1,3,7,11,17,23,31,39,49,59,71,83,97,111,127,143,161,179,199,219,241,263,287,311,337,363,391,419,449,479,511,543,577,611,647,683,721,759,799,839,881,923,967,1011,1057,1103,1151,1199,1249,1299};
	cin >> t;
	while(t--){
		cin >> x;
		cout << n[x] << endl;
	}
}
