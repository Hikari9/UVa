// 12073 - Altitude Triangle
// Accepted 27 May 2013 by Henry Morco
// Demonstrates potential of barycenters in determining special points wrt triangles (excenters in this example)
// optimized c++ with Pointers mod hehe -rico
#include<stdio.h>
#include<math.h>

struct point{
	double x,y;
	point(){}
	point(const double& X, const double& Y) : x(X), y(Y){}
	void display()const{
		printf("%.3lf %.3lf\n",x,y);
	}
};

double dist(const point& a, const point& b){
	double x=a.x-b.x, y=a.y-b.y;
	return sqrt(x*x+y*y);
}

struct triangle{
	point *A,*B,*C;
	double a,b,c;

	triangle(point& Aa, point& Bb, point& Cc) : A(&Aa), B(&Bb), C(&Cc){
		a = dist(*B,*C);
		b = dist(*A,*C);
		c = dist(*A,*B);
	}

	point bary(const double& ba, const double& bb, const double& bc)const{
		double sum = (ba) + (bb) + (bc);
		return point((A->x*ba + B->x*bb + C->x*bc)/sum,(A->y*ba + B->y*bb + C->y*bc)/sum);
	}
	point ex0()const{ return bary(-a,b,c); }
	point ex1()const{ return bary(a,-b,c); }
	point ex2()const{ return bary(a,b,-c); }
};
int counter(0);
point a,b,c;
int main(){
	scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	
	while(a.x||a.y||b.x||b.y||c.x||c.y){
		printf("Case %d:\n",++counter);
		triangle S = triangle(a,b,c);
		S.ex0().display();
		S.ex1().display();
		S.ex2().display();
		scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	}
	
}
