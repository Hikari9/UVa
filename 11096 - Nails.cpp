/**
	UVa 11096 - Nails
	by Rico Tiongson
	Submitted: August 15, 2013
	Accepted 0.019s C++
	O(nlogn) time
*/
/** START Geom v2.4.3 **/
/** IsosceleS 2013 (c) **/
#ifndef _INCLUDE_GEOM
#define _INCLUDE_GEOM 1

#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
#include<algorithm>

#undef TYPEp
#undef TYPEpp
#undef fTYPEpp
#undef TYPEo
#undef TYPE2o
#undef TYPE3o
#undef TYPE3e
#undef TYPE3
#undef TYPE2e
#undef TYPE2
#undef TYPE1

#ifndef G_INLINE
	#define G_INLINE inline
#endif
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


TYPE1 G_INLINE Type gcd( Type a, Type b ){
	Type temp;
	while(a>0){
		temp = a;
		a = b%a;
		b = temp;
	}
	return b;
}
G_INLINE float gcd( float a, float b ){
	float temp;
	while(a>0){
		temp = a;
		a = fmod(b,a);
		b = temp;
	}
	return b;
}
G_INLINE double gcd( double a, double b ){
	double temp;
	while(a>0){
		temp = a;
		a = fmod(b,a);
		b = temp;
	}
	return b;
}
G_INLINE long double gcd( long double a, long double b ){
	long double temp;
	while(a>0){
		temp = a;
		a = fmod(b,a);
		b = temp;
	}
	return b;
}

enum WiseType{ counterclockwise=0, clockwise };

TYPE1 G_INLINE long double RAD( const Type& _ ){ return _ * PI/180.; }
TYPE1 G_INLINE long double DEG( const Type& _ ){ return _*180./PI; }

TYPEpp G_INLINE dist2( const pType& a, const pType& b ){ return a.dist2(b); }
TYPEpp G_INLINE dist( const pType& a, const pType& b ){ return sqrt( dist2(a,b) ); }
TYPEpp G_INLINE cross( const pType& a, const pType& b ){ return a.cross(b); }
TYPEpp G_INLINE cross( const pType& a, const pType& b, const pType& c ){ return a.cross(b,c); }
TYPEpp G_INLINE dx( const pType& a, const pType& b ){ return b.x-a.x; }
TYPEpp G_INLINE dy( const pType& a, const pType& b ){ return b.y-a.y; }
TYPEpp G_INLINE dz( const pType& a, const pType& b ){ return b.z-a.z; }
TYPEpp G_INLINE angle( const pType& a, const pType& b ){ return a.angle(b); }
TYPEpp G_INLINE angle( const pType& a, const pType& b, const pType& c ){ return b.angle(a,c); }

TYPEp G_INLINE bool ccw( const pType& a, const pType& b, const pType& c ){ return cross(a,b,c)>=std::numeric_limits<typename pType::value_type>::epsilon(); }
TYPEp G_INLINE bool cw( const pType& a, const pType& b, const pType& c ){ return cross(a,b,c)<=-std::numeric_limits<typename pType::value_type>::epsilon(); }

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
}

namespace geom3D{
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

	TYPE1 G_INLINE Type abs( Type _ ){ return _>=0 ? _ : -_; }
	
	TYPE1 G_INLINE point<Type> triangle_bary( const triangle<Type,point<Type> >& _, const Type& ba, const Type& bb, const Type& bc ){
		Type Sum(ba+bb+bc);
		return point<Type>( ( _.A.x*ba + _.B.x*bb + _.C.x*bc )/Sum, ( _.A.y*ba + _.B.y*bb + _.C.y*bc )/Sum ); 
	}
	TYPE1 G_INLINE geom3D::point<Type> triangle_bary( const triangle<Type,geom3D::point<Type> >& _, const Type& ba, const Type& bb, const Type& bc ){
		Type Sum(ba+bb+bc);
		return geom3D::point<Type>( ( _.A.x*ba + _.B.x*bb + _.C.x*bc )/Sum, ( _.A.y*ba + _.B.y*bb + _.C.y*bc )/Sum, ( _.A.z*ba + _.B.z*bb + _.C.z*bc )/Sum ); 
	}
	
	TYPE1 class point{
		
		public:
			typedef Type value_type;
			Type x, y;
			point(): x(), y() {}
			point( const Type& a, const Type& b ): x(a), y(b) {}
			TYPEo G_INLINE bool isInPolygon( const oType& P )const{
				bool in(false);
				for(int i=0, j=P.size()-1; i<P.size(); j=i++)
					if(((P.vertex(i).y>y)!=(P.vertex(j).y>y))&&(x<dx(P.vertex(i),P.vertex(j))*dy(P.vertex(i),*this)/dy(P.vertex(i),P.vertex(j))+P.vertex(i).x)) in = !in;
				return in;
			}
			TYPEo G_INLINE bool isOnPolygon( const oType& P )const{
				for(int i=0, j=P.size()-1; i<P.size(); j=i++)
					if(segment<Type>(P.vertex(i),P.vertex(j)).contains(*this)) return true;
				return false;
			}
			G_INLINE bool isInCircle( const circle<Type,point<Type> >& C )const{ return dist2( C.center ) < C.r*C.r; }
			G_INLINE bool isOnCircle( const circle<Type,point<Type> >& C )const{ return dist2( C.center ) == C.r*C.r; }
			G_INLINE point& operator=( const point& _ ){ x = _.x, y=_.y; return *this; }
			G_INLINE bool operator==( const point& _ )const{ return x==_.x && y==_.y; }
			G_INLINE bool operator!=( const point& _ )const{ return !operator==(_); }
			G_INLINE bool operator<( const point& _ )const{ return x==_.x ? y<_.y : x<_.x; }
			G_INLINE bool operator<=( const point& _ )const{ return x==_.x ? y<=_.y : x<_.x; }
			G_INLINE bool operator>( const point& _ )const{ return x==_.x ? y>_.y : x>_.x; }
			G_INLINE bool operator>=( const point& _ )const{ return x==_.x ? y>=_.y : x>_.x; }
			
			G_INLINE Type dist2( const point& _ )const{
				Type DX = dx(*this,_), DY = dy(*this,_);
				return ( DX*DX + DY*DY );
			}
			G_INLINE Type cross( const point& _ )const{ return x*_.y-_.x*y; }
			G_INLINE Type cross( const point& b, const point& c )const{ return point( dx(*this,b), dy(*this,b) ).cross(point( dx(*this,c), dy(*this,c) ) ); }
			G_INLINE Type angle( const point& _ )const{ return atan2( dy(*this,_), dx(*this,_) ); }
			G_INLINE Type angle( const point& A, const point& C )const{
				Type
					AB = dist2(A),
					BC = dist2(C),
					CA = A.dist2(C);
				return acos((AB+BC-CA)/(2*sqrt(AB)*sqrt(BC)));
			}
				
	};
	
	TYPE1 class line{
		protected:
			G_INLINE void Normalize( const point<Type>& A_, const point<Type>& B_ ){ //for 2d
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
			std::size_t size()const{ return 0u; }
			Type length()const{ return std::numeric_limits<Type>::max(); }
			
			G_INLINE Type x_intercept()const{ return vertical ? b : -b/m; }
			G_INLINE Type y_intercept()const{ return vertical ? m : b; }
			G_INLINE Type y_value( const Type& x )const{ return m*x + b; }
			G_INLINE Type x_value( const Type& y )const{ return (y-b)/m; }
			
			G_INLINE Type slope()const{ return m; }
			// line normal()const{ Type nm = -1/m; return line(nm,b-m*x_value(b)); }
			G_INLINE bool isVertical()const{ return vertical; }
			
			G_INLINE bool contains( const Type& x, const Type& y )const{ return y_value(x)==y; }
			G_INLINE bool contains( const point<Type>& _ )const{ return y_value(_.x)==_.y; }
			
			G_INLINE line& assign( const segment<Type>& _ ){ Normalize(_.A,_.B); return *this; }
			G_INLINE line& assign( const ray<Type>& _ ){ m = _.slope(); b = _.vertex.y-m*_.vertex.x; }
			G_INLINE line& assign( const point<Type>& A_, const point<Type>& B_ ){ Normalize(A_,B_); return *this;}
			G_INLINE line& assign( const Type& A_, const Type& B_ ){ m=A_, b=B_; vertical=false; return *this; }
			G_INLINE line& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign( point<Type>(ax,ay), point<Type>(bx,by) ); }
			TYPEo G_INLINE line& operator=( const oType& _ ){ return assign(_); }
			
			line(){}
			TYPEo line( const oType& _ ){ assign(_); }
			TYPEo line( const oType& p1, const oType& p2 ){ assign(p1,p2); }
			line( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }

			G_INLINE bool operator==( const line& _ )const{ return m==_.m && b==_.b; }
			G_INLINE bool operator!=( const line& _ )const{ return !operator==(_); }
			G_INLINE bool operator<( const line& _ )const{ return m==_.m ? b < _.b : m < _.m; }
			G_INLINE bool operator<=( const line& _ )const{ return operator<(_)||operator==(_); }
			G_INLINE bool operator>( const line& _ )const{ return m==_.m ? b > _.b : m > _.m; }
			
			friend class segment<Type>;
			friend class ray<Type>;		
	};
	TYPE1 class segment{
		public:
			typedef Type value_type;
			point<Type> A, B;
			
			G_INLINE Type length()const{ return dist(A,B); }
			
		protected:
			G_INLINE bool inRange_x( const Type& X )const{ return X>=std::min(A.x,B.x) && X<=std::max(A.x,B.x); }
			G_INLINE bool inRange_y( const Type& Y )const{ return Y>=std::min(A.y,B.y) && Y<=std::max(A.y,B.y); }
			G_INLINE bool inRange_xy( const Type& X, const Type& Y )const{ return inRange_x(X)&&inRange_y(Y); }
			G_INLINE bool inRange_xy( const point<Type>& _ )const{ return inRange_x(_.x) && inRange_y(_.y); }

		public:
			
			G_INLINE Type y_intercept()const{ return y_value(0); }
			G_INLINE Type x_intercept()const{ return x_value(0); }
			
			G_INLINE Type y_value( const Type& x )const{
				if(inRange_x(x))
					return line<Type>(A,B).y_value( x );
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			G_INLINE Type x_value( const Type& y )const{
				if(inRange_y(y))
					return line<Type>(A,B).x_value( y );
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			// G_INLINE bool contains( const Type& x, const Type& y )const{ return y_value(x)==y; }
			// G_INLINE bool contains( const point<Type>& _ )const{ return contains(_.x,_.y); }
			G_INLINE bool contains( const point<Type>& _ )const{ return inRange_xy(_) && cross(A,_,B)==0; }
			G_INLINE bool contains( const Type& x, const Type& y )const{ return contains(point<Type>(x,y)); }
			
			G_INLINE Type slope()const{ return line<Type>(A,B).slope(); }
			G_INLINE bool isVertical()const{ return A.x==B.x; }
			
			G_INLINE segment& assign( const segment& _ )const{ A=_.A, B=_.B;  }
			G_INLINE segment& assign( const point<Type>& A_, const point<Type>& B_ ){ A=A_, B=B_; }
			G_INLINE segment& assign( const ray<Type>& R, const Type& len ){ A = R.vertex; B = point<Type>( A.x+len*cos(R.theta), A.y+len*sin(R.theta) ); }
			segment& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign(point<Type>(ax,ay),point<Type>(bx,by)); }
			G_INLINE segment& operator=( const segment& _ ){ return assign(_); }
			
			segment(){}
			segment( const segment& _ ){ assign(_); }
			segment( const point<Type>& p1, const point<Type>& p2 ){ assign(p1,p2); }
			segment( const ray<Type>& R, const Type& len ){ assign(R,len); }
			segment( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }
			
			G_INLINE bool operator==( const segment& _ )const{ return (A==_.A && B==_.B)||(A==_.B&&B==_.A); }
			G_INLINE bool operator!=( const segment& _ )const{ return !operator==(_); }
			G_INLINE bool operator<( const segment& _ )const{ return length() < _.length(); }
			G_INLINE bool operator<=( const segment& _ )const{ return length() <= _.length(); }
			G_INLINE bool operator>( const segment& _ )const{ return length() > _.length(); }
			G_INLINE bool operator>=( const segment& _ )const{ return length() >= _.length(); }
			
			friend class line<Type>;
			friend class ray<Type>;
			
	};
	TYPE1 class ray{
		
		public:
			typedef Type value_type;
			point<Type> vertex;
			Type theta;
		protected:
			G_INLINE bool inRange_x( const Type& X )const{ return cos(theta)>0 ? X>=vertex.x : X<=vertex.x; }
			G_INLINE bool inRange_y( const Type& Y )const{ return theta<PI ? Y>=vertex.y : Y<=vertex.y; }
			G_INLINE bool inRange_xy( const point<Type>& _ )const{ return inRange_x(_.x) && inRange_y(_.y); }
			G_INLINE bool inRange_xy( const Type& X, const Type& Y )const{ return inRange_x(X) && inRange_y(Y); }
			
		public:
		
			G_INLINE Type length()const{ return std::numeric_limits<Type>::max(); }
			
			G_INLINE bool contains( const point<Type>& _ )const{ return vertex==_ || angle(vertex,_)==theta; }
			G_INLINE bool contains( const Type& x, const Type& y )const{ return contains(point<Type>(x,y)); }
			
			G_INLINE Type x_intercept()const{ return x_value(0); }
			G_INLINE Type y_intercept()const{ return vertex.y - slope()*vertex.x; }
			
			G_INLINE Type x_value( const Type& y )const{
				if(inRange_y(y)) return (y-y_intercept())/slope();
				return std::numeric_limits<Type>::quiet_NaN();
			}
			G_INLINE Type y_value( const Type& x )const{
				if(inRange_x(x)) return (slope()*x+y_intercept());
				return std::numeric_limits<Type>::quiet_NaN();
			}
			
			G_INLINE Type slope()const{ return tan(theta); }
			G_INLINE bool isVertical()const{ return cos(theta)==0; }
			
			G_INLINE ray& assign( const ray& _ ){ vertex=_.vertex, theta = _.theta; }
			G_INLINE ray& assign( const segment<Type>& _ ){ vertex=_.A, theta = angle(_.A,_.B); return *this; }
			G_INLINE ray& assign( const point<Type>& A_, const point<Type>& B_ ){ vertex=A_, theta = angle(A_,B_); return *this; }
			G_INLINE ray& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign(point<Type>(ax,ay),point<Type>(bx,by)); }
			G_INLINE ray& assign( const point<Type>& _, const Type& ANGLE ){ vertex = _, theta = ANGLE; return *this; }
			G_INLINE ray& assign( const Type& x, const Type& y, const Type& _ ){ vertex.x = x, vertex.y = y, theta = _; return *this; }
			TYPEo G_INLINE ray& operator=( const oType& _ ){ return assign(_); }
			
			ray(){}
			TYPEo ray( const oType& _ ){ assign(_); }
			ray( const point<Type>& A_, const point<Type>& B_ ){ assign(A_,B_); }
			ray( const Type& x, const Type& y, const Type& _ ){ assign(x,y,_); }
			ray( const point<Type>& p, const Type& _ ){ assign(p,_); }
			ray( const  Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }
			
			G_INLINE bool operator==( const ray& _ )const{ return vertex==_.vertex && theta==_.theta; }
			TYPEo G_INLINE bool operator==( const oType& _ )const{ return false; }
			TYPEo G_INLINE bool operator!=( const oType& _ )const{ return !operator==(_); }
			TYPEo G_INLINE bool operator<( const oType& _ )const{ return vertex==_.vertex ? theta<_.theta : vertex<_.vertex; }
			TYPEo G_INLINE bool operator<=( const oType& _ )const{ return vertex==_.vertex ? theta<=_.theta : vertex<_.vertex; }
			TYPEo G_INLINE bool operator>( const oType& _ )const{ return vertex==_.vertex ? theta>_.theta : vertex>_.vertex; }
			TYPEo G_INLINE bool operator>=( const oType& _ )const{ return vertex==_.vertex ? theta>=_.theta : vertex>_.vertex; }
			
			friend class line<Type>;
			friend class segment<Type>;
			
	};
	
	TYPE3 class polygon{
	
		private:
			cType v;
			
		public:
			struct arrange_cw{
				const pType* val;
				arrange_cw( const pType& _ ): val( &_ ){}
				bool operator()( const pType& a, const pType& b )const{
					Type cp1 = cross( *val, a, b );
					Type cp2 = cross( *val, b, a );
					if( cp1==cp2 ){
						if( val->y <= a.y ){
							return dist2( *val, a ) < dist2( *val, b );
						}
						return dist2( *val, a ) > dist2( *val, b );
					}
					return cp1 < cp2;
				}
			};
			struct arrange_ccw{
				const pType* val;
				arrange_ccw( const pType& _ ): val( &_ ){}
				bool operator()( const pType& a, const pType& b )const{
					Type cp1 = cross( *val, a, b );
					Type cp2 = cross( *val, b, a );
					if( cp1==cp2 ){
						if( val->y >= a.y ){
							return dist2( *val, a ) < dist2( *val, b );
						}
						return dist2( *val, a ) > dist2( *val, b );
					}
					return cp1 > cp2;
				}
			};
			
			
		public:
			typedef Type value_type;
			typedef pType point_type;
			typedef cType container_type;
			
			polygon(){}
			polygon( pType* _, std::size_t sz ): v(_,_+sz) {} // array
			TYPEo polygon( oType& _ ){ for( std::size_t i=0; i<_.size(); ++i ) push(_[i]); }
			
			polygon( std::size_t sz ): v(sz) {}
			polygon( int sz ): v(sz) {}
			polygon( std::size_t sz, const pType& _ ): v(sz,_) {}
			polygon( int sz, const pType& _ ): v(sz,_) {}
			
			G_INLINE virtual cType& access(){ return v; }
			G_INLINE bool empty()const{ return v.empty(); }
			
			// inherited from cType shortcuts
			G_INLINE void clear(){ v.clear(); }
			G_INLINE polygon& push( const pType& _ ){ v.push_back(_); return *this; }
			G_INLINE polygon& push( const Type& x, const Type& y ){ v.push_back(pType(x,y)); return *this; } // 2d
			G_INLINE polygon& push( const Type&, const Type&, const Type& ); //3d, empty
			G_INLINE polygon& insert( const pType& _ ){ return push(_); }
			G_INLINE polygon& insert( const Type& x, const Type& y ){ return push(x,y); }
			G_INLINE polygon& pop(){ v.pop_back(); return *this; }
			G_INLINE void resize( std::size_t sz ){ v.resize(sz); }
			G_INLINE void resize( std::size_t sz, const pType& _ ){ v.resize(sz,_); }
			
			G_INLINE virtual std::size_t size()const{ return v.size(); }
			G_INLINE virtual pType& operator[]( std::size_t _ ){ return v[_]; }
			G_INLINE virtual pType operator[]( std::size_t _ )const{ return v[_]; }
			G_INLINE virtual pType& vertex( std::size_t _ ){ return v[_]; }
			G_INLINE virtual pType vertex( std::size_t _ )const{ return v[_]; }
			G_INLINE virtual pType& at( std::size_t _ ){ return v.at(_); }
			G_INLINE virtual pType at( std::size_t _ )const{ return v.at(_); }
			
			G_INLINE Type boundary()const{
				Type bound(0);
				for( int i=0, j=size()-1; i<size(); j=i++ ){
					bound += gcd( abs(dx(vertex(i), vertex(j))), abs(dy(vertex(i), vertex(j))));
				}
				return bound;
			}
			
			G_INLINE Type lattice()const{
				return max( Type(abs(signedArea())-boundary()+2)/2, Type(0) );
			}

			G_INLINE Type signedArea()const{
				Type Area(0);
				for( int i=0, j=size()-1; i<size(); j=i++ )
					Area += cross( vertex(j), vertex(i) );
				return Area;
			}		
			
			G_INLINE Type area()const{ return abs(signedArea())/2; }
			G_INLINE virtual Type perimeter()const{
				Type p(0);
				for( int i=0, j=size()-1; i<size(); j=i++ )
					p += dist( vertex(i), vertex(j) );
				return p;
			}
			G_INLINE bool isClockwise()const{ return signedArea()>0; }
			G_INLINE bool isCounterclockwise()const{ return signedArea()<0; }
			
			G_INLINE void sort( WiseType Wise = counterclockwise ){
				std::swap(operator[](0u),*min_element( v.begin(), v.end() ));
				if(Wise==clockwise) std::sort( access().begin()+1, access().end(), arrange_cw(vertex(0)));
				else std::sort( access().begin()+1,access().end(), arrange_ccw(vertex(0)));
			}
			
			G_INLINE void GrahamScan( WiseType Wise = counterclockwise ){
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
						while( m>=2 && cw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						operator[]( m ) = vertex(i);
						++m;
					}
				}
				resize( m-1 );
			}
			
			G_INLINE polygon& ConvexHull( WiseType Wise = counterclockwise ){
				sort( Wise );
				GrahamScan( Wise );
				return *this;
			}
			
			G_INLINE polygon hull( WiseType Wise = counterclockwise )const{
				return polygon( *this ).ConvexHull( Wise );
			}
			
			// 2D so far
			G_INLINE pType centroid()const{
				Type x(0), y(0), a;
				for( std::size_t j=0, i=size()-1; j<size(); i=j++ ){
					a = cross(vertex(i),vertex(j));
					x += a * ( vertex(i).x + vertex(j).x );
					y += a * ( vertex(i).y + vertex(j).y );
				}
				a = signedArea()*3;
				return pType( x/a, y/a );
			}
			
			G_INLINE polygon& operator+=( const pType& _ ){ return push(_); }
			G_INLINE polygon& operator+=( const polygon& _ ){ for(std::size_t i=0;i<_.size();++i) push(_.vertex(i)); return *this; }
			TYPEo G_INLINE polygon operator+( const oType& _ )const{ return polygon(*this)+=_; }
			G_INLINE polygon& operator-=( int sz ){ while(sz>0){ pop(); --sz; } return *this; }
			
			G_INLINE polygon& operator++(){ return push(pType()); }
			G_INLINE polygon& operator++( int _ ){ return operator++(); }
			G_INLINE polygon& operator--(){ return pop(); }
			G_INLINE polygon& operator--( int _ ){ return operator--(); }
			
			
			TYPE3o friend G_INLINE std::istream& operator>>( std::ostream&, polygon<oType,oType2,oType3>& );
			TYPE3o friend G_INLINE std::ostream& operator<<( std::istream&, const polygon<oType,oType2,oType3>& );
			
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
			
			G_INLINE virtual std::size_t size()const{ return 3u; }
			triangle(){}
			TYPEo triangle( oType& _ ): A(_[0]), B(_[1]), C(_[2]) { update(); } //container
			TYPEo triangle& operator=( oType& _ ){ A = _[0], B = _[1], C = _[2]; update(); }
			triangle( pType* _ ): A(_[0]), B(_[1]), C(_[2]) { update(); } //array
			triangle( const pType& pa, const pType& pb, const pType& pc ): A(pa), B(pb), C(pc) { update(); }
			triangle( const Type& ax, const Type& ay, const Type& bx, const Type& by, const int& cx, const Type& cy ): A(ax,ay), B(bx,by), C(cx,cy) { update(); }
			triangle( const Type& ax, const Type& ay, const Type& az, const Type& bx, const Type& by, const Type& bz, const Type& cx, const Type& cy, const Type& cz ): A(ax,ay,az), B(bx,by,bz), C(cx,cy,cz) { update(); }
			
			G_INLINE virtual pType& operator[]( std::size_t _ ){
				switch( _ ){
					case 0: return A; break;
					case 1: return B; break;
					case 2: return C; break;
				}
			}
			G_INLINE virtual pType vertex( std::size_t _ )const{
				switch( _ ){
					case 0: return A; break;
					case 1: return B; break;
					case 2: return C; break;
				}
			}
			
			G_INLINE Type alpha()const{ return al; }
			G_INLINE Type beta()const{ return be; }
			G_INLINE Type gamma()const{ return ga; }
			
			G_INLINE virtual void GrahamScan( WiseType Wise = counterclockwise ){
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
				update();
			}
			
			G_INLINE Type inradius()const{ return abs( this->signedArea() ) / this->perimeter(); }
			G_INLINE Type circumradius()const{ return a*b*c/(2*abs( this->signedArea() )); }
			G_INLINE pType bary( const Type& ba, const Type& bb, const Type& bc )const{ return triangle_bary(*this, ba,bb,bc); }
			G_INLINE pType brocard1()const{ return bary(a*c/b,b*a/c,c*b/a); }
			G_INLINE pType brocard2()const{ return bary(a*b/c,b*c/a,c*a/b); }
			G_INLINE pType orthocenter()const{ return bary(tan(al),tan(be),tan(ga)); }
			G_INLINE pType excenterA()const{ return bary(-a,b,c); }
			G_INLINE pType excenterB()const{ return bary(a,-b,c); }
			G_INLINE pType excenterC()const{ return bary(a,b,-c); }
			// G_INLINE bool isRight()const{ return al==90 || be==90 || ga==90; }
			// G_INLINE bool isObtuse()const{ return al>90 || be>90 || ga>90; }
			// G_INLINE bool isAcute()const{ return al<90 && be<90 && ga<90; }
			// G_INLINE bool isEquilateral()const{ return a==b && b==c; }
			// G_INLINE bool isIsosceles()const{ return a==b xor b==c xor c==a; }
			// G_INLINE bool isScalene()const{ return a!=b && a!=c && b!=c; }
					
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
			
			G_INLINE std::size_t size() const{ return 1u; }
			
			G_INLINE Type radius()const{ return r; }
			G_INLINE Type diameter()const{ return r*2; }
			G_INLINE Type area()const{ return PI*r*r; }
			G_INLINE Type circumference()const{ return PI*diameter(); }
			G_INLINE Type arcLength()const{ return circumference(); }
			G_INLINE Type arcLength( const Type& _ )const{ return circumference()*_/(2*PI); }
			G_INLINE Type chordLength( const Type& _ )const{ return sqrt( (r*r*2)*(1-cos(_))); }
			G_INLINE Type sectorArea( const Type& _ )const{ return area()*_/(2*PI); }
			
	};
		
}

TYPEo G_INLINE std::istream& operator>>( std::istream& in, geom2D::point<oType>& pt ){ return in >> pt.x >> pt.y; }
TYPEo G_INLINE std::istream& operator>>( std::istream& in, geom2D::line<oType>& ln ){ in >> ln.m >> ln.b; ln.vertical = false; return in; }
TYPEo G_INLINE std::istream& operator>>( std::istream& in, geom2D::segment<oType>& sg ){ return in >> sg.A >> sg.B;  }
TYPEo G_INLINE std::istream& operator>>( std::istream& in, geom2D::ray<oType>& ry ){ return in >> ry.vertex >> ry.theta; }
TYPE2o G_INLINE std::istream& operator>>( std::istream& in, geom2D::triangle<oType,oType2>& tr ){ in >> tr.A >> tr.B >> tr.C; tr.update(); return in; }
TYPE2o G_INLINE std::istream& operator>>( std::istream& in, geom2D::circle<oType,oType2>& cc ){ return in >> cc.center >> cc.r; }
TYPE3o G_INLINE std::istream& operator>>( std::istream& in, geom2D::polygon<oType,oType2,oType3>& pl ){ for(std::size_t i=0;i<pl.size();++i) in >> pl[i]; return in; }

TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::point<oType>& pt ){ return out << pt.x << ' ' << pt.y; }
TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::line<oType>& ln ){ return out << ln.slope() << ' ' << ln.b; }
TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::segment<oType>& sg ){ return out << sg.A << ' ' << sg.B; }
TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::ray<oType>& ry ){ return out << ry.vertex << std::endl << ry.theta; }
TYPE2o G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::circle<oType,oType2>& cc ){ return out << cc.center << ' ' << cc.r; }
TYPE2o G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::triangle<oType,oType2>& tr ){ return out << tr.A << ' ' << tr.B << ' ' << tr.C; }
TYPE3o G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::polygon<oType,oType2,oType3>& pl ){ if(!pl.empty()){ out << pl.vertex(0); for(std::size_t i=1;i<pl.size();++i) out << ' ' << pl.vertex(i);} return out; }

#undef TYPEp
#undef TYPEpp
#undef fTYPEpp
#undef TYPEo
#undef TYPE2o
#undef TYPE3o
#undef TYPE3e
#undef TYPE3
#undef TYPE2e
#undef TYPE2
#undef TYPE1
#undef PI

typedef geom2D::point<double> Point;
typedef geom2D::line<double> Line;
typedef geom2D::segment<double> Segment;
typedef geom2D::ray<double> Ray;
typedef geom2D::polygon<double> Polygon;
typedef geom2D::triangle<double> Triangle;
typedef geom2D::circle<double> Circle;
typedef geom3D::point<double> Point3D;

#endif /* _INCLUDE_GEOM */
/** END Geom v2.4.3 **/
/** IsosceleS 2013 (c) **/
using namespace std;
using namespace geom2D;
Polygon p;
int t, l, n;
int main(){
	cout.precision(5);
	cout << fixed;
	cin >> t;
	while( t-- ){
		cin >> l >> n;
		p.resize(n);
		cin >> p;
		// p.sort(clockwise);
		p.ConvexHull(counterclockwise);
		cout << max(p.perimeter(),(double)l) << endl;
	}
}
