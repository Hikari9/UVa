/**
	UVa 466 - Mirror, Mirror
	by Rico Tiongson
	Submitted: May 25, 2013
	Accepted 0.016s C++
	O(10.5n^2) time
*/
#include<iostream>
#include<algorithm>
using namespace std;
char c[3][12][12];
int n,n2,r=0;
bool same1(){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(c[0][i][j]!=c[1][i][j]) return false;
	return true;
}
bool same2(){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(c[0][i][j]!=c[2][i][j]) return false;
	return true;
}
void reflect(){
	for(int i=0;i<n2;i++)
	for(int j=0;j<n;j++)
	swap(c[2][i][j],c[2][n-i-1][j]);
}
const char* f(){
	//preserve
	if(same1()) return "preserved.";
	
	//90 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][j][n-i-1];
	if(same2()) return "rotated 90 degrees.";
	
	//180 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][n-i-1][n-j-1];
	if(same2()) return "rotated 180 degrees.";
	
	//270 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][n-j-1][i];
	if(same2()) return "rotated 270 degrees.";
	
	//vertical reflect
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][n-i-1][j];
	if(same2()) return "reflected vertically.";
	
	n2 = n/2;
	//v90 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][j][n-i-1];
	reflect();
	if(same2()) return "reflected vertically and rotated 90 degrees.";
	
	//v180 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][n-i-1][n-j-1];
	reflect();
	if(same2()) return "reflected vertically and rotated 180 degrees.";
	
	//v270 deg
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	c[2][i][j] = c[1][n-j-1][i];
	reflect();
	if(same2()) return "reflected vertically and rotated 270 degrees.";
	
	return "improperly transformed.";
}
int main(){
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> c[0][i] >> c[1][i];
		cout << "Pattern " << ++r << " was " << f() << endl;
	}
}
