/**
	UVa 620 - Cellular Structure
	by Rico Tiongson
	Submitted: September 13, 2013
	Accepted 0.015s C++
	O(n) time
*/
#include<iostream>
#define mutant cout << "MUTANT" << endl
#define simple cout << "SIMPLE" << endl
#define full cout << "FULLY-GROWN" << endl
#define mutagenic cout << "MUTAGENIC" << endl
using namespace std;
int n, i, j;
string s;
int main(){
	cin >> n;
	outer:
	while(n--){
		cin >> s;
		if( (s.length()&1) == 0 ){
			mutant;
			continue;
		}
		i = 0;
		j = s.length() - 1;
		while( i < j ){
			if( s[i]=='B' && s[j]=='A' ){
				++i, --j;
			}
			else if( j>0 && s[j]=='B' && s[j-1]=='A' ){
				j -= 2;
			}
			else{
				mutant;
				goto outer;
			}
		}
		if( s[i]!='A' ){
			mutant;
			continue;
		}
		j = s.length()-1;
		if( s[0]=='B' && s[j]=='A' ){
			mutagenic;
			continue;
		}
		if( j>0 && s[j]=='B' && s[j-1]=='A' ){
			full;
			continue;
		}
		simple;
	}
}
