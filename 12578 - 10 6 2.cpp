/**
	UVa 12578 - 10:6:2
	by Rico Tiongson
	Submitted: June 29, 2013
	Accepted 0.022s C++
	O(1) time
*/
#include<cstdio>
#include<cmath>
const double PI( acos(-1.0) );
double green, red;
int t, l;
int main(){
	scanf("%d",&t);
	while( t ){
		scanf("%d",&l);
		red = green = l/5.0;
		green *= l*3.0;
		red *= red*PI;
		green -= red;
		printf("%.2lf %.2lf\n",red,green);
		--t;
	}
}
