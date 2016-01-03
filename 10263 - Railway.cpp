/**
	UVa 10263 - Railway
	by Rico Tiongson
	Submitted: September 24, 2013
	Accepted 0.019s C++
	O(n) time
*/
/** START Geom v2.5.3 **/
/** IsosceleS 2013 (c) **/

/// notes: define complex_triangle
/// for faster trianlge operations

#ifndef _INCLUDE_GEOM
#define _INCLUDE_GEOM 1

#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
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

#ifndef GEOM_EPSILON
	#undef GEOM_EPSILON_UNDEFINED
	#define GEOM_EPSILON_UNDEFINED 1
	#ifdef eps
		#define GEOM_EPSILON(T) ((T)eps)
	#else
		#define GEOM_EPSILON(T) (std::numeric_limits<T>::epsilon())
	#endif
#endif
// override precision functions
// uses epsilon comparison
namespace geom{
	namespace math{
	
		TYPE1 Type abs( Type _ ){ return _>=0 ? _ : -_; }
		float abs( float _ ){ return std::abs(_); }
		double abs( double _ ){ return std::abs(_); }
		long double abs( long double _ ){ return std::abs(_); }
		
		TYPE1 Type mod( Type a, Type b ){ return a%b; }
		float mod( float a, float b ){ return std::fmod(a,b); }
		double mod( double a, double b ){ return std::fmod(a,b); }
		long double mod( long double a, long double b ){ return std::fmod(a,b); }
		
		TYPE1 Type gcd( Type a, Type b ){
			Type temp;
			while(a>0){
				temp = a;
				a = geom::math::mod(b,a);
				b = temp;
			}
			return b;
		}
		
		double RAD( double deg ){ return deg*PI/180.0; }
		double DEG( double rad ){ return rad*180.0/PI; }
		
		TYPE1 Type epsilon(){ return GEOM_EPSILON(Type); }
		
	}
}
namespace std{
	#define MAKE_FUNCTION(F,T,expr) \
	template<> class F<T>{ \
		public: \
		inline bool operator()( const T& a, const T& b )const{ \
			return (expr); \
		} \
	}
	MAKE_FUNCTION(equal_to,float, (geom::math::abs(a-b) < geom::math::epsilon<float>()) );
	MAKE_FUNCTION(equal_to,double, (geom::math::abs(a-b) < geom::math::epsilon<double>()) );
	MAKE_FUNCTION(equal_to,long double, (geom::math::abs(a-b) < geom::math::epsilon<long double>()) );
	
	MAKE_FUNCTION(not_equal_to,float, !equal_to<float>()(a,b) );
	MAKE_FUNCTION(not_equal_to,double, !equal_to<double>()(a,b) );
	MAKE_FUNCTION(not_equal_to,long double, !equal_to<long double>()(a,b) );
	
	MAKE_FUNCTION(less,float, (a<b - geom::math::epsilon<float>()) );
	MAKE_FUNCTION(less,double, (a<b - geom::math::epsilon<double>()) );
	MAKE_FUNCTION(less,long double, (a<b - geom::math::epsilon<long double>()) );
	
	MAKE_FUNCTION(less_equal,float, less<float>()(a,b) || equal_to<float>()(a,b) );
	MAKE_FUNCTION(less_equal,double, less<double>()(a,b) || equal_to<double>()(a,b) );
	MAKE_FUNCTION(less_equal,long double, less<long double>()(a,b) || equal_to<long double>()(a,b) );
	
	MAKE_FUNCTION(greater,float, less<float>()(b,a) );
	MAKE_FUNCTION(greater,double, less<double>()(b,a) );
	MAKE_FUNCTION(greater,long double, less<long double>()(b,a) );
	
	MAKE_FUNCTION(greater_equal,float, less_equal<float>()(b,a) );
	MAKE_FUNCTION(greater_equal,double, less_equal<double>()(b,a) );
	MAKE_FUNCTION(greater_equal,long double, less_equal<long double>()(b,a) );
	#undef MAKE_FUNCTION
}
#ifdef GEOM_EPSILON_UNDEFINED
	#undef GEOM_EPSILON_UNDEFINED
	#undef GEOM_EPSILON
#endif

/// global functions
/// forward declarations
namespace geom{
	
	TYPE1 class point;
	TYPE1 class pointRT;
	// TYPE1 class vector;
	TYPE2e class line;
	TYPE2e class segment;
	TYPE3e class polygon;
	TYPE2e class triangle;
	TYPE2e class circle;
	// TYPE2 class ellips;
	
	TYPE2o point<oType> make_point( const oType& a, const oType2& b ){ return point<oType>(a,b); }
	
	TYPE2o line<typename oType::value_type,oType> make_line( const oType& a, const oType2& b ){ return line<typename oType::value_type,oType>(a,b); }
	template<class T1,class T2,class T3,class T4> line<T1> make_line( const T1& ax, const T2& ay, const T3& bx, const T4& by ){ return make_line(make_point(ax,ay),make_point(bx,by)); }
	TYPE2o segment<typename oType::value_type,oType> make_segment( const oType& a, const oType2& b ){ return segment<typename oType::value_type,oType>(a,b); }
	template<class T1,class T2,class T3,class T4> segment<T1> make_segment( const T1& ax, const T2& ay, const T3& bx, const T4& by ){ return make_segment(make_point(ax,ay),make_point(bx,by)); }
	
	
	enum wise_t{ counterclockwise=0, clockwise };
	
	TYPEpp dot( const pType& a, const pType2& b ){ return a.dot(b); }
	TYPEpp dist2( const pType& a, const pType2& b ){ return a.dist2(b); }
	TYPEpp dist( const pType& a, const pType2& b ){ return std::sqrt( dist2(a,b) ); }
	TYPEpp cross( const pType& a, const pType2& b ){ return a.cross(b); }
	TYPEppp cross( const pType& a, const pType2& b, const pType3& c ){ return cross(a,b)+cross(b,c)+cross(c,a); }
	TYPEpp dx( const pType& a, const pType2& b ){ return b.x-a.x; }
	TYPEpp dy( const pType& a, const pType2& b ){ return b.y-a.y; }
	TYPEpp angle( const pType& a, const pType2& b ){ return a.angle(b); }
	TYPEppp angle( const pType& a, const pType2& b, const pType3& c ){ return b.angle(a,c); }
	TYPE2o oType rotate( const oType& a, const oType2& t ){ return a.rotate(t); }
	TYPE3o oType rotate( const oType& a, const oType2& b, const oType3& t ){ return a+rotate(b-a,t); }

	TYPE3o bool ccw( const oType& a, const oType2& b, const oType3& c ){ return std::greater_equal<typename oType::value_type>()(cross(a,b,c),0); } // >= std::eps
	TYPE3o bool cw( const oType& a, const oType2& b, const oType3& c ){ return std::less_equal<typename oType::value_type>()(cross(a,b,c),0); } // <= -std::eps
	
}

/// forward streams

#undef MAKE_STREAM1
#undef MAKE_STREAM2
#undef MAKE_STREAM3
#define MAKE_STREAM1(T,OP,T2,C) \
	TYPEo std::T& operator OP( std::T&, C geom::T2<oType>& )
#define MAKE_STREAM2(T,OP,T2,C) \
	TYPE2o std::T& operator OP( std::T&, C geom::T2<oType,oType2>& )
#define MAKE_STREAM3(T,OP,T2,C) \
	TYPE3o std::T& operator OP( std::T&, C geom::T2<oType,oType2,oType3>& )

MAKE_STREAM1(istream,>>,point,);
MAKE_STREAM1(ostream,<<,point,const);

MAKE_STREAM2(istream,>>,line,);
// MAKE_STREAM2(istream,>>,segment);
MAKE_STREAM2(istream,>>,circle,);
MAKE_STREAM2(ostream,<<,line,const);
// MAKE_STREAM2(ostream,<<,segment);
MAKE_STREAM2(ostream,<<,circle,const);

MAKE_STREAM3(istream,>>,polygon,);
MAKE_STREAM3(ostream,<<,polygon,const);
#ifdef complex_triangle
MAKE_STREAM2(istream,>>,triangle,);
#endif

#undef MAKE_STREAM1
#undef MAKE_STREAM2
#undef MAKE_STREAM3

namespace geom{
	
	TYPE1 class point{
		public:
			typedef Type value_type;
			Type x, y;
			point(): x(), y() {}
			point( const Type& X, const Type& Y ): x(X), y(Y) {}
			TYPEo point( const point<oType>& p ): x(p.x), y(p.y) {}
			TYPE2o point( const point<oType>& p1, const point<oType2>& p2 ): x(dx(p1,p2)), y(dy(p1,p2)) {}
			TYPEo point& operator=( const point<oType>& p ){ x=p.x, y=p.y; return *this; }
			std::string toString()const{
				std::ostringstream os;
				os << '(' << x << ',' << y << ')';
				return os.str();
			}
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(N) \
				TYPE3o bool N( const polygon<oType,point<oType2>,oType3>& p )const
				MAKE_FUNCTION(isInPolygon){
					bool in = false;
					for( int i=0, j=p.size()-1; i<p.size(); j=i++ ){
						in ^= (
							(( std::greater<oType>()( p[i].y, (oType)y ) ) != ( std::greater<oType>()(p[j].y, (oType)y )))
							&& 
							std::less<oType>()( (oType)x, (oType)dx(p[i],p[j])*dy(p[i],*this) / dy(p[i],p[j])+p[i].x )
						);
					}
					return in;
				}
				MAKE_FUNCTION(isOnPolygon){
					for(int i=0, j=p.size()-1; i<p.size(); j=i++)
						if(segment<oType2>(p[i],p[j]).contains(*this)) return true;
					return false;
				}
				MAKE_FUNCTION(isWithinPolygon){
					return isInPolygon(p) || isOnPolygon(p);
				}
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(N,OP) \
				TYPE2o bool N( const circle<oType,point<oType2> >& c )const{ \
					return std::OP<Type>()( dist2( c.center ), (Type)c.r*c.r ); \
				}
				MAKE_FUNCTION( isInCircle, less )
				MAKE_FUNCTION( isOnCircle, equal_to )
				MAKE_FUNCTION( isWithinCircle, less_equal )
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(OP,F) \
				TYPEo bool operator OP( const point<oType>& p )const{ return F; }
				MAKE_FUNCTION(==,std::equal_to<Type>()(x,(Type)p.x) && std::equal_to<Type>()(y,(Type)p.y))
				MAKE_FUNCTION(!=,!operator==(p))
				MAKE_FUNCTION(<,std::less<Type>()(x,(Type)p.x) || ( std::equal_to<Type>()(x,(Type)p.x) && std::less<Type>()(y,(Type)p.y)))
				MAKE_FUNCTION(>,p.operator<(*this))
				MAKE_FUNCTION(>=,!operator<(p))
				MAKE_FUNCTION(<=,p.operator>=(*this))
			#undef MAKE_FUNCTION
			
			TYPEo Type dist2( const point<oType>& p )const{
				point v(*this,p);
				return v.dot(v);
			}
			TYPE2o Type dist2( const line<oType,point<oType2> >& l )const{
				return dist2( l.nearestPoint(*this) );
			}
			TYPEo Type dot( const point<oType>& p )const{ return x*p.x+y*p.y; }
			TYPEo Type cross( const point<oType>& p )const{ return x*p.y-p.x*y; }
			TYPEo Type angle( const point<oType>& _ )const{ return atan2( dy(*this,_), dx(*this,_) ); }
			TYPE2o Type angle( const point<oType>& A, const point<oType2>& C )const{
				Type
					AB = dist2(A),
					BC = dist2(C),
					CA = A.dist2(C);
				return acos((AB+BC-CA)/(2.0*sqrt(AB)*sqrt(BC)));
			}
			
			TYPE2o bool inRange( const point<oType>& A, const point<oType2>& B )const{
				return std::greater_equal<Type>()( x, std::min<Type>( A.x, B.x ) )
				&& std::less_equal<Type>()( x, std::max<Type>( A.x, B.x ) )
				&& std::greater_equal<Type>()( y, std::min<Type>( A.y, B.y ) )
				&& std::less_equal<Type>()( y, std::max<Type>( A.y, B.y ) );
			}
			TYPE2o bool inRange( const line<oType,oType2>& l )const{ return true; }
			TYPE2o bool inRange( const segment<oType,oType2>& s )const{ return inRange(s.A,s.B); }
			
			point rotate( const Type& t )const{ return point(x*cos(t)-y*sin(t),x*sin(t)+y*cos(t)); }
			#define MAKE_FUNCTION(OP,OP2) \
				TYPEo point operator OP( const point<oType>& p )const{ return point( x OP p.x, y OP p.y ); } \
				TYPEo point& operator OP2 ( const point<oType>& p ){ x OP2 p.x, y OP2 p.y; return *this; }
			#undef SCALAR_FUNCTION
			#define SCALAR_FUNCTION(OP,OP2) \
				point operator OP( const Type& p )const{ return point( x OP p, y OP p ); } \
				point& operator OP2 ( const Type& p ){ x OP2 p, y OP2 p; return *this; }
				MAKE_FUNCTION(+,+=)
				MAKE_FUNCTION(-,-=)
				SCALAR_FUNCTION(+,+=)
				SCALAR_FUNCTION(-,-=)
				SCALAR_FUNCTION(/,/=)
				SCALAR_FUNCTION(*,*=)
				// SCALAR_FUNCTION(%,%=)
				point operator %( const Type& p )const{ return point( geom::math::mod(x,p), geom::math::mod(y,p) ); }
				point& operator %=( const Type& p )const{ return *this = operator%(p); }
				SCALAR_FUNCTION(^,^=)
				SCALAR_FUNCTION(&,&=)
				SCALAR_FUNCTION(|,|=)
			#undef MAKE_FUNCTION
			#undef SCALAR_FUNCTION
			
			
			
			int dimensions()const{ return 2; }
			Type& operator[]( int pos ){ return ((Type*)&x)[pos]; }
			Type operator[]( int pos )const{ return ((Type*)&x)[pos]; }
			
	};
	
	TYPE2 class line{
		
		public:
			
			typedef Type value_type;
			typedef pType point_type;
			pType A, B;
			
			line(): A(), B() {}
			TYPE2o line( const line<oType,oType2>& l ): A(l.A), B(l.B) {}
			TYPE2o line( const segment<oType,oType2>& s ): A(s.A), B(s.B) {}
			line( const pType& a, const pType& b ): A(a), B(b) {}
			
			virtual Type length()const{ return std::numeric_limits<Type>::max(); }
			
			virtual bool contains( const pType& p )const{
				return std::equal_to<Type>()( (Type)cross(A,p,B), (Type)0 );
			}
			
			virtual pType nearestPoint( const pType& p )const{
				if(A==B) return A;
				return A + (B-A)*dot( p-A, B-A )/geom::dist2(A,B);
			}
			
			Type dist2( const pType& p )const{ return geom::dist2( this->nearestPoint(p), p ); }
			
			void rotate( const Type& theta ){ B = geom::rotate(A,B,theta); }
			Type angle()const{ return geom::angle(A,B); }
			
			bool isVertical()const{ return std::equal_to<typename pType::value_type>()( A.x, B.x ); }
			bool isHorizontal()const{ return std::equal_to<typename pType::value_type>()( A.y, B.y ); }
			Type slope()const{ return isVertical() ? std::numeric_limits<Type>::quiet_NaN() : dy(A,B)/dx(A,B); }
			
			Type x_intercept()const{ return isVertical() ? A.x : -y_intercept()/slope(); }
			Type y_intercept()const{ return A.y - slope()*A.x; }
			Type x_value( const Type& y )const{ return (y-y_intercept())/slope(); }
			Type y_value( const Type& x )const{ return slope()*x+y_intercept(); }
			
			std::string toString()const{ return A.toString() + " " + B.toString(); }
			
			TYPE2o bool parallel( const line<oType,oType2>& l )const{ return std::equal_to<Type>()( cross(pType(A,B),pType(l.A,l.B)), 0 ); }
			TYPE2o bool collinear( const line<oType,oType2>& l )const{ return parallel(l) && std::equal_to<Type>()( cross(pType(A,l.A),pType(B,l.B)), 0 ); }
			
			TYPE2o bool equals( const line<oType,oType2>& l )const{ return collinear(l); }
			
			TYPE2o pType* intersection( const line<oType,oType2>& l )const{
				if( parallel(l) ) return NULL;
				pType v1(A,B);
				pType v2(l.B,l.A);
				pType v3(A,l.A);
				if( std::equal_to<Type>()(dot(v1,v1),0) ) return new pType(A);
				if( std::equal_to<Type>()(dot(v2,v2),0) ) return new pType(v3);
				return new pType(A + (v1*cross(v3,v2)/cross(v1,v2)) );
			}
			TYPE2o pType* intersection( const segment<oType,oType2>& s )const{
				pType* i = intersection( line<oType,oType2>(s) );
				if( i!=NULL && i->inRange(s) ) return i;
				return NULL;
			}
			
			#define MAKE_FUNCTION(OP,F) \
				TYPE2o bool operator OP( const line<oType,oType2>& S )const{ return F; }
				MAKE_FUNCTION(==,A==S.A&&B==S.B)
				MAKE_FUNCTION(!=,!operator==(S))
				MAKE_FUNCTION(<,A<S.A||(A==S.A&&B<S.B))
				MAKE_FUNCTION(>,S.operator<(*this))
				MAKE_FUNCTION(>=,!operator<(S))
				MAKE_FUNCTION(<=,S.operator>=(*this))
			#undef MAKE_FUNCTION
		
	};
	
	TYPE2 class segment: public line<Type,pType>{
		
		public:
			
			Type length()const{ return dist(this->A,this->B); }
			
			bool ranges( const pType& p )const{ return p.inRange(*this); }
			
			Type single_lattice()const{
				pType v(this->A,this->B);
				Type g = geom::math::abs( v[0] );
				for( int i=1; i<v.dimensions(); ++i ){
					g = geom::math::gcd( g, geom::math::abs( v[i] ) );
				}
				return g;
			}
			
			bool double_lattice()const{
				if( std::numeric_limits<Type>::is_integer ) return true;
				for( int i=0; i<this->A.dimensions(); ++i ){
					if( std::not_equal_to<Type>()( this->A[i], round(this->A[i]) ) ) return false;
					if( std::not_equal_to<Type>()( this->B[i], round(this->B[i]) ) ) return false;
				}
				return true;
			}
			
			Type lattice()const{
				return single_lattice() + double_lattice();
			}
			
			bool contains( const pType& p )const{
				return ranges(p) && std::equal_to<Type>()( (Type)cross(this->A,p,this->B), (Type)0 );
			}
			
			pType nearestPoint( const pType& p )const{
				const pType& v = this->A;
				const pType& w = this->B;
				if(w==v) return w;
				Type d = dot(p-v,w-v)/geom::dist2(v,w);
				if( std::less<Type>()( d, (Type)0 ) ) return v;
				if( std::greater<Type>()( d, (Type)1 ) ) return w;
				return v + (w-v)*d;
			}
			segment() {}
			TYPE2o segment( const line<oType,oType2>& l ) { this->A = l.A, this->B = l.B; }
			TYPE2o segment( const segment<oType,oType2>& s ) { this->A = s.A, this->B = s.B; }
			segment( const pType& a, const pType& b ) { this->A = a, this->B = b; }
			
			TYPE2o pType* intersection( const line<oType,oType2>& l )const{
				pType* i = line<Type,pType>(*this).intersection( l );
				if( i!=NULL && ranges(*i) ) return i;
				return NULL;
			}
			
			TYPE2o pType* intersection( const segment<oType,oType2>& s )const{
				pType* i = line<Type,pType>(*this).intersection( line<oType,oType2>(s) );
				if( i!=NULL && ranges(*i) && s.ranges(*i) ) return i;
				return NULL;
			}
			
			TYPE2o bool equals( const segment<oType,oType2>& S )const{ return (this->A==S.A && this->B==S.B) || (this->A==S.B && this->B==S.A); }
			
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
			
			polygon(): v() {}
			TYPEo polygon( const oType& o ): v( o.begin(), o.end() ) {}
			TYPE2o polygon( const triangle<oType,oType2>& t ): v(3){ v[0] = t.A, v[1] = t.B, v[2] = t.C; }
			TYPE2o polygon( const oType& first, const oType2& last ): v( first, last ) {}
			explicit polygon( size_t n, const pType& p = pType() ): v(n,p) {}
			
			
			virtual cType& access(){ return v; }
			virtual cType access()const{ return v; }
			virtual iterator begin(){ return v.begin(); }
			virtual iterator end(){ return v.end(); }
			virtual reverse_iterator rbegin(){ return v.rbegin(); }
			virtual reverse_iterator rend(){ return v.rend(); }
			
			virtual pType& front(){ return v.front(); }
			virtual pType front() const{ return v.front(); }
			virtual pType& back(){ return v.back(); }
			virtual pType back() const{ return v.back(); }
			
			virtual bool empty()const{ return v.empty(); }
			
			// inherited from cType shortcuts
			virtual void clear(){ v.clear(); }
			virtual polygon& push( const pType& _ ){ v.push_back(_); return *this; }
			virtual polygon& push( const Type& x, const Type& y ){ v.push_back(pType(x,y)); return *this; }
			virtual polygon& add( const pType& _ ){ push(_); return *this; }
			virtual polygon& add( const Type& x, const Type& y ){ push(pType(x,y)); return *this; }
			virtual polygon& insert( const pType& _ ){ return push(_); }
			virtual polygon& insert( const Type& x, const Type& y ){ return push(x,y); }
			virtual iterator insert( const iterator& pos, const pType& p ){ return v.insert(pos,p); }
			virtual polygon& pop(){ v.pop_back(); return *this; }
			void resize( size_t sz, const pType& _ = pType() ){ v.resize(sz,_); }
			
			virtual size_t size()const{ return v.size(); }
			virtual pType& operator[]( size_t _ ){ return v[_]; }
			virtual pType operator[]( size_t _ )const{ return v[_]; }
			virtual pType& vertex( size_t _ ){ return v[_]; }
			virtual pType vertex( size_t _ )const{ return v[_]; }
			virtual pType& at( size_t _ ){ return v.at(_); }
			virtual pType at( size_t _ )const{ return v.at(_); }
			
			/// returns polygon cross-section (works only on convex polygons)
			TYPE3o polygon intersection( const polygon<oType,oType2,oType3>& p )const{
				int i, I, j, J;
				polygon ans;
				pType* isect;
				segment<Type,pType> s;
				segment<oType,oType2> s2;
				for( i=0; i<size(); ++i ){
					if( vertex(i).isWithinPolygon(p) )
						ans.push( vertex(i) );
				}
				for( j=0; j<p.size(); ++j ){
					if( p[j].isWithinPolygon(*this) )
						ans.push( p[j] );
				}
				for( i=0, I=size()-1; i<size(); I=i++ ){
					s = segment<Type,pType>(vertex(i),vertex(I));
					for( j=0, J=p.size()-1; j<p.size(); J=j++ ){
						s2 = segment<oType,oType2>(p[j],p[J]);
						isect = s.intersection(s2);
						if( isect!=NULL ){
							ans.push(*isect);
						}
					}
				}
				ans.ConvexHull();
				return ans;
			}
			
			std::string toString()const{
				std::string ans = "[";
				for( size_t i=0; i<size(); ++i ){
					if(i) ans += ',';
					ans += vertex(i).toString();
				}
				ans += ']';
				return ans;
			}
			
			Type boundary()const{
				Type bound = 0;
				for( int i=0, j=size()-1; i<size(); j=i++ ){
					bound += make_segment( vertex(i), vertex(j) ).single_lattice();
				}
				return bound;
			}
			
			Type lattice()const{
				return std::max( Type( geom::math::abs( signedArea() )-boundary()+2 )/2, (Type)0 );
			}
			
			Type signedArea()const{
				Type a = 0;
				for( int i=0, j=size()-1; i<size(); j=i++ )
					a += cross( vertex(i), vertex(j) );
				return a;
			}
			
			Type area()const{ return geom::math::abs( (Type)signedArea() )/2; }
			Type perimeter()const{
				Type p = 0;
				for( int i=0, j=size()-1; i<size(); j=i++ )
					p += sqrt( (Type)dist2( vertex(i), vertex(j) ) );
				return p;
			}
			
			bool isClockwise()const{ return signedArea()>0; }
			bool isCounterclockwise()const{ return signedArea()<0; }
			
			void sort( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				std::swap( vertex(0), *std::min_element( begin(), end() ) );
				if( Wise==clockwise ) std::stable_sort( v.begin()+1, v.end(), arrange_cw( vertex(0) ) );
				else std::stable_sort( v.begin()+1, v.end(), arrange_ccw( vertex(0) ) );
			}
			
			virtual void GrahamScan( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				int i;
				for( i=1; i<size(); ++i ){
					if( vertex(i)!=vertex(0) ) break;
				}
				if( i==size() ){
					resize(1);
					return;
				}
				int m = 1;
				vertex(1) = vertex(i);
				push(vertex(0));
				if(Wise==clockwise){
					for( ++i;i<size();++i){
						while( m>0 && ccw( vertex(m-1), vertex(m), vertex(i) ) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				else{
					for( ++i;i<size();++i){
						while( m>0 && cw( vertex(m-1), vertex(m), vertex(i) ) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				resize( m );
			}
			
			virtual void GrahamScanCollinear( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				int i = 1;
				int m = 1;
				push(vertex(0));
				if(Wise==clockwise){
					for( ++i;i<size();++i){
						while( m>0 && !cw( vertex(m-1), vertex(m), vertex(i) ) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				else{
					for( ++i;i<size();++i){
						while( m>0 && !ccw( vertex(m-1), vertex(m), vertex(i) ) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				resize( m );
			}
			
			virtual void GrahamScanCollinearUnique( wise_t Wise = counterclockwise ){
				if( empty() ) return;
				int i;
				for( i=1; i<size(); ++i ){
					if( vertex(i)!=vertex(0) ) break;
				}
				if( i==size() ){
					resize(1);
					return;
				}
				int m = 1;
				vertex(1) = vertex(i);
				push(vertex(0));
				if(Wise==clockwise){
					for( ++i;i<size();++i){
						while( m>0 && (!cw( vertex(m-1), vertex(m), vertex(i) )||vertex(m)==vertex(i)) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				else{
					for( ++i;i<size();++i){
						while( m>0 && (!ccw( vertex(m-1), vertex(m), vertex(i) )||vertex(m)==vertex(i)) ) --m;
						vertex(++m) = vertex(i);
					}
				}
				resize( m );
			}
			
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(N,N2) \
				polygon& N( wise_t Wise = counterclockwise ){ \
					sort( Wise ); \
					N2( Wise ); \
					return *this; \
				}
			MAKE_FUNCTION(ConvexHull,GrahamScan)
			MAKE_FUNCTION(ConvexHullCollinear,GrahamScanCollinear)
			MAKE_FUNCTION(ConvexHullCollinearUnique,GrahamScanCollinearUnique)
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(N,N2) \
				polygon N( wise_t Wise = counterclockwise )const{ \
					return polygon( *this ). N2( Wise ); \
				}
			MAKE_FUNCTION(hull,ConvexHull)
			MAKE_FUNCTION(hullCollinear,ConvexHullCollinear)
			MAKE_FUNCTION(hullCollinearUnique,ConvexHullCollinearUnique)
			#undef MAKE_FUNCTION
			pType centroid()const{
				pType ans;
				for( int i=0, j=size()-1; i<size(); j=i++ ){
					ans += ( (vertex(i)+vertex(j))*cross(vertex(i),vertex(j)) );
				}
				ans /= (3*signedArea());
				return ans;
			}
			#define MAKE_FUNCTION(OP) \
				TYPE3o bool operator OP( const polygon<oType,oType2,oType3>& p )const{ \
					return v OP p.v;\
				}
			MAKE_FUNCTION(==) MAKE_FUNCTION(!=) MAKE_FUNCTION(<)
			MAKE_FUNCTION(<=) MAKE_FUNCTION(>) MAKE_FUNCTION(>=)
	};
	
	TYPE2 class triangle: public polygon<Type,pType>{
		public:
			typedef Type value_type;
			typedef pType point_type;
			typedef typename polygon<Type,pType>::arrange_cw arrange_cw;
			typedef typename polygon<Type,pType>::arrange_ccw arrange_ccw;
			pType A, B, C;
		#undef NORMALIZE
		#ifdef complex_triangle
		private:
			Type alen, blen, clen;
			Type al, be, ga;
		public:
			Type a()const{ return alen; }
			Type b()const{ return blen; }
			Type c()const{ return clen; }
		private:
			Type a2()const{ return alen*alen; }
			Type b2()const{ return blen*blen; }
			Type c2()const{ return clen*clen; }
		public:
			Type alpha()const{ return al; }
			Type beta()const{ return be; }
			Type gamma()const{ return ga; }
			void normalize(){
				alen = dist(B,C);
				blen = dist(A,C);
				clen = dist(A,B);
				al = acos( (b2()+c2()-a2()) / (2*b()*c()) );
				be = acos( (c2()+a2()-b2()) / (2*c()*a()) );
				ga = acos( (a2()+b2()-c2()) / (2*a()*b()) );
			}
			#define NORMALIZE normalize();
		#else
		public:
			Type a()const{ return dist(B,C); }
			Type b()const{ return dist(A,C); }
			Type c()const{ return dist(A,B); }
		private:
			Type a2()const{ return dist2(B,C); }
			Type b2()const{ return dist2(A,C); }
			Type c2()const{ return dist2(A,B); }
		public:
			Type alpha()const{ return acos( (b2()+c2()-a2()) / (2*b()*c()) ); }
			Type beta()const{ return acos( (c2()+a2()-b2()) / (2*c()*a()) ); }
			Type gamma()const{ return acos( (a2()+b2()-c2()) / (2*a()*b()) ); }
			#define NORMALIZE
		#endif
		public:
			size_t size()const{ return 3; }
			bool empty()const{ return false; }
			triangle(): A(), B(), C() {NORMALIZE}
			TYPEo triangle( const oType& p ): A(p[0]), B(p[1]), C(p[2]) {NORMALIZE}
			triangle( const pType& pa, const pType& pb, const pType& pc ): A(pa), B(pb), C(pc) {NORMALIZE}
			//2d triangle special
			#undef T
			#define T const typename pType::value_type&
			triangle( T ax, T ay, T bx, T by, T cx, T cy ): A(ax,ay), B(bx,by), C(cx,cy) {NORMALIZE}
			#undef T
			#undef NORMALIZE
			
			pType& operator[]( size_t _ ){ return *(&A+_); }
			pType operator[]( size_t _ )const{ return *(&A+_); }
			pType& vertex( size_t _ ){ return *(&A+_); }
			pType vertex( size_t _ )const{ return *(&A+_); }
			pType& at( size_t _ ){ if(_>=this->size()) throw std::out_of_range("triangle::at( pos )"); return this->operator[](_); }
			pType at( size_t _ )const{ if(_>=this->size()) throw std::out_of_range("triangle::at( pos )"); return this->operator[](_); }
			
			TYPEo void sort( wise_t Wise = counterclockwise ){
				std::swap(vertex(0),*std::min_element( (pType*)&vertex(0), (pType*)&vertex(3) ));
				if(Wise==clockwise){
					if( arrange_cw(vertex(0))(vertex(2),vertex(1)) )
						std::swap( vertex(1), vertex(2) );
				}
				else{
					if( arrange_ccw(vertex(0))(vertex(2),vertex(1)) )
						std::swap( vertex(1), vertex(2) );
				}
			}
			void GrahamScan( wise_t Wise = counterclockwise ){ throw std::logic_error("geom::triangle has fixed size, cannot perform Graham Scan.\n           Suggested Alternative/s: geom::polygon"); }
			#undef MAKE_FUNCTION
			#define MAKE_FUNCTION(N) \
				void N( wise_t Wise = counterclockwise ){ this->GrahamScan(); }
			MAKE_FUNCTION(GrahamScanCollinear)
			MAKE_FUNCTION(GrahamScanCollinearUnique)
			
			Type inradius()const{ return geom::math::abs( this->signedArea() )/this->perimeter(); }
			Type circumradius()const{ return a()*b()*c()/(2*geom::math::abs( this->signedArea() ) ); }
			
			pType bary( const Type& ba, const Type& bb, const Type& bc )const{ return ( A*ba + B*bb + C*bc )/(ba+bb+bc); }
			
			
			pType brocard1()const{ return bary(a()*c()/b(),b()*a()/c(),c()*b()/a()); }
			pType brocard2()const{ return bary(a()*b()/c(),b()*c()/a(),c()*a()/b()); }
			pType incenter()const{ return bary(a(),b(),c()); }
			pType circumcenter()const{ return bary( a2()*(b2()+c2()-a2()), b2()*(c2()+a2()-b2()), c2()*(a2()+b2()-c2()) ); }
			pType orthocenter()const{ return bary(tan(alpha()),tan(beta()),tan(gamma())); }
			pType excenterA()const{ return bary(-a(),b(),c()); }
			pType excenterB()const{ return bary(a(),-b(),c()); }
			pType excenterC()const{ return bary(a(),b(),-c()); }
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
			
			size_t size() const{ return 1; }
			
			Type radius()const{ return r; }
			Type diameter()const{ return r*2; }
			Type area()const{ return PI*r*r; }
			Type circumference()const{ return PI*diameter(); }
			Type arc_length()const{ return circumference(); }
			Type arc_length( const Type& theta )const{ return circumference()*theta/(2*PI); }
			Type chord_length( const Type& theta )const{ return sqrt( (r*r*2)*(1-cos(theta))); }
			Type sectorArea( const Type& theta )const{ return area()*theta/(2*PI); }
	};
	
}

#undef MAKE_STREAM1
#undef MAKE_STREAM2
#undef MAKE_STREAM3
#define MAKE_STREAM1(T,OP,T2,C) \
	TYPEo std::T& operator OP( std::T& s, C geom::T2<oType>& o )
#define MAKE_STREAM2(T,OP,T2,C) \
	TYPE2o std::T& operator OP( std::T& s, C geom::T2<oType,oType2>& o )
#define MAKE_STREAM3(T,OP,T2,C) \
	TYPE3o std::T& operator OP( std::T& s, C geom::T2<oType,oType2,oType3>& o )

MAKE_STREAM1(istream,>>,point,){ return s >> o.x >> o.y; }
MAKE_STREAM1(ostream,<<,point,const){ return s << o.x << ' ' << o.y; }

MAKE_STREAM2(istream,>>,line,){ return s >> o.A >> o.B; }
MAKE_STREAM2(istream,>>,circle,){ return s >> o.center >> o.r; }
MAKE_STREAM2(ostream,<<,line,const){ return s << o.A << ' ' << o.B; }
MAKE_STREAM2(ostream,<<,circle,const){ return s << o.center << ' ' << o.r; }

MAKE_STREAM3(istream,>>,polygon,){ for( int i=0; i<o.size(); ++i ) s >> o[i]; return s; }
MAKE_STREAM3(ostream,<<,polygon,const){ for( int i=0; i<o.size(); ++i ){ if(i) s << ' '; s << o[i]; } return s; }

#ifdef complex_triangle
MAKE_STREAM2(istream,>>,triangle,){ for( int i=0; i<o.size(); ++i ) s >> o[i]; o.normalize(); return s; }
#endif

#undef MAKE_STREAM1
#undef MAKE_STREAM2
#undef MAKE_STREAM3

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

typedef geom::point<double> Point;
typedef geom::line<double> Line;
typedef geom::segment<double> Segment;
typedef geom::polygon<double> Polygon;
typedef geom::triangle<double> Triangle;
typedef geom::circle<double> Circle;

#endif /* _INCLUDE_GEOM */
/** END Geom v2.5.3 **/
/** IsosceleS 2013 (c) **/
using namespace std;
using namespace geom;
Polygon rail;
Point m, ans;
int n, i;
double mn, d;
int main(){
	cout.precision(4);
	cout << fixed;
	while( cin >> m ){
		cin >> n;
		rail.resize(n+1);
		cin >> rail;
		ans = Point(0,1);
		mn = HUGE_VAL;
		for( i=1; i<=n; ++i ){
			Segment s( rail[i-1], rail[i] );
			Point p2 = s.nearestPoint(m);
			d = dist(p2,m);
			if( d < mn ){
				mn = d;
				ans = p2;
			}
		}
		cout << ans.x << endl << ans.y << endl;
	}
}
