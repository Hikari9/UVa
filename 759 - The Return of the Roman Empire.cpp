/**
	UVa 759 - The Return of the Roman Empire
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.229s C++
	O(nlogn) pre-gen + O(logn) time
*/
#include<iostream>
#include<map>
using namespace std;
map<string,int> roman;
map<string,int>::iterator it;
string s;
int i;
string romanNumeral( int x ){
	s.clear();
	switch( x/1000 ){
		case 3:
			s += 'M';
		case 2:
			s += 'M';
		case 1:
			s += 'M';
			break;
	}
	x %= 1000;
	if( x/100 == 9 ){
		s += "CM";
		x -= 900;
	}
	else if( x/100 > 4 ){
		s += 'D';
		x -= 500;
	}
	switch( x/100 ){
		case 4:
			s += "CD";
			break;
		case 3:
			s += 'C';
		case 2:
			s += 'C';
		case 1:
			s += 'C';
			break;
	}
	x %= 100;
	if( x/10 == 9 ){
		s += "XC";
		x -= 90;
	}
	else if( x/10 > 4 ){
		s += 'L';
		x -= 50;
	}
	switch( x/10 ){
		case 4:
			s += "XL";
			break;
		case 3:
			s += 'X';
		case 2:
			s += 'X';
		case 1:
			s += 'X';
			break;
	}
	x %= 10;
	if( x == 9 ){
		s += "IX";
		x -= 9;
	}
	else if( x > 4 ){
		s += 'V';
		x -= 5;
	}
	switch( x ){
		case 4:
			s += "IV";
			break;
		case 3:
			s += 'I';
		case 2:
			s += 'I';
		case 1:
			s += 'I';
			break;
	}
	return s;
}
string& trim( string& S ){
	for( i=S.size()-1; i>=0; --i ){
		if( S[i]!=' ' ) break;
	}
	if( i+1!=S.size() ) S = S.substr(0,i+1);
	return S;
}
int main(){
	for( i=0; i<4000; ++i ){
		roman[romanNumeral(i)] = i;
	}
	while( getline(cin,s) ){
		it=roman.find(trim(s));
		if( it == roman.end() ){
			cout << "This is not a valid number" << endl;
		}
		else{
			cout << it->second << endl;
		}
	}
}
