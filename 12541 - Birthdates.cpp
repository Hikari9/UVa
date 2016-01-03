/**
	UVa 12541 - Birthdates
	by Rico Tiongson
	Submitted: May 17, 2013
	Accepted 0.013s C++
	O(n) time
*/
#include<iostream>
using namespace std;
struct bDay{
	string name;
	int year, month, day;
	bDay(){
		cin >> name >> day >> month >> year;
	}
	bool operator<(const bDay& rhs) const{
		return year==rhs.year ?( month==rhs.month ? day < rhs.day : month < rhs.month ) : year < rhs.year;
	}
} *mn, *mx, *x;
int main(){
	int n;
	cin >> n;
	mn = mx = new bDay;
	while(--n>0){
		x = new bDay;
		if(*x<*mn) mn = x;
		if(*mx<*x) mx = x;
	}
	cout << mx->name << endl << mn->name << endl;
}
