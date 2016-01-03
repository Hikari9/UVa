/**
	UVa 11787 - Numeral Heiroglyphs
	by Rico Tiongson
	Submitted: May 15, 2013
	Accepted 0.012s C++
	O(n) time
*/
#include<iostream>
using namespace std;
// B U S P F T M
int Index[26],count[7],n,ans;
char buf[100005];
bool ups,downs;
bool Error(){
	for(int i=0;i<7;i++) count[i] = 0;
	ups = false;
	downs = false;
	if(buf[0]=='\0'){
		ans = 0;
		return false;
	}
	buf[0]-='A';
	count[Index[buf[0]]]++;
	for(int i=1;buf[i]!='\0';i++){
		buf[i]-='A';
		if(Index[buf[i]] > Index[buf[i-1]]){
			if(downs) return true;
			ups = true;
		}
		else if(Index[buf[i]] < Index[buf[i-1]]){
			if(ups) return true;
			downs = true;
		}
		count[Index[buf[i]]]++;
	}
	ans = 0;
	for(int i=6;i>-1;i--){
		if(count[i]>9) return true;
		ans = ans*10 + count[i];
	}
	return false;
}
int main(){
	Index[1] = 0; //B
	Index[20] = 1; //U
	Index[18] = 2; //S
	Index[15] = 3; //P
	Index[5] = 4; //F
	Index[19] = 5; //T
	Index[12] = 6; //M
	cin >> n;
	while(n--){
		cin >> buf;
		if(Error()) cout << "error" << endl;
		else cout << ans << endl;
	}
}
