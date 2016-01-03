/**
	UVa 10205 - Stack 'em Up
	by Rico Tiongson
	Submitted: March 20, 2013
	Accepted 0.012s C++
	O(n) time
*/
#include<iostream>
#include<vector>
#include<map>
#include<cstring>
#include<sstream>
using namespace std;
int hold,deck[53];
string names[14]={"","2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
struct shuff{
	int c[53];
	shuff(){memset(c,0,53);}
	void reset(){memset(c,0,53);}
	void in(){for(int i=1;i<53;i++) cin >>c[i];}
	void shuffle(){
		int newdeck[53];
		for(int i=1;i<53;i++){
			newdeck[i]=deck[c[i]];
		}
		for(int i=1;i<53;i++) deck[i]=newdeck[i];
	}
};
map<int,shuff> m;
void printdeck(){
	string suit;
	int x;
	for(int i=1;i<53;i++){
		x=deck[i];
		if(x>39){
			suit="Spades";
			x-=39;
		}
		else if(x>26){
			suit="Hearts";
			x-=26;
		}
		else if(x>13){
			suit="Diamonds";
			x-=13;
		}
		else suit="Clubs";
		cout << names[x] << " of " << suit << endl;
	}
}
int main(){
	int t,n,u;
	string buffer;
	cin >> t;
	while(t--){
		m.clear();
		for(int i=0;i<53;i++) deck[i]=i;
		cin >> n;
		for(int i=1;i<=n;i++){
			shuff s;
			s.in();
			m.insert(pair<int,shuff>(i,s));
		}
		cin.ignore();
		while(getline(cin,buffer),buffer!=""){
			istringstream(buffer)>>u;
			m[u].shuffle();
		}
		printdeck();
		if(t) cout << endl;
	}
}
