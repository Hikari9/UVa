/**
	UVa 10281 - Average Speed
	by Rico Tiongson
	Submitted: August 16, 2013
	Accepted 0.016s C++
	O(1) time
*/
#include<cstdio>
#include<cstring>
using namespace std;
int h, m, s, speed;
int prevTime;
double curKM;
char buf[10005], *p;
int main(){
	while( gets(buf) ){
		p = strtok( buf, " " );
		sscanf( p, "%d:%d:%d", &h, &m, &s );
		s += m*60 + h*3600;
		curKM += ((s - prevTime)*speed);
		if( (p=strtok(NULL," "))==NULL ) // no speedometer
			printf( "%s %.2lf km\n", buf, curKM/3600.0 );
		else
			sscanf( p, "%d", &speed );
		prevTime = s;
	}
}
