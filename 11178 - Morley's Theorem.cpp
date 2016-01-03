/**
	UVa 11178 - Morley's Theorem
	by Rico Tiongson
	Submitted: June 11, 2013
	Accepted 0.109s C++
	constant time
*/
#define RAW_TRIANGLE
#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
#include<algorithm>

#define TYPEp template<class pType>
#define TYPEpp template<class pType> typename pType::value_type
#define fTYPEpp template<class pType> friend typename pType::value_type
#define TYPEo template<class oType>
#define TYPE2o template<class oType, class oType2>
#define TYPE3o template<class oType, class oType2, class oType3>
#define TYPE3e template<class Type, class pType=point<Type>, class cType=std::vector<pType> >
#define TYPE3 template<class Type, class pType, class cType>
#define TYPE2e template<class Type, class pType=point<Type> >
#define TYPE2 template<class Type, class pType>
#define TYPE1 template<class Type>
#ifndef PI
	#define PI acos(-1.0)
#endif
TYPE1 Type gcd( Type a, Type b ){
	Type temp;
	while(a>0){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}

enum WiseType{ counterclockwise=0, clockwise };

TYPE1 long double RAD( const Type& _ ){ return _ * PI/180.; }
TYPE1 long double DEG( const Type& _ ){ return _*180./PI; }

TYPEpp dist2( const pType& a, const pType& b ){ return a.dist2(b); }
TYPEpp dist( const pType& a, const pType& b ){ return sqrt( dist2(a,b) ); }
TYPEpp cross_product( const pType& a, const pType& b ){ return a.cross_product(b); }
TYPEpp cross_product( const pType& a, const pType& b, const pType& c ){ return a.cross_product(b,c); }
TYPEpp dot_product( const pType& a, const pType& b ){ return a.dot_product(b); }
TYPEpp dx( const pType& a, const pType& b ){ return b.x-a.x; }
TYPEpp dy( const pType& a, const pType& b ){ return b.y-a.y; }
TYPEpp dz( const pType& a, const pType& b ){ return b.z-a.z; }
TYPEpp angle( const pType& a, const pType& b ){ return a.angle(b); }
TYPEpp vector_angle( const pType& a, const pType& b ){ return a.vector_angle(b); }
TYPEpp angle( const pType& a, const pType& b, const pType& c ){ return b.angle(a,c); }
			
namespace geom3D{
	TYPE1 class point;
	// TYPE1 class vector;
	// TYPE1 class line;
	// TYPE1 class segment;
	// TYPE1 class ray;
	// TYPE2 class sphere;
	// TYPE2 class cone;
	// TYPE3 class prism;
	// TYPE3 class polyhedra;
	// TYPE3 class pyramid;
	
	TYPE1 class point{
		public:
			Type x, y, z;
			typedef Type value_type;
			point(){}
			point( const Type& a, const Type& b, const Type& c ): x(a), y(b), z(c) {}
			// TYPEo bool isInPolygon( const oType& P ){
			// }
	};
}
namespace geom2D{
	TYPE1 class point;
	// TYPE1 class vector;
	TYPE1 class line;
	TYPE1 class segment;
	TYPE1 class ray;
	TYPE3e class polygon;
	TYPE2e class triangle;
	TYPE2e class circle;
	// TYPE2 class ellips;
	
	TYPE1 point<Type> triangle_bary( const triangle<Type,point<Type> >& _, const Type& ba, const Type& bb, const Type& bc ){
		Type Sum(ba+bb+bc);
		return point<Type>( ( _.A.x*ba + _.B.x*bb + _.C.x*bc )/Sum, ( _.A.y*ba + _.B.y*bb + _.C.y*bc )/Sum ); 
	}
	TYPE1 geom3D::point<Type> triangle_bary( const triangle<Type,geom3D::point<Type> >& _, const Type& ba, const Type& bb, const Type& bc ){
		Type Sum(ba+bb+bc);
		return geom3D::point<Type>( ( _.A.x*ba + _.B.x*bb + _.C.x*bc )/Sum, ( _.A.y*ba + _.B.y*bb + _.C.y*bc )/Sum, ( _.A.z*ba + _.B.z*bb + _.C.z*bc )/Sum ); 
	}
	
	TYPE1 class point{
		
		public:
			typedef Type value_type;
			Type x, y;
			point(){}
			point( const Type& a, const Type& b ): x(a), y(b) {}
			TYPEo bool isInPolygon( const oType& P )const{
				bool in(false);
				for(int i=0, j=P.size()-1; i<P.size(); j=i++)
					if(((P.vertex(i).y>y)!=(P.vertex(j).y>y))&&(x<dx(P.vertex(i),P.vertex(j))*dy(P.vertex(i),*this)/dy(P.vertex(i),P.vertex(j))+P.vertex(i).x)) in = !in;
				return in;
			}
			TYPEo bool isOnPolygon( const oType& P )const{
				for(int i=0, j=P.size()-1; i<P.size(); j=i++)
					if(segment<Type>(P.vertex(i),P.vertex(j)).contains(*this)) return true;
				return false;
			}
			bool isInCircle( const circle<Type,point<Type> >& C )const{ return dist2( C.center ) < C.r*C.r; }
			bool isOnCircle( const circle<Type,point<Type> >& C )const{ return dist2( C.center ) == C.r*C.r; }
			point& operator=( const point& _ ){ x = _.x, y=_.y; return *this; }
			bool operator==( const point& _ )const{ return x==_.x && y==_.y; }
			bool operator!=( const point& _ )const{ return !operator==(_); }
			bool operator<( const point& _ )const{ return y==_.y ? x<_.x : y<_.y; }
			bool operator<=( const point& _ )const{ return y==_.y ? x<=_.x : y<_.y; }
			bool operator>( const point& _ )const{ return y==_.y ? x>_.x : y>_.y; }
			bool operator>=( const point& _ )const{ return y==_.y ? x>=_.x : y>_.y; }
			
			// scalar point operations
			point& operator+=( const Type& _ ){ x+=_; y+=_; return *this; }
			point& operator+=( const point& _ ){ x+=_.x; y+=_.y; return *this; }
			point operator+( const Type& _ )const{ return point(x+_,y+_); }
			point operator+( const point& _ )const{ return point(x+_.x,y+_.y); }
			
			point& operator-=( const Type& _ ){ x-=_; y-=_; return *this; }
			point& operator-=( const point& _ ){ x-=_.x; y-=_.y; return *this; }
			point operator-( const Type& _ )const{ return point(x-_, y-_); }
			point operator-( const point& _ )const{ return point(x-_.x, y-_.y); }
			
			point& operator*=( const Type& _ )const{ x*=_; y*=_; return *this; }
			point& operator*=( const point& _ )const{ x*=_.x; y*=_.y; return *this; }
			point operator*( const Type& _ )const{ return point(x*_,y*_); }
			point operator*( const point& _ )const{ return point(x*_.x,y*_.y); }
			
			point& operator/=( const Type& _ )const{ x/=_; y/=_; return *this; }
			point& operator/=( const point& _ )const{ x/=_.x; y/=_.y; return *this; }
			point operator/( const Type& _ )const{ return point(x/_,y/_); }
			point operator/( const point& _ )const{ return point(x/_.x,y/_.y); }
			
			
			
			Type dist2( const point& _ )const{
				Type DX = dx(*this,_), DY = dy(*this,_);
				return ( DX*DX + DY*DY );
			}
			Type cross_product( const point& _ )const{ return x*_.y-_.x*y; }
			Type cross_product( const point& b, const point& c )const{ return point( dx(*this,b), dy(*this,b) ).cross_product(point( dx(*this,c), dy(*this,c) ) ); }
			Type dot_product( const point& _ )const{ return x*_.x + y*_.y; }
			Type angle( const point& _ )const{ return atan2( dy(*this,_), dx(*this,_) ); }
			Type vector_angle( const point& _ )const{ return acos( dot_product(_) / sqrt(dot_product(*this)) / sqrt(_.dot_product(_))); }
			Type angle( const point& A, const point& C )const{
				Type
					AB = dist2(A),
					BC = dist2(C),
					CA = A.dist2(C);
				return acos((AB+BC-CA)/(2*sqrt(AB)*sqrt(BC)));
			}
			point& rotate( const Type& _ ){
				Type X,Y,COS,SIN;
				COS = cos(_);
				SIN = sin(_);
				X = x*COS-y*SIN;
				Y = x*SIN+y*COS;
				x = X;
				y = Y;
				return *this;
			}
	};
	
	TYPE1 class line{
		protected:
			void Normalize( const point<Type>& A_, const point<Type>& B_ ){ //for 2d
				if(A_.x==B_.x){
					b = A_.x;
					if(!b) m = std::numeric_limits<Type>::max();
					else m = std::numeric_limits<Type>::quiet_NaN();
					vertical = true;
				}
				else{
					m = dy(A_,B_)/dx(A_,B_);
					b = A_.y - m*A_.x;
					vertical = false;
				}
			}
		public:
			typedef Type value_type;
			Type m, b; //y = mx+b
			bool vertical;
			unsigned size()const{ return 0u; }
			Type length()const{ return std::numeric_limits<Type>::max(); }
			
			Type x_intercept()const{ return vertical ? b : -b/m; }
			Type y_intercept()const{ return vertical ? m : b; }
			Type y_value( const Type& x )const{ return m*x + b; }
			Type x_value( const Type& y )const{ return (y-b)/m; }
			
			Type slope()const{ return m; }
			// line normal()const{ Type nm = -1/m; return line(nm,b-m*x_value(b)); }
			bool isVertical()const{ return vertical; }
			
			bool contains( const Type& x, const Type& y )const{ return y_value(x)==y; }
			bool contains( const point<Type>& _ )const{ return y_value(_.x)==_.y; }
			
			line& assign( const segment<Type>& _ ){ Normalize(_.A,_.B); return *this; }
			line& assign( const ray<Type>& _ ){ m = _.slope(); b = _.vertex.y-m*_.vertex.x; }
			line& assign( const point<Type>& A_, const point<Type>& B_ ){ Normalize(A_,B_); return *this;}
			line& assign( const Type& A_, const Type& B_ ){ m=A_, b=B_; vertical=false; return *this; }
			line& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign( point<Type>(ax,ay), point<Type>(bx,by) ); }
			TYPEo line& operator=( const oType& _ ){ return assign(_); }
			
			line(){}
			TYPEo line( const oType& _ ){ assign(_); }
			TYPEo line( const oType& p1, const oType& p2 ){ assign(p1,p2); }
			line( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }

			bool operator==( const line& _ )const{ return m==_.m && b==_.b; }
			bool operator!=( const line& _ )const{ return !operator==(_); }
			bool operator<( const line& _ )const{ return m==_.m ? b < _.b : m < _.m; }
			bool operator<=( const line& _ )const{ return operator<(_)||operator==(_); }
			bool operator>( const line& _ )const{ return m==_.m ? b > _.b : m > _.m; }
			
			friend class segment<Type>;
			friend class ray<Type>;		
	};
	TYPE1 class segment{
		public:
			typedef Type value_type;
			point<Type> A, B;
			
			Type length()const{ return dist(A,B); }
			
		protected:
			bool inRange_x( const Type& X )const{ return X>=std::min(A.x,B.x) && X<=std::max(A.x,B.x); }
			bool inRange_y( const Type& Y )const{ return Y>=std::min(A.y,B.y) && Y<=std::max(A.y,B.y); }
			bool inRange_xy( const Type& X, const Type& Y )const{ return inRange_x(X)&&inRange_y(Y); }
			bool inRange_xy( const point<Type>& _ )const{ return inRange_x(_.x) && inRange_y(_.y); }

		public:
			
			Type y_intercept()const{ return y_value(0); }
			Type x_intercept()const{ return x_value(0); }
			
			Type y_value( const Type& x )const{
				if(inRange_x(x))
					return line<Type>(A,B).y_value( x );
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			Type x_value( const Type& y )const{
				if(inRange_y(y))
					return line<Type>(A,B).x_value( y );
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			bool contains( const Type& x, const Type& y )const{ return y_value(x)==y; }
			bool contains( const point<Type>& _ )const{ return contains(_.x,_.y); }
			
			Type slope()const{ return line<Type>(A,B).slope(); }
			bool isVertical()const{ return A.x==B.x; }
			
			segment& assign( const segment& _ )const{ A=_.A, B=_.B;  }
			segment& assign( const point<Type>& A_, const point<Type>& B_ ){ A=A_, B=B_; }
			segment& assign( const ray<Type>& R, const Type& len ){ A = R.vertex; B = point<Type>( A.x+len*cos(R.theta), A.y+len*sin(R.theta) ); }
			segment& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign(point<Type>(ax,ay),point<Type>(bx,by)); }
			segment& operator=( const segment& _ ){ return assign(_); }
			
			segment(){}
			segment( const segment& _ ){ assign(_); }
			segment( const point<Type>& p1, const point<Type>& p2 ){ assign(p1,p2); }
			segment( const ray<Type>& R, const Type& len ){ assign(R,len); }
			segment( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }
			
			bool operator==( const segment& _ )const{ return (A==_.A && B==_.B)||(A==_.B&&B==_.A); }
			bool operator!=( const segment& _ )const{ return !operator==(_); }
			bool operator<( const segment& _ )const{ return length() < _.length(); }
			bool operator<=( const segment& _ )const{ return length() <= _.length(); }
			bool operator>( const segment& _ )const{ return length() > _.length(); }
			bool operator>=( const segment& _ )const{ return length() >= _.length(); }
			
			friend class line<Type>;
			friend class ray<Type>;
			
	};
	TYPE1 class ray{
		
		public:
			typedef Type value_type;
			point<Type> vertex;
			Type theta;
		protected:
			bool inRange_x( const Type& X )const{ return cos(theta)>0 ? X>=vertex.x : X<=vertex.x; }
			bool inRange_y( const Type& Y )const{ return theta<PI ? Y>=vertex.y : Y<=vertex.y; }
			bool inRange_xy( const point<Type>& _ )const{ return inRange_x(_.x) && inRange_y(_.y); }
			bool inRange_xy( const Type& X, const Type& Y )const{ return inRange_x(X) && inRange_y(Y); }
			
		public:
		
			Type length()const{ return std::numeric_limits<Type>::max(); }
			
			bool contains( const point<Type>& _ )const{ return vertex==_ || angle(vertex,_)==theta; }
			bool contains( const Type& x, const Type& y )const{ return contains(point<Type>(x,y)); }
			
			Type x_intercept()const{ return x_value(0); }
			Type y_intercept()const{ return vertex.y - slope()*vertex.x; }
			
			Type x_value( const Type& y )const{
				if(inRange_y(y)) return (y-y_intercept())/slope();
				return std::numeric_limits<Type>::quiet_NaN();
			}
			Type y_value( const Type& x )const{
				if(inRange_x(x)) return (slope()*x+y_intercept());
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			Type slope()const{ return tan(theta); }
			bool isVertical()const{ return cos(theta)==0; }
			
			ray& assign( const ray& _ ){ vertex=_.vertex, theta = _.theta; }
			ray& assign( const segment<Type>& _ ){ vertex=_.A, theta = angle(_.A,_.B); return *this; }
			ray& assign( const point<Type>& A_, const point<Type>& B_ ){ vertex=A_, theta = angle(A_,B_); return *this; }
			ray& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign(point<Type>(ax,ay),point<Type>(bx,by)); }
			ray& assign( const point<Type>& _, const Type& ANGLE ){ vertex = _, theta = ANGLE; return *this; }
			ray& assign( const Type& x, const Type& y, const Type& _ ){ vertex.x = x, vertex.y = y, theta = _; return *this; }
			TYPEo ray& operator=( const oType& _ ){ return assign(_); }
			
			ray(){}
			TYPEo ray( const oType& _ ){ assign(_); }
			ray( const point<Type>& A_, const point<Type>& B_ ){ assign(A_,B_); }
			ray( const Type& x, const Type& y, const Type& _ ){ assign(x,y,_); }
			ray( const point<Type>& p, const Type& _ ){ assign(p,_); }
			ray( const  Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }
			
			bool operator==( const ray& _ )const{ return vertex==_.vertex && theta==_.theta; }
			TYPEo bool operator==( const oType& _ )const{ return false; }
			TYPEo bool operator!=( const oType& _ )const{ return !operator==(_); }
			TYPEo bool operator<( const oType& _ )const{ return vertex==_.vertex ? theta<_.theta : vertex<_.vertex; }
			TYPEo bool operator<=( const oType& _ )const{ return vertex==_.vertex ? theta<=_.theta : vertex<_.vertex; }
			TYPEo bool operator>( const oType& _ )const{ return vertex==_.vertex ? theta>_.theta : vertex>_.vertex; }
			TYPEo bool operator>=( const oType& _ )const{ return vertex==_.vertex ? theta>=_.theta : vertex>_.vertex; }
			
			friend class line<Type>;
			friend class segment<Type>;
			
	};
	
	TYPE3 class polygon{
	
		private:
			cType v;
			
		protected:
			struct arrange_cw{
				const pType* val;
				arrange_cw( const pType& _ ): val( &_ ){}
				bool operator()( const pType& a, const pType& b )const{
					Type cp = cross_product( *val, a, b );
					if(!cp) return dist(*val,a)>dist(*val,b);
					return 0>cp;
				}
			};
			struct arrange_ccw{
				const pType* val;
				arrange_ccw( const pType& _ ): val( &_ ){}
				bool operator()( const pType& a, const pType& b )const{
					Type cp = cross_product( *val, a, b );
					if(!cp) return dist(*val,a)<dist(*val,b);
					return 0<cp;
				}
			};
			bool ccw( const pType& a, const pType& b, const pType& c ){ return cross_product(a,b,c)>=0; }
			bool cccw( const pType& a, const pType& b, const pType& c ){ return cross_product(a,b,c)<=0; }
			
		public:
			typedef Type value_type;
			typedef pType point_type;
			typedef cType container_type;
			
			polygon(){}
			polygon( pType* _, unsigned sz ): v(_,_+sz) {} // array
			TYPEo polygon( oType& _ ){ for( unsigned i=0; i<_.size(); ++i ) push(_[i]); }
			
			polygon( unsigned sz ): v(sz) {}
			polygon( int sz ): v(sz) {}
			polygon( unsigned sz, const pType& _ ): v(sz,_) {}
			polygon( int sz, const pType& _ ): v(sz,_) {}
			
			virtual cType& access(){ return v; }
			bool empty()const{ return v.empty(); }
			
			// inherited from cType shortcuts
			void clear(){ v.clear(); }
			polygon& push( const pType& _ ){ v.push_back(_); return *this; }
			polygon& push( const Type& x, const Type& y ){ v.push_back(pType(x,y)); return *this; } // 2d
			polygon& push( const Type&, const Type&, const Type& ); //3d, empty
			polygon& insert( const pType& _ ){ return push(_); }
			polygon& insert( const Type& x, const Type& y ){ return push(x,y); }
			polygon& pop(){ v.pop_back(); }
			void resize( unsigned sz ){ v.resize(sz); }
			void resize( unsigned sz, const pType& _ ){ v.resize(sz,_); }
			
			virtual unsigned size()const{ return v.size(); }
			virtual pType& operator[]( unsigned _ ){ return v[_]; }
			virtual pType vertex( unsigned _ )const{ return v[_]; }
			
			Type boundary()const{
				Type bound(0);
				for( int i=0, j=size()-1; i<size(); j=i++ ){
					bound += gcd( abs(dx(vertex(i), vertex(j))), abs(dy(vertex(i), vertex(j))));
				}
				return bound;
			}
			
			Type lattice()const{
				return (abs(signedArea())-boundary()+2LL)/2LL;
			}

			Type signedArea()const{
				Type Area(0);
				for( int i=0, j=size()-1; i<size(); j=i++ )
					Area += cross_product( vertex(j), vertex(i) );
				return Area;
			}		
			
			Type area()const{ return abs(signedArea())/2; }
			virtual Type perimeter()const{
				Type p(0);
				for( int i=0, j=size()-1; i<size(); j=i++ )
					p += dist( vertex(i), vertex(j) );
				return p;
			}
			bool isClockwise()const{ return signedArea()>0; }
			bool isCounterclockwise()const{ return signedArea()<0; }
			
			void sort( WiseType Wise = clockwise ){
				std::swap(operator[](0u),*min_element( v.begin(), v.end() ));
				if(Wise==clockwise) std::sort( access().begin()+1, access().end(), arrange_cw(vertex(0)));
				else std::sort( access().begin()+1,access().end(), arrange_ccw(vertex(0)));
			}
			
			void GrahamScan( WiseType Wise = clockwise){
				push(vertex(0));
				int m = 2;
				if(Wise==clockwise){
					for(int i=2;i<size();++i){
						while( m>=2 && ccw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						operator[]( m ) = vertex(i);
						++m;
					}
				}
				else{
					for(int i=2;i<size();++i){
						while( m>=2 && cccw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						operator[]( m ) = vertex(i);
						++m;
					}
				}
				resize( m );
			}
			
			void ConvexHull( WiseType Wise = clockwise ){
				sort( Wise );
				GrahamScan( Wise );
			}
			
			polygon hull( WiseType Wise = clockwise )const{
				return polygon( *this ).convexHull( Wise );
			}
			
			polygon& operator+=( const pType& _ ){ return push(_); }
			polygon& operator+=( const polygon& _ ){ for(unsigned i=0;i<_.size();++i) push(_.vertex(i)); return *this; }
			TYPEo polygon operator+( const oType& _ )const{ return polygon(*this)+=_; }
			polygon& operator-=( int sz ){ while(sz>0){ pop(); --sz; } return *this; }
			
			polygon& operator++(){ return push(pType()); }
			polygon& operator++( int _ ){ return operator++(); }
			polygon& operator--(){ return pop(); }
			polygon& operator--( int _ ){ return operator--(); }
			
			
			TYPE3o friend std::istream& operator>>( std::ostream&, polygon<oType,oType2,oType3>& );
			TYPE3o friend std::ostream& operator<<( std::istream&, const polygon<oType,oType2,oType3>& );
			
	};
	
	TYPE2 class triangle: public polygon<Type,pType>{
		public:
			typedef Type value_type;
			typedef pType point_type;
			pType A,B,C;
			Type a, b, c;
		private:
			Type al, be, ga;
		public:
			void update(){
				a = dist(A,B);
				b = dist(A,C);
				c = dist(A,B);
				al = acos((b*b+c*c-a*a)/(2.*b*c));
				be = acos((c*c+a*a-b*b)/(2.*c*a));
				ga = acos((a*a+b*b-c*c)/(2.*a*b));
			}
			
			virtual unsigned size()const{ return 3u; }
			triangle(){}
			TYPEo triangle( oType& _ ): A(_[0]), B(_[1]), C(_[2]) {
				#ifndef RAW_TRIANGLE
				update();
				#endif
			} //container
			TYPEo triangle& operator=( oType& _ ){
				A = _[0], B = _[1], C = _[2];
				#ifndef RAW_TRIANGLE
				update();
				#endif
			}
			triangle( pType* _ ): A(_[0]), B(_[1]), C(_[2]) {
				#ifndef RAW_TRIANGLE
				update();
				#endif
			} //array
			triangle( const pType& pa, const pType& pb, const pType& pc ): A(pa), B(pb), C(pc) {
				#ifndef RAW_TRIANGLE
				update();
				#endif
			}
			triangle( const Type& ax, const Type& ay, const Type& bx, const Type& by, const int& cx, const Type& cy ): A(ax,ay), B(bx,by), C(cx,cy) {
				#ifndef RAW_TRIANGLE
				update();
				#endif
			}
			triangle( const Type& ax, const Type& ay, const Type& az, const Type& bx, const Type& by, const Type& bz, const Type& cx, const Type& cy, const Type& cz ): A(ax,ay,az), B(bx,by,bz), C(cx,cy,cz) {
				#ifndef RAW_TRIANGLE
				update();
				#endif
			}
			
			virtual pType& operator[]( unsigned _ ){
				switch( _ ){
					case 0: return A; break;
					case 1: return B; break;
					case 2: return C; break;
				}
			}
			virtual pType vertex( unsigned _ )const{
				switch( _ ){
					case 0: return A; break;
					case 1: return B; break;
					case 2: return C; break;
				}
			}
			
			Type alpha()const{ return al; }
			Type beta()const{ return be; }
			Type gamma()const{ return ga; }
			
			virtual void GrahamScan( WiseType Wise = clockwise ){
				pType* mn;
				if(A<B){
					if(A<C) mn = &A;
					else mn = &C;
				}
				else if(B<C) mn = &B;
				else mn = &C;
				std::swap(*mn,A);
				if( Wise==clockwise ){
					if( angle(A,B) < angle(A,C) ) std::swap(B,C);
				}
				else{
					if( angle(A,B) > angle(A,C) ) std::swap(B,C);
				}
				#ifndef RAW_TRIANGLE
				update();
				#endif
			}
			
			Type inradius()const{ return abs( this->signedArea() ) / this->perimeter(); }
			Type circumradius()const{ return a*b*c/(2*abs( this->signedArea() )); }
			pType bary( const Type& ba, const Type& bb, const Type& bc )const{ return triangle_bary(*this, ba,bb,bc); }
			pType brocard1()const{ return bary(a*c/b,b*a/c,c*b/a); }
			pType brocard2()const{ return bary(a*b/c,b*c/a,c*a/b); }
			pType excenterA()const{ return bary(-a,b,c); }
			pType excenterB()const{ return bary(a,-b,c); }
			pType excenterC()const{ return bary(a,b,-c); }
			bool isRight()const{ return al==90 || be==90 || ga==90; }
			bool isObtuse()const{ return al>90 || be>90 || ga>90; }
			bool isAcute()const{ return al<90 && be<90 && ga<90; }
			bool isEquilateral()const{ return a==b && b==c; }
			bool isIsosceles()const{ return a==b xor b==c xor c==a; }
			bool isScalene()const{ return a!=b && a!=c && b!=c; }
			
			pType MorleyPoint( const pType& pa, const pType& pb, const pType& pc )const{
				pType v1 = (pc-pb);
				v1.rotate( vector_angle(v1,pa-pb)/3. );
				pType v2 = pb-pc;
				v2.rotate( -vector_angle(v2,pa-pc)/3. );
				pType u = pb-pc;
				return (pb + v1*( cross_product(v2, u)/cross_product(v1,v2) ) );
			}
			
			triangle Morley()const{
				return triangle( MorleyPoint(A,B,C), MorleyPoint(B,C,A), MorleyPoint(C,A,B) );
			}
			
	};
		
	TYPE2 class circle{
		public:
			typedef Type value_type;
			typedef pType point_type;
			pType center;
			Type r;
			circle(): center(), r() {}
			circle( const pType& c, const Type& R ): center(c), r(R) {}
			circle( const Type& R, const pType& c ): center(c), r(R) {}
			circle( const pType& a, const pType& b ): center(a), r( dist(a,b) ) {}
			circle( const Type& x, const Type& y, const Type& R ): center(x,y), r(R) {}
			
			unsigned size() const{ return 1u; }
			
			Type radius()const{ return r; }
			Type diameter()const{ return r*2; }
			Type area()const{ return PI*r*r; }
			Type circumference()const{ return PI*diameter(); }
			Type arcLength()const{ return circumference(); }
			Type arcLength( const Type& _ )const{ return circumference()*_/(2*PI); }
			Type chordLength( const Type& _ )const{ return sqrt( (r*r*2)*(1-cos(_))); }
			Type sectorArea( const Type& _ )const{ return area()*_/(2*PI); }
			
	};
		
}

TYPEo std::istream& operator>>( std::istream& in, geom2D::point<oType>& pt ){ return in >> pt.x >> pt.y; }
TYPEo std::istream& operator>>( std::istream& in, geom2D::line<oType>& ln ){ in >> ln.m >> ln.b; ln.vertical = false; return in; }
TYPEo std::istream& operator>>( std::istream& in, geom2D::segment<oType>& sg ){ return in >> sg.A >> sg.B;  }
TYPEo std::istream& operator>>( std::istream& in, geom2D::ray<oType>& ry ){ return in >> ry.vertex >> ry.theta; }
TYPE2o std::istream& operator>>( std::istream& in, geom2D::triangle<oType,oType2>& tr ){ in >> tr.A >> tr.B >> tr.C;
	#ifndef RAW_TRIANGLE
	tr.update();
	#endif
return in; }
TYPE2o std::istream& operator>>( std::istream& in, geom2D::circle<oType,oType2>& cc ){ return in >> cc.center >> cc.r; }
TYPE3o std::istream& operator>>( std::istream& in, geom2D::polygon<oType,oType2,oType3>& pl ){ for(unsigned i=0;i<pl.size();++i) in >> pl[i]; return in; }

TYPEo std::ostream& operator<<( std::ostream& out, const geom2D::point<oType>& pt ){ return out << pt.x << ' ' << pt.y; }
TYPEo std::ostream& operator<<( std::ostream& out, const geom2D::line<oType>& ln ){ return out << ln.slope() << ' ' << ln.b; }
TYPEo std::ostream& operator<<( std::ostream& out, const geom2D::segment<oType>& sg ){ return out << sg.A << ' ' << sg.B; }
TYPEo std::ostream& operator<<( std::ostream& out, const geom2D::ray<oType>& ry ){ return out << ry.vertex << std::endl << ry.theta; }
TYPE2o std::ostream& operator<<( std::ostream& out, const geom2D::circle<oType,oType2>& cc ){ return out << cc.center << ' ' << cc.r; }
TYPE2o std::ostream& operator<<( std::ostream& out, const geom2D::triangle<oType,oType2>& tr ){ return out << tr.A << ' ' << tr.B << ' ' << tr.C; }
TYPE3o std::ostream& operator<<( std::ostream& out, const geom2D::polygon<oType,oType2,oType3>& pl ){ if(!pl.empty()){ out << pl.vertex(0); for(unsigned i=1;i<pl.size();++i) out << ' ' << pl.vertex(i);} return out; }
	
typedef geom2D::point<double> Point;
typedef geom2D::line<double> Line;
typedef geom2D::segment<double> Segment;
typedef geom2D::ray<double> Ray;
typedef geom2D::polygon<double> Polygon;
typedef geom2D::triangle<double> Triangle;
typedef geom2D::circle<double> Circle;
typedef geom3D::point<double> Point3D;

/** END Geom v2.3 proto **/
/** IsosceleS **/

using namespace std;
Triangle t;
int n;
int main(){
	cout.precision(6);
	cout << fixed;
	cin >> n;
	while(n--){
		cin >> t;
		cout << t.Morley() << endl;
	}
}
