/**
	UVa 10409 - Die Game
	by Rico Tiongson
	Submitted: October 19, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#include<map>
using namespace std;
typedef void (*function)();

int TOP, NORTH, WEST;

int OPPOSITE( int x ){ return 7-x; }
#define BOTTOM OPPOSITE(TOP)
#define EAST OPPOSITE(WEST)
#define SOUTH OPPOSITE(NORTH)

void north(){
	int temp = TOP;
	TOP = SOUTH;
	NORTH = temp;
}
void east(){
	int temp = BOTTOM;
	TOP = WEST;
	WEST = temp;
}
void south(){
	int temp = BOTTOM;
	TOP = NORTH;
	NORTH = temp;
}
void west(){
	int temp = TOP;
	TOP = EAST;
	WEST = temp;
}

int main(){
	int n;
	string s;
	map<string, function> m;
	m["north"] = north;
	m["east"] = east;
	m["south"] = south;
	m["west"] = west;
	while( cin >> n, n ){
		TOP = 1;
		NORTH = 2;
		WEST = 3;
		while(n--){
			cin >> s;
			(*m[s])();
		}
		cout << TOP << endl;
	}
	
}
