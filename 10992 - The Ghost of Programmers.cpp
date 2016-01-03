/**
	UVa 10992 - The Ghost of Programmers
	by Rico Tiongson
	Submitted: July 31, 2013
	Accepted 0.019s C++
	O(8logn) time
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
istream& operator>>( istream&, BigInt& );
ostream& operator<<( ostream&, const BigInt& );
class BigInt{
	
	BIGINT_CONTAINER v;
	#ifdef BIGINT_PUBLIC
	public:
	#endif
	int BASE_CASE( char c )const{ return c<'A' ? c-'0' : ( c<'a' ? c-'A'+10 : c-'a' + 10 ); }
	
	template<class Type> BigInt& INTEGRAL_ASSIGN( Type _ ){
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

	template<class Comparator> bool T_COMPARE( const BigInt& _, Comparator cmp, bool whenEqual )const{
		B_rFOR if( get(i)!=_.get(i) ){
			return signbit ? cmp( _.get(i), get(i) ) : cmp( get(i), _.get(i) );
		}
		return whenEqual;
	}
	
	bool U_COMPARE( const BigInt& _ )const{
		if( size() == _.size() ) return T_COMPARE( _, less<int>(), false );
		return size() < _.size();
	}
	
	bool S_COMPARE( const BigInt& _ )const{
		if( signbit != _.signbit ) return signbit;
		if( signbit ) return !U_COMPARE( _ );
		return U_COMPARE( _ );
	}
	BigInt& ACCUMULATE( const BigInt& _ ){
		push_left( 0, _.size()-size() );
		for( int i=0; i<_.size(); ++i ) v[i] += _.get(i);
		return *this;
	}
	BigInt& ACCUMULATE( const BigInt& _, int off ){
		push_left( 0, (_.size()+off)-size() );
		for( int i=0; i<_.size(); ++i ) v[i+off] += _.get(i);
		return *this;
	}
	BigInt& DECCUMULATE( const BigInt& _ ){
		bool u = U_COMPARE( _ );
		if( _.size() > size() ) push_left( 0, _.size()-size() );
		for( int i=0; i<_.size(); ++i ) v[i] -= _.get(i);
		if(u){
			signbit = !signbit;
			B_FOR v[i] = -v[i];
		}
		return *this;
	}
	
	BigInt& CARRY(){
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
	
	BigInt& UNCARRY(){
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
	template<class Type> pair<BigInt,Type> NUMBER_DIV( Type _ )const{
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
	
	template<class Type> BigInt NUMBER_DIVISION( Type _ )const{
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
	
	template<class Type> Type NUMBER_MOD( Type _ )const{
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
	
	template<class Type> BigInt DIGIT_MULT( Type _ )const{
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
		
		BigInt& assign( const BigInt& _ ){
			v = _.v;
			signbit = _.signbit;
			if( BASE != _.BASE ) toBase( BASE );
			return *this;
		}
		
		BigInt& assign( const string& _ ){
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
		
		BigInt& assign( const char* _ ){
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
		
		BigInt& assign( const char& _ ){
			clear();
			push_left( BASE_CASE( _ ) );
			return *this;
		}
		
		BigInt& assign( int _ ){ return INTEGRAL_ASSIGN(  _ ); }
		BigInt& assign( short _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( long _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( long long _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( unsigned _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( unsigned short _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( unsigned long _ ){ return INTEGRAL_ASSIGN( _ ); }
		BigInt& assign( unsigned long long _ ){ return INTEGRAL_ASSIGN( _ ); }
		
		template<class Type> BigInt& assign( const Type& _, int b ){
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::assign( Type, int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::assign( Type, int )");
			#endif 
			int hold = BASE;
			BASE = b;
			return assign( _ ).toBase( hold );
		}

		void clear(){
			v.clear();
			signbit = false;
		}
		
		BigInt& push_left( int _ ){
			#ifdef BIGINT_EXCEPTION
				if( _>=BASE ) throw BigInt_Exception(2,"InvalidBase Exception","Trying to assign Base greater than expected","BigInt::push_left( int )");
			#endif
			v.push_back( _ );
			return *this;
		}
		
		BigInt& push_left( int _, int pad ){ while( pad>0 ){ push_left( _ ); --pad; } return *this; }
		
		BigInt& push_right( int _ ){
			#ifdef BIGINT_EXCEPTION
				if( _>=BASE ) throw BigInt_Exception(2,"InvalidBase Exception","Trying to assign Base greater than expected","BigInt::push_right( int )");
			#endif
			v.push_front( _ );
			return *this;
		}
		
		BigInt& push_right( int _, int pad ){ while( pad>0 ){ push_right( _ ); --pad; } return *this; }
		
		BigInt& pop_left(){ v.pop_back(); return *this; }
		
		BigInt& pop_left( int pad ){ while( !empty() && pad>0 ){ pop_left(); --pad; } return *this; }
		
		BigInt& pop_right(){ v.pop_front(); return *this; }
		
		BigInt& pop_right( int pad ){ while( !empty() && pad>0 ){ pop_right(); --pad; } return *this; }
		
		BigInt& trim( int _=0 ){ return trim_left( _ ).trim_right( _ ); }
		
		BigInt& trim_left( int _=0 ){ while( !empty() && left()==_ ) pop_left(); return *this; }
		
		BigInt& trim_right( int _=0 ){ while( !empty() && right()==_ ) pop_right(); return *this; }
		
	//constr
	
		BigInt(): BASE(use_base) {
			#ifdef BIGINT_EXCEPTION
				if( use_base < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","static BigInt::use_base");
				else if( use_base >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","static BigInt::use_base");
			#endif 
			clear();
		}
	
		template<class Type> BigInt( const Type& _ ): BASE(use_base) { assign( _ ); }
		template<class Type> BigInt( const Type& _, int b ):BASE(use_base) { assign( _, b ); }
		
	//convert
	
		BigInt base( int b )const{
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::base( int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::base( int )");
			#endif 
			BigInt Copy = *this;
			return Copy.toBase( b );
		}
		
		BigInt operator()( int b )const{ return base( b ); }
		BigInt& toBase( int b ){
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
		
		template<class Type> vector<Type> to_vector(){ return vector<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> list<Type> to_list(){ return list<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> deque<Type> to_deque(){ return deque<Type>( v.rbegin(), v.rend() ); }
		
		template<class Type> Type u_to()const{
			Type ans = 0;
			B_rFOR{
				ans *= BASE;
				ans += get(i);
			}
			return ans;
		}
		
		template<class Type> Type u_to( int b )const{ return base( b ).u_to<Type>(); }
		
		template<class Type> Type to()const{
			if(signbit) return -u_to<Type>();
			return u_to<Type>();
		}
		
		template<class Type> Type to( int b )const{ return base( b ).to<Type>(); }
		
		operator bool()const{ return !empty(); }
		operator char()const;
		operator short()const{ return to<short>(); }
		operator int()const{ return to<int>(); }
		operator long()const{ return to<long>(); }
		operator long long()const{ return to<long long>(); }
		operator unsigned short()const{ return u_to<unsigned short>(); }
		operator unsigned()const{ return u_to<unsigned>(); }
		operator unsigned long()const{ return u_to<unsigned long>(); }
		operator unsigned long long()const{ return u_to<unsigned long long>(); }
		operator string()const;
		
	//accessors
	
		BIGINT_CONTAINER& access(){ return v; }
		
		int& base(){ return BASE; }
		int base()const{ return BASE; }
		
		bool& sign(){ return signbit; }
		bool sign()const{ return signbit; }
		
		int size()const{ return v.size(); }
		
		int length()const{ return v.size(); }
		
		bool empty()const{ return v.empty(); }
		
		BIGINT_cTYPE get( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::get( int )");
			#endif 
			return v[_];
		}//from ones digit
		BIGINT_cTYPE& get( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::get( int )");
			#endif 
			return v[_];
		}
		
		BIGINT_cTYPE digit( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::digit( int )");
			#endif 
			return v[ size()-_-1 ];
		} //from most significant digit
		BIGINT_cTYPE& digit( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::digit( int )");
			#endif 
			return v[ size()-_-1 ];
		}
		
		BIGINT_cTYPE& left(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::left( )");
			#endif 
			return v.back();
		}
		
		BIGINT_cTYPE& right(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::right( )");
			#endif 
			return v.front();
		}
		
		BIGINT_cTYPE& operator[]( int _ ){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::operator[] ( int )");
			#endif 
			return v[_];
		}
		BIGINT_cTYPE operator[]( int _ )const{
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::operator[] ( int )");
			#endif 
			return v[_];
		}
		BigInt operator-()const{
			BigInt Copy = *this;
			Copy.signbit = !signbit;
			return Copy;
		}
		
		BigInt& operator+=( const BigInt& _ ){
			if( signbit != _.signbit ){
				signbit = !signbit;
				operator-=( _ );
				signbit = !signbit;
			}
			else ACCUMULATE( _ ).CARRY().trim_left();
			return *this;
		}
		
		BigInt& operator++(){
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
		BigInt& operator++( int _ ){ return operator++(); } //ignore post
		
		template<class Type> BigInt operator+( const Type& _ )const{ return (BigInt(*this)+=_); }
		
		BigInt& operator-=( const BigInt& _ ){
			if( signbit != _.signbit ){
				signbit = !signbit;
				operator+=( _ );
				signbit = !signbit;
			}
			else DECCUMULATE( _ ).UNCARRY().trim_left();
			return *this;
		}
		
		BigInt& operator--(){
			signbit = !signbit;
			operator++();
			if(!empty())
				signbit = !signbit;
			return *this;
		}
		BigInt& operator--( int _ ){ return operator--(); } //ignore post
		
		template<class Type> BigInt operator-( const Type& _ )const{ return (BigInt(*this)-=_); }
		
		template<class Type> BigInt& operator*=( const Type& _ ){ return *this = operator*( _ ); }
		
		BigInt operator*( const BigInt& _ )const{
			if(BASE!=_.BASE) return operator*(_.base(BASE));
			BigInt ans;
			ans.BASE = BASE;
			B_FOR ans.ACCUMULATE( _.DIGIT_MULT(get(i)), i );
			ans.CARRY();
			ans.signbit = (signbit!=_.signbit);
			return ans;
		}
		
		BigInt operator*( int _ )const{
			return DIGIT_MULT(_).CARRY();
		}
		
		template<class Type> pair<BigInt, Type> div( const Type& _ )const{ return NUMBER_DIV( _ ); }
		
		pair<BigInt,BigInt> div( const BigInt& _ )const{
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
		
		pair<BigInt,BigInt> div( const string& _ )const{ return div(BigInt(_)); }
		pair<BigInt,BigInt> div( const char* _ )const{ return div(BigInt(_)); }
		BigInt operator/( const BigInt& _ )const{
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
		BigInt operator/( const string& _ )const{ return operator/(BigInt(_)); }
		BigInt operator/( const char* _ )const{ return operator/(BigInt(_)); }
		template<class Type> BigInt operator/( const Type& _ )const{  return NUMBER_DIVISION((long long)_); }
		template<class Type> BigInt& operator/=( const Type& _ ){ return *this = operator/(_); }
		BigInt operator%( const BigInt& _ )const{
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
		
		BigInt operator%( const string& _ )const{ return operator%(BigInt(_)); }
		BigInt operator%( const char* _ )const{ return operator%(BigInt(_)); }
		template<class Type> BigInt operator%( const Type& _ )const{  return NUMBER_MOD((long long)_); }
		template<class Type> BigInt& operator%=( const Type& _ ){ return *this = operator%(_); }
		bool operator<( const BigInt& _ )const{
			if( BASE != _.BASE ) return operator<(_.base(BASE));
			return S_COMPARE( _ );
		}
		template<class Type> bool operator<( const Type& _ )const{ return operator<(BigInt(_)); }
		bool operator<=( const BigInt& _ )const{
			if( signbit != _.signbit ) return signbit;
			if( BASE != _.BASE ) return operator<=(_.base(BASE));
			if( size() == _.size() ) return T_COMPARE( _, less<int>(), true );
			if( signbit ) return size() > _.size();
			return size() < _.size();
		}
		template<class Type> bool operator<=( const Type& _ )const{ return operator<=(BigInt(_)); }
		template<class Type> bool operator>( const Type& _ )const{ return !operator<=(_); }
		template<class Type> bool operator>=( const Type& _ ) const{ return !operator<(_); }
		bool operator==( const BigInt& _ )const{ return signbit==_.signbit && BASE==_.BASE && v==_.v; }
		template<class Type> bool operator==( const Type& _ )const{ return operator==(BigInt(_)); }
		template<class Type> bool operator!=( const Type& _ )const{ return !(operator==(_)); }
		bool operator!()const{ return empty(); }
		BigInt operator^( int _ )const{
			BigInt ans(1);
			if(!_) return ans;
			BigInt POW(*this);
			while( _ ){
				if(_&1) ans *= POW;
				if( _>>=1 ) POW *= POW;
			}
			return ans;
		}
		BigInt& operator^=( int _ ){ return *this = operator^(_); }
		BigInt& operator=( const BigInt& _ ){
			v = _.v;
			signbit = _.signbit;
			BASE = _.BASE;
			return *this;
		}
};
template<> string BigInt::to<string>()const{
	if(empty()) return "0";
	string ans;
	if(signbit) ans.push_back('-');
	B_rFOR ans.push_back( _base[get(i)] );
	return ans;
}
template<> char* BigInt::to<char*>()const{
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
template<> char BigInt::to<char>()const{ if(empty()) return '0'; return _base[get(0)]; }
BigInt::operator char()const{ return to<char>(); }
BigInt::operator string()const{ return to<string>(); }
istream& operator>>( istream& in, BigInt& _ ){
	string buffer;
	in >> buffer;
	_.assign(buffer);
	return in;
}
ostream& operator<<( ostream& out, const BigInt& _ ){ return out << string(_); }
int BigInt::use_base = 10;
#undef BIGINT_CONTAINER
#undef BIGINT_cTYPE
#undef B_FOR
#undef B_rFOR
#endif /* _INCLUDE_BIGINT */
/** END BigInt v1.3 **/
/** IsosceleS 2013(c) **/
#define GHOST(i) ghost=true; cout << "Ghost of " << i << "!!!" << endl
#define noGHOST cout << "No ghost will come in this year" << endl
BigInt y, came(2148);
bool f(false), leap, ghost;
int main(){
	while( cin >> y, y ){
		if( f ) cout << endl;
		else f = true;
		cout << y << endl;
		if( y<came ){
			noGHOST;
			continue;
		}
		ghost = false;
		leap = ( y%400==0 || ( y%4==0 && y%100!=0 ) );
		y -= came;
		if( y%2==0 ){
			GHOST( "Tanveer Ahsan" );
		}
		if( y%5==0 ){
			GHOST( "Shahriar Manzoor" );
		}
		if( y%7==0 ){
			GHOST( "Adrian Kugel" );
		}
		if( y%11==0 ){
			GHOST( "Anton Maydell" );
		}
		if( y%15==0 ){
			GHOST( "Derek Kisman" );
		}
		if( y%20==0 ){
			GHOST( "Rezaul Alam Chowdhury" );
		}
		if( y%28==0 ){
			GHOST( "Jimmy Mardell" );
		}
		if( y%36==0 ){
			GHOST( "Monirul Hasan" );
		}
		if( leap ){
			GHOST( "K. M. Iftekhar" );
		}
		if( !ghost ) noGHOST;
	}
}
