/**
	UVa 11447 - Reservoir logs
	by Rico Tiongson
	Submitted: August 28, 2013
	Accepted 0.092s C++
	O(n) time
*/
/** START Geom v2.5 **/
/** IsosceleS 2013 (c) **/
#ifndef _INCLUDE_GEOM
#define _INCLUDE_GEOM 1

#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
#include<cstdarg>
#include<limits>
#include<stdexcept>
#include<algorithm>

#undef TYPEp
#undef TYPEpp
#undef TYPEppp
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
#define TYPEpp template<class pType,class pType2> typename pType::value_type
#define TYPEppp template<class pType,class pType2,class pType3> typename pType::value_type
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

/// global functions
namespace geom2D{
	TYPE1 G_INLINE Type abs( Type _ ){ return _>=0 ? _ : -_; }
	G_INLINE float abs( float _ ){ return std::abs(_); }
	G_INLINE double abs( double _ ){ return std::abs(_); }
	G_INLINE long double abs( long double _ ){ return std::abs(_); }
	
	TYPE1 G_INLINE Type mod( Type a, Type b ){ return a%b; }
	G_INLINE float mod( float a, float b ){ return std::fmod(a,b); }
	G_INLINE double mod( double a, double b ){ return std::fmod(a,b); }
	G_INLINE long double mod( long double a, long double b ){ return std::fmod(a,b); }
	
	TYPE1 G_INLINE Type gcd( Type a, Type b ){
		Type temp;
		while(a>0){
			temp = a;
			a = mod(b,a);
			b = temp;
		}
		return b;
	}
	
	TYPE1 G_INLINE double RAD( Type _ ){ return _ * PI/180.0; }
	TYPE1 G_INLINE double DEG( Type _ ){ return _*180.0/PI; }

	enum wise_t{ counterclockwise=0, clockwise };
	
	TYPEpp G_INLINE dist2( const pType& a, const pType2& b ){ return a.dist2(b); }
	TYPEpp G_INLINE dist( const pType& a, const pType2& b ){ return sqrt( dist2(a,b) ); }
	TYPEpp G_INLINE cross( const pType& a, const pType2& b ){ return a.cross(b); }
	TYPEpp G_INLINE cross( const pType& a, const pType2& b, const pType& c ){ return a.cross(b,c); }
	TYPEpp G_INLINE dx( const pType& a, const pType2& b ){ return b.x-a.x; }
	TYPEpp G_INLINE dy( const pType& a, const pType2& b ){ return b.y-a.y; }
	TYPEpp G_INLINE angle( const pType& a, const pType2& b ){ return a.angle(b); }
	TYPEppp G_INLINE angle( const pType& a, const pType2& b, const pType3& c ){ return b.angle(a,c); }

	TYPE3o G_INLINE bool ccw( const oType& a, const oType2& b, const oType3& c ){ return std::greater_equal<typename oType::value_type>()(cross(a,b,c),0); } // >= std::eps
	TYPE3o G_INLINE bool cw( const oType& a, const oType2& b, const oType3& c ){ return std::less_equal<typename oType::value_type>()(cross(a,b,c),0); } // <= -std::eps
}

#ifndef GEOM_EPSILON
	#undef GEOM_EPSILON_UNDEFINED
	#define GEOM_EPSILON_UNDEFINED 1
	#ifdef eps
		#define GEOM_EPSILON(T) (eps)
	#else
		#define GEOM_EPSILON(T) (std::numeric_limits<T>::epsilon())
	#endif
#endif
// override precision functions
// uses epsilon comparison
namespace std{
	#define OVERRIDE_FUNCTIONAL(F,T,expr) \
	template<> class F<T>{ \
		public: \
		inline bool operator()( const T& a, const T& b )const{ \
			return (expr); \
		} \
	}
	OVERRIDE_FUNCTIONAL(equal_to,float, (geom2D::abs(a-b) < GEOM_EPSILON(float)) );
	OVERRIDE_FUNCTIONAL(equal_to,double, (geom2D::abs(a-b) < GEOM_EPSILON(double)) );
	OVERRIDE_FUNCTIONAL(equal_to,long double, (geom2D::abs(a-b) < GEOM_EPSILON(long double)) );
	
	OVERRIDE_FUNCTIONAL(not_equal_to,float, !equal_to<float>()(a,b) );
	OVERRIDE_FUNCTIONAL(not_equal_to,double, !equal_to<double>()(a,b) );
	OVERRIDE_FUNCTIONAL(not_equal_to,long double, !equal_to<long double>()(a,b) );
	
	OVERRIDE_FUNCTIONAL(less,float, (a<b - GEOM_EPSILON(float)) );
	OVERRIDE_FUNCTIONAL(less,double, (a<b - GEOM_EPSILON(double)) );
	OVERRIDE_FUNCTIONAL(less,long double, (a<b - GEOM_EPSILON(long double)) );
	
	OVERRIDE_FUNCTIONAL(less_equal,float, less<float>()(a,b) || equal_to<float>()(a,b) );
	OVERRIDE_FUNCTIONAL(less_equal,double, less<double>()(a,b) || equal_to<double>()(a,b) );
	OVERRIDE_FUNCTIONAL(less_equal,long double, less<long double>()(a,b) || equal_to<long double>()(a,b) );
	
	OVERRIDE_FUNCTIONAL(greater,float, less<float>()(b,a) );
	OVERRIDE_FUNCTIONAL(greater,double, less<double>()(b,a) );
	OVERRIDE_FUNCTIONAL(greater,long double, less<long double>()(b,a) );
	
	OVERRIDE_FUNCTIONAL(greater_equal,float, less_equal<float>()(b,a) );
	OVERRIDE_FUNCTIONAL(greater_equal,double, less_equal<double>()(b,a) );
	OVERRIDE_FUNCTIONAL(greater_equal,long double, less_equal<long double>()(b,a) );
	#undef OVERRIDE_FUNCTIONAL
}
#ifdef GEOM_EPSILON_UNDEFINED
	#undef GEOM_EPSILON_UNDEFINED
	#undef GEOM_EPSILON
#endif
/// forward class definitions
namespace geom2D{

	TYPE1 class point;
	// TYPE1 class vector;
	TYPE1 class line;
	TYPE1 class segment;
	// TYPE1 class ray;
	TYPE3e class polygon;
	TYPE2e class triangle;
	TYPE2e class circle;
	// TYPE2 class ellips;
}

/// forward streams
TYPEo G_INLINE std::istream& operator>>( std::istream&, geom2D::point<oType>& );
TYPEo G_INLINE std::istream& operator>>( std::istream&, geom2D::line<oType>& );
TYPEo G_INLINE std::istream& operator>>( std::istream&, geom2D::segment<oType>& );
TYPE2o G_INLINE std::istream& operator>>( std::istream&, geom2D::circle<oType,oType2>& );
TYPE3o G_INLINE std::istream& operator>>( std::istream&, geom2D::polygon<oType,oType2,oType3>& );

TYPEo G_INLINE std::ostream& operator<<( std::ostream&, const geom2D::point<oType>& );
TYPEo G_INLINE std::ostream& operator<<( std::ostream&, const geom2D::line<oType>& );
TYPEo G_INLINE std::ostream& operator<<( std::ostream&, const geom2D::segment<oType>& );
TYPE2o G_INLINE std::ostream& operator<<( std::ostream&, const geom2D::circle<oType,oType2>& );
TYPE3o G_INLINE std::ostream& operator<<( std::ostream&, const geom2D::polygon<oType,oType2,oType3>& );

namespace geom2D{

	TYPE1 G_INLINE point<Type> triangle_bary( const triangle<Type,point<Type> >& _, const Type& ba, const Type& bb, const Type& bc ){
		Type Sum(ba+bb+bc);
		return point<Type>( ( _.A.x*ba + _.B.x*bb + _.C.x*bc )/Sum, ( _.A.y*ba + _.B.y*bb + _.C.y*bc )/Sum );
	}
	
	TYPE1 class point{
		
		public:
			typedef Type value_type;
			Type x, y;
			point(): x(), y() {}
			TYPEo point( const point<oType>& p ): x(p.x), y(p.y) {}
			point( const Type& a, const Type& b ): x(a), y(b) {}
			std::string toString()const{
				std::ostringstream os;
				os << '(' << x << ',' << y << ')';
				return os.str();
			}
			TYPEo G_INLINE bool isInPolygon( const polygon<oType,point<oType> >& P )const{
				bool in(false);
				for(size_t i=0, j=P.size()-1; i<P.size(); j=i++){
					in ^= (
						( ( P[i].y > y ) != ( P[j].y > y ) )
						&&
						( x < dx(P[i],P[j])*dy(P[i],*this) / dy(P[i],P[j])+P[i].x )
					);
				}
				return in;
			}
			TYPEo G_INLINE bool isOnPolygon( const polygon<oType,point<oType> >& P )const{
				for(size_t i=0, j=P.size()-1; i<P.size(); j=i++)
					if(segment<oType>(P[i],P[j]).contains(*this)) return true;
				return false;
			}
			TYPEo G_INLINE bool isWithinPolygon( const polygon<oType,point<oType> >& P )const{
				return isInPolygon(P) || isOnPolygon(P);
			}
			TYPEo G_INLINE bool isInCircle( const circle<oType,point<oType> >& C )const{ return std::less<Type>( dist2( C.center ), C.r*C.r ); }
			TYPEo G_INLINE bool isOnCircle( const circle<oType,point<oType> >& C )const{ return std::equal_to<Type>( dist2( C.center ), C.r*C.r ); }
			TYPEo G_INLINE bool isWithinCircle( const circle<oType,point<oType> >& C )const{ return std::less_equal<Type>( dist2( C.center ), C.r*C.r ); }
			
			TYPEo G_INLINE point& operator=( const point<oType>& _ ){ x=_.x, y=_.y; return *this; }
			TYPEo G_INLINE bool operator==( const point<oType>& _ )const{ return std::equal_to<Type>()(x,_.x) && std::equal_to<Type>()(y,_.y); }
			TYPEo G_INLINE bool operator!=( const point<oType>& _ )const{ return !operator==(_); }
			TYPEo G_INLINE bool operator<( const point<oType>& _ )const{ return std::less<Type>()(x,_.x) || ( std::equal_to<Type>()(x,_.x) && std::less<Type>()(y,_.y) ); }
			TYPEo G_INLINE bool operator<=( const point<oType>& _ )const{ return std::less<Type>()(x,_.x) || ( std::equal_to<Type>()(x,_.x) && std::less_equal<Type>()(y,_.y) ); }
			TYPEo G_INLINE bool operator>( const point& _ )const{ return std::greater<Type>()(x,_.x) || ( std::equal_to<Type>()(x,_.x) && std::greater<Type>()(y,_.y) ); }
			TYPEo G_INLINE bool operator>=( const point& _ )const{ return std::greater<Type>()(x,_.x) || ( std::equal_to<Type>()(x,_.x) && std::greater_equal<Type>()(y,_.y) ); }
			
			TYPEo G_INLINE Type dist2( const point<oType>& _ )const{
				Type DX = dx(*this,_), DY = dy(*this,_);
				return ( DX*DX + DY*DY );
			}
			
			TYPEo G_INLINE Type cross( const point<oType>& _ )const{ return x*_.y-_.x*y; }
			TYPE2o G_INLINE Type cross( const point<oType>& b, const point<oType2>& c )const{ return point( dx(*this,b), dy(*this,b) ).cross(point( dx(*this,c), dy(*this,c) ) ); }
			TYPEo G_INLINE Type angle( const point<oType>& _ )const{ return atan2( dy(*this,_), dx(*this,_) ); }
			TYPE2o G_INLINE Type angle( const point<oType>& A, const point<oType>& C )const{
				Type
					AB = dist2(A),
					BC = dist2(C),
					CA = A.dist2(C);
				return acos((AB+BC-CA)/(2.0*sqrt(AB)*sqrt(BC)));
			}

	};
	
	TYPE1 class line{
		protected:
			TYPE2o G_INLINE void Normalize( const point<oType>& A_, const point<oType2>& B_ ){ //for 2d
				if(std::equal_to<oType>()(A_.x,B_.x)){
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
			size_t size()const{ return 0u; }
			Type length()const{ return std::numeric_limits<Type>::max(); }
			
			G_INLINE Type x_intercept()const{ return vertical ? b : -b/m; }
			G_INLINE Type y_intercept()const{ return vertical ? m : b; }
			G_INLINE Type y_value( const Type& x )const{ return m*x + b; }
			G_INLINE Type x_value( const Type& y )const{ return (y-b)/m; }
			
			G_INLINE Type slope()const{ return m; }
			// line normal()const{ Type nm = -1/m; return line(nm,b-m*x_value(b)); }
			G_INLINE bool isVertical()const{ return vertical; }
			
			G_INLINE bool contains( const Type& x, const Type& y )const{ return std::equal_to<Type>(y_value(x),y); }
			TYPEo G_INLINE bool contains( const point<oType>& _ )const{ return std::equal_to<Type>(y_value(_.x),_.y); }
			
			TYPEo G_INLINE line& assign( const segment<oType>& _ ){ Normalize(_->A,_->B); return *this; }
			TYPE2o G_INLINE line& assign( const point<oType>& A_, const point<oType2>& B_ ){ Normalize(A_,B_); return *this;}
			G_INLINE line& assign( const Type& A_, const Type& B_ ){ m=A_, b=B_; vertical=false; return *this; }
			G_INLINE line& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign( point<Type>(ax,ay), point<Type>(bx,by) ); }
			TYPEo G_INLINE line& operator=( const oType& _ ){ return assign(_); }
			
			line(){}
			TYPEo line( const oType& _ ){ assign(_); }
			TYPEo line( const oType& p1, const oType& p2 ){ assign(p1,p2); }
			line( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }

			TYPEo G_INLINE bool operator==( const line<oType>& _ )const{ return std::equal_to<Type>()(m,_.m) && std::equal_to<Type>()(b,_.b); }
			TYPEo G_INLINE bool operator!=( const line<oType>& _ )const{ return !operator==(_); }
			TYPEo G_INLINE bool operator<( const line<oType>& _ )const{ return std::less<Type>()(m,_.m) || ( std::equal_to<Type>()(m,_.m) && std::less<Type>()(b,_.b) ); }
			TYPEo G_INLINE bool operator<=( const line<oType>& _ )const{ return std::less<Type>()(m,_.m) || ( std::equal_to<Type>()(m,_.m) && std::less_equal<Type>()(b,_.b) ); }
			TYPEo G_INLINE bool operator>( const line<oType>& _ )const{ return std::greater<Type>()(m,_.m) || ( std::equal_to<Type>()(m,_.m) && std::greater<Type>()(b,_.b) ); }
			TYPEo G_INLINE bool operator>=( const line<oType>& _ )const{ return std::greater<Type>()(m,_.m) || ( std::equal_to<Type>()(m,_.m) && std::greater_equal<Type>()(b,_.b) ); }
			
	};
	TYPE1 class segment{
		public:
			typedef Type value_type;
			point<Type> A, B;
			
			G_INLINE Type length()const{ return dist(A,B); }
			
		protected:
			G_INLINE bool inRange_x( const Type& X )const{ return X>=std::min(A.x,B.x) && X<=std::max(A.x,B.x); }
			G_INLINE bool inRange_y( const Type& Y )const{ return Y>=std::min(A.y,B.y) && Y<=std::max(A.y,B.y); }
			G_INLINE bool inRange_xy( const Type& X, const Type& Y )const{ return inRange_x(X) && inRange_y(Y); }
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
			
			TYPEo G_INLINE bool contains( const point<oType>& _ )const{ return inRange_xy(_) && std::equal_to<Type>(cross(A,_,B),0); }
			G_INLINE bool contains( const Type& x, const Type& y )const{ return contains(point<Type>(x,y)); }
			
			G_INLINE Type slope()const{ return line<Type>(A,B).slope(); }
			G_INLINE bool isVertical()const{ return std::equal_to<Type>(A.x,B.x); }
			
			TYPEo G_INLINE segment& assign( const segment<oType>& _ )const{ A=_.A, B=_.B;  }
			TYPE2o G_INLINE segment& assign( const point<oType>& A_, const point<oType2>& B_ ){ A=A_, B=B_; }
			segment& assign( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ return assign(point<Type>(ax,ay),point<Type>(bx,by)); }
			TYPEo G_INLINE segment& operator=( const segment<oType>& _ ){ return assign(_); }
			
			segment(){}
			segment( const segment& _ ){ assign(_); }
			TYPE2o segment( const point<oType>& p1, const point<oType2>& p2 ){ assign(p1,p2); }
			segment( const Type& ax, const Type& ay, const Type& bx, const Type& by ){ assign(ax,ay,bx,by); }
			
			TYPEo G_INLINE bool operator==( const segment<oType>& _ )const{ return std::equal_to<Type>()(A,_.A) && std::equal_to<Type>()(B,_.B); }
			TYPEo G_INLINE bool operator!=( const segment<oType>& _ )const{ return !operator==(_); }
			TYPEo G_INLINE bool operator<( const segment<oType>& _ )const{ return std::less<point<Type> >()(A,_.A) || ( std::equal_to<point<Type> >()(A,_.A) && std::less<point<Type> >()(B,_.B) ); }
			TYPEo G_INLINE bool operator<=( const segment<oType>& _ )const{ return std::less<point<Type> >()(A,_.A) || ( std::equal_to<point<Type> >()(A,_.A) && std::less_equal<point<Type> >()(B,_.B) ); }
			TYPEo G_INLINE bool operator>( const segment<oType>& _ )const{ return std::greater<point<Type> >()(A,_.A) || ( std::equal_to<point<Type> >()(A,_.A) && std::greater<point<Type> >()(B,_.B) ); }
			TYPEo G_INLINE bool operator>=( const segment<oType>& _ )const{ return std::greater<point<Type> >()(A,_.A) || ( std::equal_to<point<Type> >()(A,_.A) && std::greater_equal<point<Type> >()(B,_.B) ); }
			
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
					if( std::equal_to<Type>()( cp1, cp2 ) ){
						if( std::less_equal<Type>()( val->y, a.y ) ){
							return std::less<Type>()( dist2( *val, a ), dist2( *val, b ) );
						}
						return std::greater<Type>()( dist2( *val, a ), dist2( *val, b ) );
					}
					return std::less<Type>()( cp1, cp2 );
				}
			};
			struct arrange_ccw{
				const pType* val;
				arrange_ccw( const pType& _ ): val( &_ ){}
				bool operator()( const pType& a, const pType& b )const{
					Type cp1 = cross( *val, a, b );
					Type cp2 = cross( *val, b, a );
					if( std::equal_to<Type>()( cp1, cp2 ) ){
						if( std::greater_equal<Type>()( val->y, a.y ) ){
							return std::less<Type>()( dist2( *val, a ), dist2( *val, b ) );
						}
						return std::greater<Type>()( dist2( *val, a ), dist2( *val, b ) );
					}
					return std::greater<Type>()( cp1, cp2 );
				}
			};
			
			
		public:
			typedef Type value_type;
			typedef pType point_type;
			typedef cType container_type;
			typedef std::size_t size_t;
			typedef typename cType::iterator iterator;
			typedef typename cType::reverse_iterator reverse_iterator;
			
			polygon(){}
			TYPEo explicit polygon( const oType& _ ){ for( size_t i=0; i<_.size(); ++i ) push(_[i]); }
			TYPE2o polygon( const oType& first, const oType& last ): v(first,last) {}
			TYPE3o polygon( const polygon<oType,oType2,oType3>& _ ): v(_.v) {}
			// argument list
			explicit polygon( size_t n, const pType& p = pType(), ... ): v(n,p) {
				if(!n) return;
				va_list vl;
				va_start(vl,p);
				for( size_t i=1; i<n; ++i ){
					v[i] = va_arg(vl,pType);
				}
				va_end(vl);
			}
			
			G_INLINE virtual cType& access(){ return v; }
			G_INLINE virtual iterator begin(){ return v.begin(); }
			G_INLINE virtual iterator end(){ return v.end(); }
			G_INLINE virtual reverse_iterator rbegin(){ return v.rbegin(); }
			G_INLINE virtual reverse_iterator rend(){ return v.rend(); }
			
			G_INLINE virtual pType& front(){ return v.front(); }
			G_INLINE virtual pType front() const{ return v.front(); }
			G_INLINE virtual pType& back(){ return v.back(); }
			G_INLINE virtual pType back() const{ return v.back(); }
			
			G_INLINE virtual bool empty()const{ return v.empty(); }
			
			// inherited from cType shortcuts
			G_INLINE void clear(){ v.clear(); }
			G_INLINE polygon& push( const pType& _ ){ v.push_back(_); return *this; }
			G_INLINE polygon& push( const Type& x, const Type& y ){ v.push_back(pType(x,y)); return *this; } // 2d
			G_INLINE polygon& push( const Type&, const Type&, const Type& ); //3d, empty
			G_INLINE polygon& insert( const pType& _ ){ return push(_); }
			G_INLINE polygon& insert( const Type& x, const Type& y ){ return push(x,y); }
			G_INLINE polygon& pop(){ v.pop_back(); return *this; }
			G_INLINE void resize( size_t sz, const pType& _ = pType() ){ v.resize(sz,_); }
			
			G_INLINE virtual size_t size()const{ return v.size(); }
			G_INLINE virtual pType& operator[]( size_t _ ){ return v[_]; }
			G_INLINE virtual pType operator[]( size_t _ )const{ return v[_]; }
			G_INLINE virtual pType& vertex( size_t _ ){ return v[_]; }
			G_INLINE virtual pType vertex( size_t _ )const{ return v[_]; }
			G_INLINE virtual pType& at( size_t _ ){ return v.at(_); }
			G_INLINE virtual pType at( size_t _ )const{ return v.at(_); }
			
			std::string toString()const{
				std::string ans = "[";
				for( size_t i=0; i<size(); ++i ){
					if(i) ans += ',';
					ans += vertex(i).toString();
				}
				ans += ']';
				return ans;
			}
			
			G_INLINE Type boundary()const{
				Type bound(0);
				for( size_t i=0, j=size()-1; i<size(); j=i++ ){
					bound += gcd( abs(dx(vertex(i), vertex(j))), abs(dy(vertex(i), vertex(j))));
				}
				return bound;
			}
			
			G_INLINE Type lattice()const{
				return max( Type(abs(signedArea())-boundary()+2)/2, Type(0) );
			}

			G_INLINE Type signedArea()const{
				Type Area(0);
				for( size_t i=0, j=size()-1; i<size(); j=i++ )
					Area += cross( vertex(j), vertex(i) );
				return Area;
			}		
			
			G_INLINE Type area()const{ return abs(signedArea())/2; }
			G_INLINE Type perimeter()const{
				Type p(0);
				for( size_t i=0, j=size()-1; i<size(); j=i++ )
					p += dist( vertex(i), vertex(j) );
				return p;
			}
			G_INLINE bool isClockwise()const{ return signedArea()>0; }
			G_INLINE bool isCounterclockwise()const{ return signedArea()<0; }
			
			G_INLINE virtual void sort( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				std::swap(vertex(0),*std::min_element( v.begin(), v.end() ));
				
				if(Wise==clockwise) std::stable_sort( v.begin()+1, v.end(), arrange_cw(vertex(0)));
				else std::stable_sort( v.begin()+1,v.end(), arrange_ccw(vertex(0)));
			}
			
			G_INLINE virtual void GrahamScan( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				size_t i;
				for( i=1; i<size(); ++i ){
					if( vertex(i)!=vertex(0) ) break;
				}
				if( i==size() ){
					resize(1);
					return;
				}
				size_t m = 2;
				vertex(1) = vertex(i);
				push(vertex(0));
				if(Wise==clockwise){
					for( i=i+1;i<size();++i){
						while( m>=2 && ccw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				else{
					for( i=i+1;i<size();++i){
						while( m>=2 && cw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				resize( m-1 );
			}
			
			G_INLINE virtual void GrahamScanCollinear( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				size_t i = 1;
				size_t m = 2;
				push(vertex(0));
				if(Wise==clockwise){
					for( ++i;i<size();++i){
						while( m>=2 && !cw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				else{
					for( ++i;i<size();++i){
						while( m>=2 && !ccw( vertex(m-2), vertex(m-1), vertex(i) ) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				resize( m-1 );
			}
			
			G_INLINE virtual void GrahamScanCollinearUnique( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				size_t i;
				for( i=1; i<size(); ++i ){
					if( vertex(i)!=vertex(0) ) break;
				}
				if( i==size() ){
					resize(1);
					return;
				}
				size_t m = 2;
				vertex(1) = vertex(i);
				push(vertex(0));
				if(Wise==clockwise){
					for( ++i;i<size();++i){
						while( m>=2 && (!cw( vertex(m-2), vertex(m-1), vertex(i) )||vertex(m-1)==vertex(i)) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				else{
					for( ++i;i<size();++i){
						while( m>=2 && (!ccw( vertex(m-2), vertex(m-1), vertex(i) )||vertex(m-1)==vertex(i)) ) --m;
						vertex(m) = vertex(i);
						++m;
					}
				}
				resize( m-1 );
			}
			
			G_INLINE polygon& ConvexHull( wise_t Wise = counterclockwise ){
				sort( Wise );
				GrahamScan( Wise );
				return *this;
			}
			
			G_INLINE polygon& ConvexHullCollinear( wise_t Wise = counterclockwise ){
				sort( Wise );
				GrahamScanCollinear( Wise );
				return *this;
			}
			
			G_INLINE polygon& ConvexHullCollinearUnique( wise_t Wise = counterclockwise ){
				sort( Wise );
				GrahamScanCollinearUnique( Wise );
				return *this;
			}
			
			G_INLINE polygon hull( wise_t Wise = counterclockwise )const{
				return polygon( *this ).ConvexHull( Wise );
			}
			
			G_INLINE polygon hullCollinear( wise_t Wise = counterclockwise ) const{
				return polygon( *this ).ConvexHullCollinear( Wise );
			}
			
			G_INLINE polygon hullCollinearUnique( wise_t Wise = counterclockwise ) const{
				return polygon( *this ).ConvexHullCollinearUnique( Wise );
			}
			
			// 2D so far
			G_INLINE pType centroid()const{
				Type x(0), y(0), a;
				for( size_t j=0, i=size()-1; j<size(); i=j++ ){
					a = cross(vertex(i),vertex(j));
					x += a * ( vertex(i).x + vertex(j).x );
					y += a * ( vertex(i).y + vertex(j).y );
				}
				a = signedArea()*3;
				return pType( x/a, y/a );
			}
			
			G_INLINE polygon& operator+=( const pType& _ ){ return push(_); }
			TYPE3o G_INLINE polygon& operator+=( const polygon<oType,oType2,oType3>& _ ){ for(size_t i=0,I=_.size();i<I;++i) push(_.vertex(i)); return *this; }
			TYPEo G_INLINE polygon operator+( const oType& _ )const{ return polygon(*this)+=_; }

			TYPE3o G_INLINE bool operator==( const polygon<oType,oType2,oType3>& _ )const{ return std::equal_to<container_type>(v,_.v); }
			TYPE3o G_INLINE bool operator!=( const polygon<oType,oType2,oType3>& _ )const{ return !operator==(_); }
			TYPE3o G_INLINE bool operator<( const polygon<oType,oType2,oType3>& _ )const{ return std::less<container_type>(v,_.v); }
			TYPE3o G_INLINE bool operator<=( const polygon<oType,oType2,oType3>& _ )const{ return std::less_equal<container_type>(v,_.v); }
			TYPE3o G_INLINE bool operator>( const polygon<oType,oType2,oType3>& _ )const{ return std::greater<container_type>(v,_.v); }
			TYPE3o G_INLINE bool operator>=( const polygon<oType,oType2,oType3>& _ )const{ return std::greater_equal<container_type>(v,_.v); }
			
	};
	
	TYPE2 class triangle: public polygon<Type,pType>{
		public:
			static bool simple;
			typedef Type value_type;
			typedef pType point_type;
			typedef typename polygon<Type,pType>::arrange_cw arrange_cw;
			typedef typename polygon<Type,pType>::arrange_ccw arrange_ccw;
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
			
			G_INLINE size_t size()const{ return 3; }
			G_INLINE bool empty()const{ return false; }
			triangle(){}
			TYPEo triangle( oType& _ ): A(_[0]), B(_[1]), C(_[2]) { if(!simple) update(); } //container
			TYPEo triangle& operator=( oType& _ ){ A = _[0], B = _[1], C = _[2]; if(!simple) update(); }
			triangle( pType* _ ): A(_[0]), B(_[1]), C(_[2]) { if(!simple) update(); } //array
			triangle( const pType& pa, const pType& pb, const pType& pc ): A(pa), B(pb), C(pc) { if(!simple) update(); }
			triangle( const Type& ax, const Type& ay, const Type& bx, const Type& by, const Type& cx, const Type& cy ): A(ax,ay), B(bx,by), C(cx,cy) { if(!simple) update(); }
			triangle( const Type& ax, const Type& ay, const Type& az, const Type& bx, const Type& by, const Type& bz, const Type& cx, const Type& cy, const Type& cz ): A(ax,ay,az), B(bx,by,bz), C(cx,cy,cz) { if(!simple) update(); }
			
			G_INLINE pType& operator[]( size_t _ ){ return *(&A+_); }
			G_INLINE pType operator[]( size_t _ )const{ return *(&A+_); }
			G_INLINE pType& vertex( size_t _ ){ return *(&A+_); }
			G_INLINE pType vertex( size_t _ )const{ return *(&A+_); }
			G_INLINE pType& at( size_t _ ){ if(_>=this->size()) throw std::out_of_range("triangle::at( pos )"); return this->operator[](_); }
			G_INLINE pType at( size_t _ )const{ if(_>=this->size()) throw std::out_of_range("triangle::at( pos )"); return this->operator[](_); }
			
			G_INLINE Type alpha()const{ return al; }
			G_INLINE Type beta()const{ return be; }
			G_INLINE Type gamma()const{ return ga; }
			
			G_INLINE void sort( wise_t Wise = counterclockwise ){
				std::swap(vertex(0),*std::min_element( (pType*)&vertex(0), (pType*)&vertex(3) ));
				if(Wise==clockwise){
					if( arrange_cw(vertex(0))(vertex(2),vertex(1)) )
						std::swap( vertex(1), vertex(2) );
				}
				else{
					if( arrange_ccw(vertex(0))(vertex(2),vertex(1)) )
						std::swap( vertex(1), vertex(2) );
				}
				if(!simple)
				update();
			}
			G_INLINE void GrahamScan( wise_t Wise = counterclockwise ){ throw std::logic_error("geom2D::triangle has fixed size, cannot perform Graham Scan.\n           Suggested Alternative/s: geom2D::polygon"); }
			G_INLINE void GrahamScanCollinear( wise_t Wise = counterclockwise ){ this->GrahamScan(); }
			G_INLINE void GrahamScanCollinearUnique( wise_t Wise = counterclockwise ){ this->GrahamScan(); }
			
			G_INLINE Type inradius()const{ return abs( this->signedArea() ) / this->perimeter(); }
			G_INLINE Type circumradius()const{ return a*b*c/(2*abs( this->signedArea() )); }
			G_INLINE pType bary( const Type& ba, const Type& bb, const Type& bc )const{ return triangle_bary(*this, ba,bb,bc); }
			G_INLINE pType brocard1()const{ return bary(a*c/b,b*a/c,c*b/a); }
			G_INLINE pType brocard2()const{ return bary(a*b/c,b*c/a,c*a/b); }
			G_INLINE pType orthocenter()const{ return bary(tan(al),tan(be),tan(ga)); }
			G_INLINE pType excenterA()const{ return bary(-a,b,c); }
			G_INLINE pType excenterB()const{ return bary(a,-b,c); }
			G_INLINE pType excenterC()const{ return bary(a,b,-c); }
	};
	TYPE2 bool triangle<Type,pType>::simple = false;
		
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
			
			G_INLINE size_t size() const{ return 1u; }
			
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
TYPE2o G_INLINE std::istream& operator>>( std::istream& in, geom2D::circle<oType,oType2>& cc ){ return in >> cc.center >> cc.r; }
TYPE3o G_INLINE std::istream& operator>>( std::istream& in, geom2D::polygon<oType,oType2,oType3>& pl ){ for(size_t i=0;i<pl.size();++i) in >> pl[i]; return in; }

TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::point<oType>& pt ){ return out << pt.x << ' ' << pt.y; }
TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::line<oType>& ln ){ return out << ln.slope() << ' ' << ln.b; }
TYPEo G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::segment<oType>& sg ){ return out << sg.A << ' ' << sg.B; }
TYPE2o G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::circle<oType,oType2>& cc ){ return out << cc.center << ' ' << cc.r; }
TYPE3o G_INLINE std::ostream& operator<<( std::ostream& out, const geom2D::polygon<oType,oType2,oType3>& pl ){ if(!pl.empty()){ out << pl.vertex(0); for(size_t i=1;i<pl.size();++i) out << ' ' << pl.vertex(i);} return out; }

#undef TYPEp
#undef TYPEpp
#undef TYPEppp
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
typedef geom2D::polygon<double> Polygon;
typedef geom2D::triangle<double> Triangle;
typedef geom2D::circle<double> Circle;

#endif /* _INCLUDE_GEOM */
/** END Geom v2.5 **/
/** IsosceleS 2013 (c) **/
using namespace std;
Polygon p;
int t, n, i, j, W;
double init, amnt, fall, volume;
int main(){
	cin >> t;
	while( t-- ){
		cin >> n;
		p.resize(n);
		cin >> p >> W;
		cin >> init >> amnt >> fall;
		volume = p.area()*W;
		amnt = volume * init / 100.0 - amnt;
		if( amnt < 0 ){
			amnt = 0;
			cout << "Lack of water. ";
		}
		if( (amnt+=fall) > volume ){
			amnt = volume;
			cout << "Excess of water. ";
		}
		cout << "Final percentage: " << (int)( 100.0* amnt/volume ) << "%\n";
	}
}
