/**
	UVa 10229 - Modular Fibonacci
	by Rico Tiongson
	Submitted: September 19, 2013
	Accepted 0.015s C++
	O(logn) time
*/
#include<iostream>
/** START matrix v1.0 **/
/** IsosceleS 2013 (c) **/
#ifndef _INCLUDE_MATRIX
#define _INCLUDE_MATRIX 1

#include<iostream>
#include<stdexcept>
#include<algorithm>

/// forward

#undef TEMP1
#undef TEMP2
#define TEMP1 int P, int Q, class Type
#define TEMP2 int P2, int Q2, class Type2

template<TEMP1=int> class matrix;

template<TEMP1>
std::istream& operator>>( std::istream&, const matrix<P,Q,Type>& );
template<TEMP1>
std::ostream& operator<<( std::ostream&, const matrix<P,Q,Type>& );

int matrix_mod;
/// backward

template<TEMP1>
class matrix{

	private:
	
		Type a[P][Q];
		
	public:
	
		/// accessors
		
		inline operator Type*()const{ return static_cast<Type*>( (Type*)a ); }
		
		inline Type*
			operator[]( int i )const{ return static_cast<Type*>( (Type*)a[i] ); }
		
		inline int
			height()const{ return P; }
		
		inline int
			width()const{ return Q; }
		
		/// constructors
		
		matrix() { std::fill( a[0], a[P-1]+Q, Type() ); }
		
		matrix( const Type x[P][Q] ){ std::copy( x[0], x[P-1]+Q, a[0] ); }
		
		matrix( const matrix<P,Q,Type>& x ){ std::copy( x[0], x[P-1]+Q, a[0] ); }
		
		/// arithmetic
		
		template<int R> matrix<P,R,Type>
			operator*( const matrix<Q,R,Type>& x ) const{
				matrix<P,R,Type> ans;
				int i, j, k;
				for( i=0; i<P; ++i )
					for( j=0; j<R; ++j )
						for( k=0; k<Q; ++k ){
							// #ifndef matrix_mod
							// ans[i][j] += a[i][k]*x[k][j];
							// #else
							ans[i][j] = ( ans[i][j] + a[i][k]*x[k][j] )&(matrix_mod);
							// #endif /* matrix_mod */
						}
				return ans;
			}
		
		template<int R> matrix<P,R,Type>&
			operator*=( const matrix<R,Q,Type>& x ){
				*this = (*this)*(x);
				return *this;
			}
			
		template<int R> inline matrix<P,R,Type>
			multiply( const matrix<R,Q,Type>& x )const{
				return (*this)*(x);
			}
		
		matrix<P,Q,Type>
			pow( long long expo ) const{
				using namespace std;
				if( P!=Q ) throw std::logic_error( "matrix should be square" );
				matrix<P,Q,Type> ans;
				
				for( int i=0; i<P; ++i ) ans[i][i] = 1;
				// cout << "HERE" << endl;
				
				matrix<P,Q,Type> bas( *this );
				while( expo ){
					if( expo&1 )
						ans = ans*bas;
					bas = bas*bas;
					expo >>= 1;
				}
				return ans;
			}
			
		/// relational
		template<TEMP2> inline int
			compare( const matrix<P2,Q2,Type2>& m )const{
				int cmp = P - P2;
				if(!cmp){
					cmp = Q - Q2;
					if(!cmp){
						int i, j;
						for( i=0; i<P; ++i )
							for( j=0; j<Q; ++j )
								if( a[i][j] != m[i][j] )
									return a[i][j] - m[i][j];						
					}
				}
				return cmp;
			}
		#undef make_operator
		#define make_operator(O) \
			template<TEMP2> inline bool \
				operator O ( const matrix<P2,Q2,Type2>& m )const{ \
					return this->compare(m) O 0; \
				}
		make_operator(<);
		make_operator(<=);
		make_operator(>);
		make_operator(>=);
		make_operator(==);
		make_operator(!=);
		#undef make_operator
		
};

template<int P, int Q, class Type>
std::istream& operator>>( std::istream& in, const matrix<P,Q,Type>& m ){
	int i, j;
	for( i=0; i<P; ++i )
		for( j=0; j<Q; ++j )
			in >> m[i][j];
	return in;
}

template<int P, int Q, class Type>
std::ostream& operator<<( std::ostream& out, const matrix<P,Q,Type>& m ){
	int i, j;
	for( i=0; i<P; ++i ){
		out << "[ ";
		for( j=0; j<Q; ++j ){
			if(j) out << ", ";
			out << m[i][j];
		}
		out << "]\n";
	}
	return out;
}

#endif /* _INCLUDE_MATRIX */
/** END matrix v1.0 **/
/** IsosceleS 2013 (c) **/
using namespace std;
int fib[2][2] = { 1, 1, 1, 0 };
int st[2][1] = { 1, 0 };
matrix<2,2> m1 = fib;
matrix<2,1> m2 = st;
int n, m;
int main(){
	while( cin >> n >> m ){
		matrix_mod = (1<<m)-1;
		cout << (m1.pow(n)*m2)[1][0] << endl;
	}
}
