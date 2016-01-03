/**
	UVa 11519 - Logo 2
	by Rico Tiongson
	Submitted: September 26, 2013
	Accepted 0.105s C++
	O(n^2) time
*/
#include<cstdio>
#include<cmath>
using namespace std;

const double PI( acos(-1.0) );

int t, n, i, q;
char c[1001], buf[100];
int d[1001], ans;
double x, y, a, d1, d2;

double rad( double _ ){ return _*PI/180.0; }
void check( int id ){
	switch(c[id]){
		case 'f':
			x += d[id] * cos(a);
			y += d[id] * sin(a);
			break;
		case 'b':
			x -= d[id] * cos(a);
			y -= d[id] * sin(a);
			break;
		case 'l':
			a += rad(d[id]);
			break;
		case 'r':
			a -= rad(d[id]);
	}
}
void makePoint(){
	a = x = y = 0.0;
	for( i=0; i<n; ++i )
		check(i);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for( i=0; i<n; ++i ){
			scanf("%s",buf);
			c[i] = buf[0];
			scanf("%s",buf);
			if( buf[0]=='?' )
				q = i;
			else
				sscanf(buf,"%d",d+i);
		}
		if( c[q]=='f' || c[q]=='b' ){
			d[q] = 0;
			makePoint();
			ans = round(hypot(x,y));
			d[q] = ans;
			makePoint();
			d1 = hypot(x,y);
			d[q] = -ans;
			makePoint();
			d2 = hypot(x,y);
			if( d1 > d2 ) ans *= -1;
		}
		else{
			for( ans=0; ans<360; ++ans ){
				d[q] = ans;
				makePoint();
				if( abs(x)<0.01 && abs(y)<0.01 ) break;
			}
		}
		// printf( " %c ", c[q] );
		printf("%d\n",ans);
	}
}
