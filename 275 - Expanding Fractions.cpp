/**
	UVa 275 - Expanding Fractions
	by Rico Tiongson
	Submitted: August 25, 2013
	Accepted 0.016s C++
	O(nlogn) time
*/
#include<iostream>
#include<map>
using namespace std;
int n, d, hold, c;
bool f;
map<int,int> m;
pair<map<int,int>::iterator,bool> it;
int main(){
	while( cin >> n >> d, n||d ){
		cout << '.';
		n %= d;
		m.clear();
		hold = n;
		c = 1;
		while( hold && ((it=m.insert(make_pair(hold,m.size()))).second) ){
			if( c++==50 ){
				cout << endl;
				c = 1;
			}
			n = hold*10;
			hold = n/d;
			cout << hold;
			hold = n-(hold*d);
		}
		cout << endl;
		if(hold){
			cout << "The last " << (m.size()-it.first->second) << " digits repeat forever." << endl;
		}
		else{
			cout << "This expansion terminates." << endl;
		}
		cout << endl;
	}
}
