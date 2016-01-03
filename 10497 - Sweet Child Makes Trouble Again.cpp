/**
	UVa 10497 - Sweet Child Makes Trouble Again
	by Rico Tiongson
	Submitted: September 14, 2013
	Accepted 0.098s C++
	O(n) pregen + O(1) time
*/
#ifndef _INCLUDE_BIGINT
#define _INCLUDE_BIGINT 1
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
using namespace std;
#ifndef B_inline
#define B_inline inline
#endif
#define BIGINT_cTYPE int
#define BIGINT_CONTAINER deque<BIGINT_cTYPE>
#define B_FOR for( int i(0); i<size(); ++i )
#define B_rFOR for( int i(size()-1); i>=0; --i )
// #define BIGINT_EXCEPTION

static const char* _base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

//for exception handling
#ifdef BIGINT_EXCEPTION
	class BigInt_Exception{
		int id;
		string kind, desc, func;
		public:
			BigInt_Exception():id(0), desc("DEFAULT EXCEPTION"), func("NONE"){what();}
			BigInt_Exception(int ID,const char* KIND,const char* DESC,const char* FUNC):id(ID),kind(KIND),desc(DESC),func(FUNC){what();}
			void what()const{
				cerr << "     __________________________________________________________________      " << endl;
				cerr << "    #                                                                          " << endl;
				cerr << "    #  BigInt exception #" << id << " occured :: " << kind <<  endl;
				cerr << "    #  " << endl;
				cerr << "    #  Description: ";
				cerr << left << desc  << endl << "    #  " << endl;
				cerr << "    #  handled when method \"" << func << "\" was called." << endl;
				cerr <<  "    #                                                                          " << endl;
				cerr <<  "    #_________________________________________________________________         " << endl;
				cerr << endl;
				cerr <<  "Program has been forcibly terminated ----- @Exception handling by rico B-)" << endl;
				cerr <<  "                                                                            " << endl;
				cerr <<  "                                                                            " << endl;
				// throw BigInt_Exception();
			}
	};
#endif 
class BigInt;
B_inline istream& operator>>( istream&, BigInt& );
B_inline ostream& operator<<( ostream&, const BigInt& );
class BigInt{
	
	BIGINT_CONTAINER v;
	#ifdef BIGINT_PUBLIC
	public:
	#endif
	B_inline int BASE_CASE( char c )const{
		int gotBase = c<'A' ? c-'0' : ( c<'a' ? c-'A'+10 : c-'a' + 10 ); 
		#ifdef BIGINT_EXCEPTION
			if( gotBase>=BASE ) throw BigInt_Exception(2,"InvalidBase Exception","Trying to assign Base greater than expected","BigInt::push_left( int )");
		#endif
		return gotBase;
	}
	
	template<class Type> B_inline BigInt& INTEGRAL_ASSIGN( Type _ ){
		clear();
		if( _ < 0 ){
			signbit = true;
			_ = -_;
		}
		while( _ ){
			push_left( _%BASE );
			_ /= BASE;
		}
		return *this;
	}

	template<class Comparator> B_inline bool T_COMPARE( const BigInt& _, Comparator cmp, bool whenEqual )const{
		B_rFOR if( get(i)!=_.get(i) ){
			return signbit ? cmp( _.get(i), get(i) ) : cmp( get(i), _.get(i) );
		}
		return whenEqual;
	}
	
	B_inline bool U_COMPARE( const BigInt& _ )const{
		if( size() == _.size() ) return T_COMPARE( _, less<int>(), false );
		return size() < _.size();
	}
	
	B_inline bool S_COMPARE( const BigInt& _ )const{
		if( signbit != _.signbit ) return signbit;
		if( signbit ) return !U_COMPARE( _ );
		return U_COMPARE( _ );
	}
	B_inline BigInt& ACCUMULATE( const BigInt& _ ){
		push_left( 0, _.size()-size() );
		for( int i=0; i<_.size(); ++i ) v[i] += _.get(i);
		return *this;
	}
	B_inline BigInt& ACCUMULATE( const BigInt& _, int off ){
		push_left( 0, (_.size()+off)-size() );
		for( int i=0; i<_.size(); ++i ) v[i+off] += _.get(i);
		return *this;
	}
	B_inline BigInt& DECCUMULATE( const BigInt& _ ){
		bool u = U_COMPARE( _ );
		if( _.size() > size() ) push_left( 0, _.size()-size() );
		for( int i=0; i<_.size(); ++i ) v[i] -= _.get(i);
		if(u){
			signbit = !signbit;
			B_FOR v[i] = -v[i];
		}
		return *this;
	}
	
	B_inline BigInt& CARRY(){
		int hold(0);
		B_FOR{
			v[i]+=hold;
			hold = v[i]/BASE;
			v[i]%=BASE;
		}
		while(hold){
			push_left(hold%BASE);
			hold/=BASE;
		}
		return *this;
	}
	
	B_inline BigInt& UNCARRY(){
		int hold(0);
		B_FOR{
			v[i] -= hold;
			hold = 0;
			while(v[i]<0){
				v[i] += BASE;
				++hold;
			}
		}
		return *this;
	}
	template<class Type> B_inline pair<BigInt,Type> NUMBER_DIV( Type _ )const{
		#ifdef BIGINT_EXCEPTION
			if(!_)
			throw BigInt_Exception(1,"Arithmetic Exception","Division by Zero","private : BigInt::NUMBER_DIV( Type )");
		#endif 
		BigInt ans;
		ans.BASE = BASE;
		ans.signbit = (signbit!=(_<0));
		Type hold=0;
		int k;
		B_rFOR{
			hold*=BASE;
			hold+=get(i);
			k = hold/_;
			ans.push_right(k);
			hold-=_*k;
		}
		ans.trim_left();
		return pair<BigInt,Type>( ans, hold );
	}
	
	template<class Type> B_inline BigInt NUMBER_DIVISION( Type _ )const{
		#ifdef BIGINT_EXCEPTION
			if(!_)
			throw BigInt_Exception(1,"Arithmetic Exception","Division by Zero","private : BigInt::NUMBER_DIVISION( Type )");
		#endif 
		BigInt ans;
		ans.signbit = (signbit!=(_<0));
		ans.BASE = BASE;
		Type hold=0;
		int k;
		B_rFOR{
			hold*=BASE;
			hold+=get(i);
			k = hold/_;
			ans.push_right(k);
			hold-=_*k;
		}
		ans.trim_left();
		return ans;
	}
	
	template<class Type> B_inline Type NUMBER_MOD( Type _ )const{
		#ifdef BIGINT_EXCEPTION
			if(!_)
			throw BigInt_Exception(1,"Arithmetic Exception","Modulo by Zero","private : BigInt::NUMBER_MOD( Type )");
		#endif 
		// BigInt ans;
		// ans.signbit = (signbit!=(_<0));
		// ans.BASE = BASE;
		Type hold(0);
		int k;
		B_rFOR{
			hold*=BASE;
			hold+=get(i);
			k = hold/_;
			// ans.push_right(k);
			hold-=_*k;
		}
		return hold;
	}
	
	template<class Type> B_inline BigInt DIGIT_MULT( Type _ )const{
		// if(!*this) return BigInt();
		if(!_) return BigInt();
		BigInt ans;
		ans.BASE = BASE;
		if(_<0){
			_=-_;
			ans.signbit = !signbit;
		}
		else ans.signbit = signbit;
		if(_!=1){
			int hold=0;
			B_FOR{
				hold += _*get(i);
				ans.push_left(hold%BASE);
				hold/=BASE;
			}
			if(hold) ans.push_left(hold);
		}
		else ans.v = v;
		return ans;
	}
	
	#ifndef BIGINT_PUBLIC
	public:
	#endif
		static int use_base;
		
		bool signbit;
		int BASE;
	//methods
		
		B_inline BigInt& assign( const BigInt& _ ){
			v = _.v;
			signbit = _.signbit;
			if( BASE != _.BASE ) toBase( BASE );
			return *this;
		}
		
		B_inline BigInt& assign( const string& _ ){
			clear();
			if( !_.empty() ){
				int i(0);
				if( _[i]=='-' ){
					++i;
					signbit = true;
				}
				for( ; i<_.size(); ++i ) push_right( BASE_CASE( _[i] ) );
				trim_left();
				if(empty()) signbit = false;
			}
			return *this;
		}
		
		B_inline BigInt& assign( const char* _ ){
			clear();
			int i(0);
			if( _[i]=='-' ){
				++i;
				signbit = true;
			}
			for( ; _[i]!='\0'; ++i ) push_right( BASE_CASE( _[i] ) );
			trim_left();
			if(empty()) signbit = false;
			return *this;
		}
		
		B_inline BigInt& assign( const char& _ ){
			clear();
			push_left( BASE_CASE( _ ) );
			return *this;
		}
		
		B_inline BigInt& assign( int _ ){ return INTEGRAL_ASSIGN(  _ ); }
		B_inline BigInt& assign( short _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( long _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( long long _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( unsigned _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( unsigned short _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( unsigned long _ ){ return INTEGRAL_ASSIGN( _ ); }
		B_inline BigInt& assign( unsigned long long _ ){ return INTEGRAL_ASSIGN( _ ); }
		
		template<class Type> B_inline BigInt& assign( const Type& _, int b ){
			if( BASE==b ) return assign( _ );
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::assign( Type, int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::assign( Type, int )");
			#endif 
			swap( BASE, b );
			return assign( _ ).toBase( b );
		}

		B_inline void clear(){
			v.clear();
			signbit = false;
		}
		
		B_inline BigInt& push_left( int _ ){
			// #ifdef BIGINT_EXCEPTION
				// if( _>=BASE ) throw BigInt_Exception(2,"InvalidBase Exception","Trying to assign Base greater than expected","BigInt::push_left( int )");
			// #endif
			v.push_back( _ );
			return *this;
		}
		
		B_inline BigInt& push_left( int _, int pad ){ while( pad>0 ){ push_left( _ ); --pad; } return *this; }
		
		B_inline BigInt& push_right( int _ ){
			// #ifdef BIGINT_EXCEPTION
				// if( _>=BASE ) throw BigInt_Exception(2,"InvalidBase Exception","Trying to assign Base greater than expected","BigInt::push_right( int )");
			// #endif
			v.push_front( _ );
			return *this;
		}
		
		B_inline BigInt& push_right( int _, int pad ){ while( pad>0 ){ push_right( _ ); --pad; } return *this; }
		
		B_inline BigInt& pop_left(){ v.pop_back(); return *this; }
		
		B_inline BigInt& pop_left( int pad ){ while( !empty() && pad>0 ){ pop_left(); --pad; } return *this; }
		
		B_inline BigInt& pop_right(){ v.pop_front(); return *this; }
		
		B_inline BigInt& pop_right( int pad ){ while( !empty() && pad>0 ){ pop_right(); --pad; } return *this; }
		
		B_inline BigInt& trim( int _=0 ){ return trim_left( _ ).trim_right( _ ); }
		
		B_inline BigInt& trim_left( int _=0 ){ while( !empty() && left()==_ ) pop_left(); return *this; }
		
		B_inline BigInt& trim_right( int _=0 ){ while( !empty() && right()==_ ) pop_right(); return *this; }
		
	//constr
	
		B_inline BigInt(): BASE(use_base) {
			#ifdef BIGINT_EXCEPTION
				if( use_base < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","static BigInt::use_base");
				else if( use_base >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","static BigInt::use_base");
			#endif 
			clear();
		}
	
		template<class Type> B_inline BigInt( const Type& _ ): BASE(use_base) { assign( _ ); }
		template<class Type> B_inline BigInt( const Type& _, int b ):BASE(use_base) { assign( _, b ); }
		
	//convert
	
		B_inline BigInt base( int b )const{
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::base( int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::base( int )");
			#endif 
			BigInt Copy = *this;
			return Copy.toBase( b );
		}
		
		B_inline BigInt operator()( int b )const{ return base( b ); }
		B_inline BigInt& toBase( int b ){
			if( b==BASE ) return *this;
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::toBase( int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::toBase( int )");
			#endif 
			BigInt ans;
			ans.BASE = b;
			ans.signbit = signbit;
			pair<BigInt,int> DIV;
			while(!empty()){
				DIV = NUMBER_DIV( b );
				*this = DIV.first;
				ans.push_left( DIV.second );
			}
			return *this = ans;
		}
		
		template<class Type> B_inline vector<Type> to_vector(){ return vector<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> B_inline list<Type> to_list(){ return list<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> B_inline deque<Type> to_deque(){ return deque<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> B_inline Type u_to()const{
			Type ans = 0;
			B_rFOR{
				ans *= BASE;
				ans += get(i);
			}
			return ans;
		}
		
		template<class Type> B_inline Type u_to( int b )const{ return b==BASE ? u_to<Type>() : base( b ).u_to<Type>; }
		
		template<class Type> B_inline Type to()const{
			if(signbit) return -u_to<Type>();
			return u_to<Type>();
		}
		
		template<class Type> B_inline Type to( int b )const{ return b==BASE ? to<Type>() : base( b ).to<Type>(); }
		
		B_inline operator bool()const{ return !empty(); }
		B_inline operator char()const;
		B_inline operator short()const{ return to<short>(); }
		B_inline operator int()const{ return to<int>(); }
		B_inline operator long()const{ return to<long>(); }
		B_inline operator long long()const{ return to<long long>(); }
		B_inline operator unsigned short()const{ return u_to<unsigned short>(); }
		B_inline operator unsigned()const{ return u_to<unsigned>(); }
		B_inline operator unsigned long()const{ return u_to<unsigned long>(); }
		B_inline operator unsigned long long()const{ return u_to<unsigned long long>(); }
		B_inline operator string()const;
		
	//accessors
	
		B_inline BIGINT_CONTAINER& access(){ return v; }
		
		B_inline int& base(){ return BASE; }
		B_inline int base()const{ return BASE; }
		
		B_inline bool& sign(){ return signbit; }
		B_inline bool sign()const{ return signbit; }
		
		B_inline int size()const{ return v.size(); }
		
		B_inline int length()const{ return v.size(); }
		
		B_inline bool empty()const{ return v.empty(); }
		
		B_inline BIGINT_cTYPE get( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::get( int )");
			#endif 
			return v[_];
		}//from ones digit
		B_inline BIGINT_cTYPE& get( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::get( int )");
			#endif 
			return v[_];
		}
		
		B_inline BIGINT_cTYPE digit( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::digit( int )");
			#endif 
			return v[ size()-_-1 ];
		} //from most significant digit
		B_inline BIGINT_cTYPE& digit( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::digit( int )");
			#endif 
			return v[ size()-_-1 ];
		}
		
		B_inline BIGINT_cTYPE& left(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::left( )");
			#endif 
			return v.back();
		}
		
		B_inline BIGINT_cTYPE& right(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::right( )");
			#endif 
			return v.front();
		}
		
		B_inline BIGINT_cTYPE& operator[]( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::operator[] ( int )");
			#endif 
			return v[_];
		}
		B_inline BIGINT_cTYPE operator[]( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::operator[] ( int )");
			#endif 
			return v[_];
		}
		B_inline BigInt operator-()const{
			BigInt Copy = *this;
			Copy.signbit = !signbit;
			return Copy;
		}
		
		B_inline BigInt& operator+=( const BigInt& _ ){
			if( signbit != _.signbit ){
				signbit = !signbit;
				operator-=( _ );
				signbit = !signbit;
			}
			else ACCUMULATE( _ ).CARRY().trim_left();
			return *this;
		}
		
		B_inline BigInt& operator++(){
			if(empty()){
				signbit = false;
				push_left(1);
				return *this;
			}
			if(signbit){
				for(int i=0;i<size();++i){
					if(--v[i]==-1) v[i] = BASE-1;
					else return trim_left();
				}
			}
			else{
				for(int i=0;i<size();++i){
					if(++v[i]==BASE) v[i]=0;
					else return *this;
				}
				push_left(1);
			}
			return *this;
		}
		B_inline BigInt& operator++( int _ ){ return operator++(); } //ignore post
		
		template<class Type> B_inline BigInt operator+( const Type& _ )const{ return (BigInt(*this)+=_); }
		
		B_inline BigInt& operator-=( const BigInt& _ ){
			if( signbit != _.signbit ){
				signbit = !signbit;
				operator+=( _ );
				signbit = !signbit;
			}
			else DECCUMULATE( _ ).UNCARRY().trim_left();
			return *this;
		}
		
		B_inline BigInt& operator--(){
			signbit = !signbit;
			operator++();
			if(!empty())
				signbit = !signbit;
			return *this;
		}
		B_inline BigInt& operator--( int _ ){ return operator--(); } //ignore post
		
		template<class Type> B_inline BigInt operator-( const Type& _ )const{ return (BigInt(*this)-=_); }
		
		template<class Type> B_inline BigInt& operator*=( const Type& _ ){ return *this = operator*( _ ); }
		
		B_inline BigInt operator*( const BigInt& _ )const{
			if(BASE!=_.BASE) return operator*(_.base(BASE));
			BigInt ans;
			ans.BASE = BASE;
			B_FOR ans.ACCUMULATE( _.DIGIT_MULT(get(i)), i );
			ans.CARRY();
			ans.signbit = (signbit!=_.signbit);
			return ans;
		}
		
		B_inline BigInt operator*( int _ )const{
			return DIGIT_MULT(_).CARRY();
		}
		
		template<class Type> B_inline pair<BigInt, Type> div( const Type& _ )const{ return NUMBER_DIV( _ ); }
		
		B_inline pair<BigInt,BigInt> div( const BigInt& _ )const{
			#ifdef BIGINT_EXCEPTION
				if(!_) throw BigInt_Exception(1,"Arithmetic Exception","Division by Zero","BigInt::div( const BigInt& )");
			#endif 
			if(empty()) return pair<BigInt,BigInt>(*this,*this);
			if(_.size()<16) return NUMBER_DIV( _.to<long long>());
			if(BASE!=_.BASE) return div(_.base(BASE));
			if( U_COMPARE(_) ){
				BigInt ans;
				ans.BASE = BASE;
				return pair<BigInt,BigInt>(ans,signbit!=_.signbit?-*this:*this);
			}
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(int i=_.size()-4;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_rFOR{
				hold.push_right( get(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( int j=_.size()-4;j<hold.size();++j ){
						HOLDER*=hold.BASE;
						HOLDER+=hold.get(j);
					}
					val = HOLDER/SMALL;
					// cerr << endl << ans << endl;
					temp = _*(val);
					while( temp<=hold ){
						temp+=_;
						++val;
					}
					ans.push_right( val-1 );
					hold-=(temp-=_);
				}
			}
			ans.trim_left();
			if(!ans.empty())
				ans.signbit = (signbit!=_.signbit);
			if(hold.empty()) hold.signbit = false;
			else hold.signbit = (signbit!=_.signbit);
			return pair<BigInt,BigInt>(ans,hold);
		}
		
		B_inline pair<BigInt,BigInt> div( const string& _ )const{ return div(BigInt(_)); }
		B_inline pair<BigInt,BigInt> div( const char* _ )const{ return div(BigInt(_)); }
		B_inline BigInt operator/( const BigInt& _ )const{
			#ifdef BIGINT_EXCEPTION
				if(!_) throw BigInt_Exception(1,"Arithmetic Exception","Division by Zero","BigInt::operator/( const BigInt& )");
			#endif 
			if(empty()) return *this;
			if(_.size()<16) return NUMBER_DIVISION(_.to<long long>());
			if(BASE!=_.BASE) return operator/(_.base(BASE));
			if( U_COMPARE(_) ){
				BigInt ans;
				ans.BASE = BASE;
				return ans;
			}
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(int i=_.size()-4u;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_rFOR{
				hold.push_right( get(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( int j=_.size()-4u;j<hold.size();++j ){
						HOLDER*=hold.BASE;
						HOLDER+=hold.get(j);
					}
					val = HOLDER/SMALL;
					// cerr << endl << ans << endl;
					temp = _*(val);
					while( temp<=hold ){
						temp+=_;
						++val;
					}
					ans.push_right( val-1 );
					hold-=(temp-=_);
				}
			}
			ans.trim_left();
			if(!ans.empty())
				ans.signbit = (signbit!=_.signbit);
			return ans;
		}
		B_inline BigInt operator/( const string& _ )const{ return operator/(BigInt(_)); }
		B_inline BigInt operator/( const char* _ )const{ return operator/(BigInt(_)); }
		template<class Type> B_inline BigInt operator/( const Type& _ )const{  return NUMBER_DIVISION((long long)_); }
		template<class Type> B_inline BigInt& operator/=( const Type& _ ){ return *this = operator/(_); }
		B_inline BigInt operator%( const BigInt& _ )const{
			#ifdef BIGINT_EXCEPTION
				if(!_) throw BigInt_Exception(1,"Arithmetic Exception","Modulo by Zero","BigInt::operator%( const BigInt& )");
			#endif 
			if(empty()) return *this;
			if(_.size()<16) return NUMBER_MOD(_.to<long long>());
			if(BASE!=_.BASE) return operator%(_.base(BASE));
			if( U_COMPARE( _ ) ) return signbit!=_.signbit?-*this:*this;
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(int i=_.size()-4u;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_rFOR{
				hold.push_right( get(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( int j=_.size()-4u;j<hold.size();++j ){
						HOLDER*=hold.BASE;
						HOLDER+=hold.get(j);
					}
					val = HOLDER/SMALL;
					temp = _*(val);
					while(temp<=hold){
						temp+=_;
						++val;
					}
					ans.push_right( val-1 );
					hold-=(temp-=_);
				}
			}
			if(hold.empty()) hold.signbit = false;
			else hold.signbit = (signbit!=_.signbit);
			return hold;
		}
		
		B_inline BigInt operator%( const string& _ )const{ return operator%(BigInt(_)); }
		B_inline BigInt operator%( const char* _ )const{ return operator%(BigInt(_)); }
		template<class Type> B_inline BigInt operator%( const Type& _ )const{  return NUMBER_MOD((long long)_); }
		template<class Type> B_inline BigInt& operator%=( const Type& _ ){ return *this = operator%(_); }
		B_inline bool operator<( const BigInt& _ )const{
			if( BASE != _.BASE ) return operator<(_.base(BASE));
			return S_COMPARE( _ );
		}
		template<class Type> B_inline bool operator<( const Type& _ )const{ return operator<(BigInt(_)); }
		B_inline bool operator<=( const BigInt& _ )const{
			if( signbit != _.signbit ) return signbit;
			if( BASE != _.BASE ) return operator<=(_.base(BASE));
			if( size() == _.size() ) return T_COMPARE( _, less<int>(), true );
			if( signbit ) return size() > _.size();
			return size() < _.size();
		}
		template<class Type> B_inline bool operator<=( const Type& _ )const{ return operator<=(BigInt(_)); }
		template<class Type> B_inline bool operator>( const Type& _ )const{ return !operator<=(_); }
		template<class Type> B_inline bool operator>=( const Type& _ ) const{ return !operator<(_); }
		B_inline bool operator==( const BigInt& _ )const{ return signbit==_.signbit && BASE==_.BASE && v==_.v; }
		template<class Type> B_inline bool operator==( const Type& _ )const{ return operator==(BigInt(_)); }
		template<class Type> B_inline bool operator!=( const Type& _ )const{ return !(operator==(_)); }
		B_inline bool operator!()const{ return empty(); }
		B_inline BigInt operator^( int _ )const{
			BigInt ans(1);
			if(!_) return ans;
			BigInt POW(*this);
			while( _ ){
				if(_&1) ans *= POW;
				if( _>>=1 ) POW *= POW;
			}
			return ans;
		}
		B_inline BigInt& operator^=( int _ ){ return *this = operator^(_); }
		B_inline BigInt& operator=( const BigInt& _ ){
			v = _.v;
			signbit = _.signbit;
			BASE = _.BASE;
			return *this;
		}
};
template<> B_inline string BigInt::to<string>()const{
	if(empty()) return "0";
	static string BigInt_buffer;
	BigInt_buffer.clear();
	if(signbit) BigInt_buffer.push_back('-');
	B_rFOR BigInt_buffer.push_back( _base[get(i)] );
	return BigInt_buffer;
}
template<> B_inline char* BigInt::to<char*>()const{
	char* c = new char[size()+2];
	char *p = c;
	if(empty()){
		c[0] = '0';
		c[1] = '\0';
		return c;
	}
	p=c;
	if(signbit){
		*p= '-';
		++p;
	}
	B_rFOR{
		*p = get(i)+'0';
		p++;
	}
	*p = '\0';
	return c;
}
template<> B_inline char BigInt::to<char>()const{ if(empty()) return '0'; return _base[get(0)]; }
B_inline BigInt::operator char()const{ return to<char>(); }
BigInt::operator string()const{ return to<string>(); }
B_inline istream& operator>>( istream& in, BigInt& _ ){
	static string BigInt_buffer;
	in >> BigInt_buffer;
	_.assign(BigInt_buffer,BigInt::use_base);
	return in;
}
B_inline ostream& operator<<( ostream& out, const BigInt& _ ){ return out << _.to<string>(BigInt::use_base); }
int BigInt::use_base = 10;
#undef BIGINT_CONTAINER
#undef BIGINT_cTYPE
#undef B_FOR
#undef B_rFOR
#undef B_inline
#endif /* _INCLUDE_BIGINT */
/** END BigInt v1.4 **/
/** IsosceleS 2013(c) **/
using namespace std;
BigInt f[801];
int i;
int main(){
	f[2] = 1;
	for( i=3; i<801; ++i ){
		f[i] = (f[i-1]+f[i-2])*(i-1);
	}
	while( cin >> i, ~i ){
		cout << f[i] << endl;
	}
}
