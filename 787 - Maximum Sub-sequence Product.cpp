/**
	UVa 787 - Maximum Sub-sequence Product
	by Rico Tiongson
	Submitted: June 23, 2013
	Accepted 0.035s C++
	O( n ) time DP
*/
#include<cstdio>
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<functional>
using namespace std;
#define BIGINT_CONTAINER deque<int>
#define B_FOR for( unsigned i(0); i<size(); ++i )
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
		B_FOR if( digit(i)!=_.digit(i) ) return cmp( digit(i), _.digit(i) );
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
		for( unsigned i=0; i<_.size(); ++i ) v[i] += _.get(i);
		return *this;
	}
	BigInt& DECCUMULATE( const BigInt& _ ){
		bool u = U_COMPARE( _ );
		push_left( 0, _.size()-size() );
		for( unsigned i=0; i<_.size(); ++i ) v[i] -= _.get(i);
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
			v[i]+=hold;
			if(v[i]<0){
				hold = v[i]/BASE-1;
				v[i] = BASE+v[i]%BASE;
			}
			else hold = 0;
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
		for(unsigned i=0;i<size();++i){
			hold*=BASE;
			hold+=digit(i);
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
		for(unsigned i=0;i<size();++i){
			hold*=BASE;
			hold+=digit(i);
			k = hold/_;
			ans.push_right(k);
			hold-=_*k;
		}
		ans.trim_left();
		return ans;
	}
	
	template<class Type> BigInt NUMBER_MOD( Type _ )const{
		#ifdef BIGINT_EXCEPTION
			if(!_)
			throw BigInt_Exception(1,"Arithmetic Exception","Modulo by Zero","private : BigInt::NUMBER_MOD( Type )");
		#endif 
		BigInt ans;
		ans.signbit = (signbit!=(_<0));
		ans.BASE = BASE;
		Type hold=0;
		int k;
		for(unsigned i=0;i<size();++i){
			hold*=BASE;
			hold+=digit(i);
			k = hold/_;
			ans.push_right(k);
			hold-=_*k;
		}
		return hold;
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
				unsigned i(0);
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
			unsigned i=0;
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
		template<class Type> BigInt( const Type& _, int b ):BASE( b ) { assign( _ ); }
		
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
			#ifdef BIGINT_EXCEPTION
				if( b < 2 ) throw BigInt_Exception(2,"InvalidBase Exception","Base < 2","BigInt::toBase( int )");
				else if( b >61 ) throw BigInt_Exception(2,"InvalidBase Exception","Base > 61","BigInt::toBase( int )");
			#endif 
			BigInt ans;
			ans.BASE = b;
			ans.signbit = signbit;
			pair<BigInt,int> DIV;
			while(!empty()){
				DIV = div( b );
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
			B_FOR{
				ans *= BASE;
				ans += digit(i);
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
		
		bool& sign(){ return signbit; }
		
		unsigned size()const{ return v.size(); }
		
		unsigned length()const{ return v.size(); }
		
		bool empty()const{ return v.empty(); }
		
		int get( unsigned _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::get( unsigned )");
			#endif 
			return v[_];
		}//from ones digit
		
		int digit( unsigned _ )const{
			#ifdef BIGINT_EXCEPTION
				if(_>=size()) throw BigInt_Exception(3,"OutOfRange Exception","Index Out of Range","BigInt::digit( unsigned )");
			#endif 
			return v[ size()-_-1 ];
		} //from most significant digit
		
		int& left(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::left( )");
			#endif 
			return v.back();
		}
		
		int& right(){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::right( )");
			#endif 
			return v.front();
		}
		
		int& operator[]( unsigned _ ){
			#ifdef BIGINT_EXCEPTION
				if(empty()) throw BigInt_Exception(3,"OutOfRange Exception","Force Access on Empty Container","BigInt::operator[] ( unsigned )");
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
				for(unsigned i=0;i<size();++i){
					if(--v[i]==-1) v[i] = BASE-1;
					else return trim_left();
				}
			}
			else{
				for(unsigned i=0;i<size();++i){
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
			else DECCUMULATE ( _ ).UNCARRY().trim_left();
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
			BigInt ans,temp;
			ans.BASE = BASE;
			if(size()<_.size()){
				for(unsigned int i=0;i<size();++i)
					ans += _.operator*(get(i)).push_right(0,i);
			}
			else{
				for(unsigned int i=0;i<_.size();++i){
					ans += operator*(_.get(i)).push_right(0,i);
				}
			}
			ans.signbit = (signbit!=_.signbit);
			return ans;
		}
		
		BigInt operator*( int _ )const{
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
				for(unsigned i=0;i<size();++i){
					hold += _*get(i);
					ans.push_left(hold%BASE);
					hold/=BASE;
				}
				if(hold) ans.push_left(hold);
			}
			else ans.v = v;
			ans.CARRY();
			return ans;
		}
		
		template<class Type> pair<BigInt, Type> div( const Type& _ )const{ return NUMBER_DIV( _ ); }
		
		pair<BigInt,BigInt> div( const BigInt& _ )const{
			#ifdef BIGINT_EXCEPTION
				if(!_) throw BigInt_Exception(1,"Arithmetic Exception","Division by Zero","BigInt::div( const BigInt& )");
			#endif 
			if(empty()) return pair<BigInt,BigInt>(*this,*this);
			if(_.size()<18u) return NUMBER_DIV( _.to<long long>());
			if(BASE!=_.BASE) return div(_.base(BASE));
			if( U_COMPARE(_) ){
				BigInt ans;
				ans.BASE = BASE;
				return pair<BigInt,BigInt>(ans,signbit!=_.signbit?-*this:*this);
			}
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(unsigned i=_.size()-4u;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_FOR{
				hold.push_right( digit(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( unsigned j=_.size()-4u;j<hold.size();++j ){
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
			if(_.size()<18u) return NUMBER_DIVISION(_.to<long long>());
			if(BASE!=_.BASE) return operator/(_.base(BASE));
			if( U_COMPARE(_) ){
				BigInt ans;
				ans.BASE = BASE;
				return ans;
			}
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(unsigned i=_.size()-4u;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_FOR{
				hold.push_right( digit(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( unsigned j=_.size()-4u;j<hold.size();++j ){
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
		template<class Type> BigInt operator/( const Type& _ )const{  return NUMBER_DIVISION(_); }
		template<class Type> BigInt& operator/=( const Type& _ ){ return *this = operator/(_); }
		BigInt operator%( const BigInt& _ )const{
			#ifdef BIGINT_EXCEPTION
				if(!_) throw BigInt_Exception(1,"Arithmetic Exception","Modulo by Zero","BigInt::operator%( const BigInt& )");
			#endif 
			if(empty()) return *this;
			if(_.size()<18u) return NUMBER_MOD(_.to<long long>());
			if(BASE!=_.BASE) return operator%(_.base(BASE));
			if( U_COMPARE( _ ) ) return signbit!=_.signbit?-*this:*this;
			BigInt ans,hold,temp;
			long SMALL = 0,HOLDER;
			for(unsigned i=_.size()-4u;i<_.size();++i){
				SMALL*=_.BASE;
				SMALL+=_.get(i);
			}
			ans.BASE = hold.BASE = BASE;
			hold.signbit = _.signbit;
			int val;
			B_FOR{
				hold.push_right( digit(i) );
				if( hold.U_COMPARE( _ ) ){
					ans.push_right( 0 );
				}
				else{
					//estimate
					//fix binary
					HOLDER = 0;
					for( unsigned j=_.size()-4u;j<hold.size();++j ){
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
		template<class Type> BigInt operator%( const Type& _ )const{  return NUMBER_MOD(_); }
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
		template<class Type> bool operator>( const Type& _ )const{ return _.operator<(*this); }
		template<class Type> bool operator>=( const Type& _ ) const{ return _.operator<=(*this); }
		bool operator==( const BigInt& _ )const{ return signbit==_.signbit && BASE==_.BASE && v==_.v; }
		template<class Type> bool operator==( const Type& _ )const{ return operator==(BigInt(_)); }
		template<class Type> bool operator!=( const Type& _ )const{ return !(operator==(_)); }
		bool operator!()const{ return empty(); }
		BigInt operator^( int _ )const{
			if(!_) return BigInt(1);
			BigInt POW = operator^(_/2);
			if(_%2) return operator*(POW*POW);
			return POW*POW;
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
	B_FOR ans.push_back( _base[digit(i)] );
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
	for(unsigned i=0;i<size();++i){
		*p = digit(i)+'0';
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
/** END BigInt v1.1 **/
/** IsosceleS 2013(c) **/
#define INF -999999
int x, i, j;
BigInt Left, Right, product, mx;
bool zero, isneg;
vector<int> v;
void calculate(){
	if( v.empty() ) return;
	if( isneg && v.size()!=1 ){
		// retrieve bigger end
		Left = Right = 1;
		for( i=0; i<v.size(); ++i ){
			Left *= v[i];
			if( v[i]<0 )
				break;		
		}
		for( j=v.size()-1; j>=0; --j ){
			Right *= v[j];
			if( v[j]<0 )
				break;
		}
		product = 1;
		if( Left < Right ){ // higher magnitude left side!!
			for( x=0; x<j; ++x ) product *= v[x];
		}
		else{
			for( x=i+1; x<v.size(); ++x ) product *= v[x];
		}
	}
	else{
		product = 1;
		for( i=0; i<v.size(); ++i ) product*=v[i];
	}
	if( mx < product ) mx = product;
	isneg = false;
	v.clear();
}
int main(){
	while( scanf("%d",&x)!=EOF ){
		if( x==INF ){
			puts("0"); // no ans
			continue;
		}
		isneg = zero = false;
		mx = x;
		do{
			if( !x ){
				zero = true;
				calculate();
			}
			else{
				if( x<0 ) isneg = !isneg;
				v.push_back( x );
			}
			scanf("%d",&x);
		} while( x!=INF );
		calculate();
		// negative maximum, prefer zero
		if( mx.sign() && zero ) puts("0");
		else cout << mx << endl;
	}
}
