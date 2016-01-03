/**
	UVa 384 - Slurpys
	by Rico Tiongson
	Submitted: September 11, 2013
	Accepted 0.016s C++
	O(?) time
*/
#include<iostream>
using namespace std;

string s;
int slump( int st ){
	if( st>=s.length() ) return -1;
	if( s[st]!='E' && s[st]!='D' ) return -1;
	// get F's
	bool hasF = false;
	for( st=st+1; st<s.length(); ++st ){
		if( s[st]!='F' ) break;
		hasF = true;
	}
	if( !hasF || st==s.length() ) return -1;
	if( s[st]=='G' ) return st+1;
	return slump(st);
}
int slimp( int st ){
	if( st + 2 >= s.length() ) return -1;
	if( s[st]!='A' ) return -1;
	if( s[st+1]=='H' ) return st+2;
	if( s[st+1]=='B' ){
		int nextId = slimp(st+2);
		if( nextId==-1 || nextId+1==s.length() ) return -1;
		return s[nextId]=='C' ? nextId+1 : -1;
	}
	int nextId = slump(st+1);
	if( nextId==-1 || nextId+1>=s.length() ) return -1;
	return s[nextId]=='C' ? nextId+1 : -1;
}

int n, i;
int main(){
	cin >> n;
	cout << "SLURPYS OUTPUT" << endl;
	while(n--){
		cin >> s;
		i = slimp(0);
		if(i==-1){
			cout << "NO" << endl;
			continue;
		}
		i = slump(i);
		if( i==s.length() ){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
}
