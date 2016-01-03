/**
	UVa 10683 - The decadary watch
	by Rico Tiongson
	Submitted: August 26, 2013
	Accepted 0.039s C++
	O(1) time
*/
#include<cstdio>
using namespace std;
char buf[10];
int hh, mm, ss, cc, D = 8640000;
long long d;
int main(){
	while( gets(buf) ){
		hh = (buf[0]-'0')*10 + buf[1]-'0';
		mm = (buf[2]-'0')*10 + buf[3]-'0';
		ss = (buf[4]-'0')*10 + buf[5]-'0';
		cc = (buf[6]-'0')*10 + buf[7]-'0';
		d = (long long)(cc + ss*100 + mm*6000 + hh*360000)*10000000LL;
		printf( "%07d\n", int(d/D) );
	}
}
