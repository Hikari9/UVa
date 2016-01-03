/**
	UVa 10098 - Generating Fast
	by Rico Tiongson
	Submitted: May 11, 2013
	Accepted 0.865s C++
	O(nlogn) time
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,len;
	char c[12];
	cin.getline(c,12);
	n = atoi(c);
	while(n--){
		cin.getline(c,12);
		len = strlen(c);
		sort(c,c+len);
		do{
			cout << c << endl;
		} while(next_permutation(c,c+len));
		cout << endl;
	}
}
