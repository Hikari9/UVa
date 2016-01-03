/**
	UVa 10341 - Solve It
	by Rico Tiongson
	Submitted: June 10, 2013
	Accepted 0.025s C++
	O(newton) time
*/
#include<cstdio>
#include<cmath>
const double eps(1e-9);
int p,q,r,s,t,u;
double ans;
double cos2( double x ){
	x = cos(x);
	return x*x;
}
double f( double x ){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
double f_prime( double x ){
	return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos2(x)) + 2*t*x;
}
double newton(){
	if(f(0.)==0.) return 0.;
	double x=0.5, x1;
	while(x<2){
		x1 = x-f(x)/f_prime(x);
		if( fabs(x-x1) < eps ) return x;
		x = x1; //prev value
	}
	return -1,0;
}
int main(){
	while( scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF ){
		if(f(0.)*f(1.)>0.) puts("No solution");
		else printf("%.4lf\n",newton());
	}
}
