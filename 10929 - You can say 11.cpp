/**
	UVa 10929 - You can say 11
	by Rico Tiongson
	Submitted: May 8, 2013
	Accepted 0.069s C++
	O(n) time
*/
#include<deque>
#include<vector>
#include<iostream>
using namespace std;
#define digitTYPE short
class BigInt{
	typedef deque<digitTYPE> vdig;
	typedef long long lag;
	#define T_ template
	#define _T typename
	vdig v; //reverse digits 21470 = 07412
	void _trim(){while(v.size()>1){if(v.back()==0) v.pop_back();else return;}}
	bool unsigned_compare(const BigInt& b) const{ //this is larger or equal to
		if(size()==b.size()){
			int i=size();
			while(--i!=-1){
				if(getdigit(i)!=b.getdigit(i)) return getdigit(i)>b.getdigit(i)?sign:b.sign;
			}
			return 1; //case same
		}
		return size()>b.size()?sign:b.sign;
	}
	BigInt mult1(const digitTYPE& b,const int& I) const{ //single digit mult
		if(b==0) return 0;
		BigInt c(0,0);
		if(b!=1){
			digitTYPE hold=0,temp;
			for(int i=0;i!=size();i++){
				temp=b*getdigit(i)+hold;
				hold=temp/10;
				c.push_front(temp%10);
			}
			if(hold) c.push_front(hold);
		}
		else c=*this;
		for(int i=0;i<I;i++) c.push_back(0);
		return c;
	}
	BigInt pow(const lag& exponent)const{
		if(exponent==1) return *this;
		BigInt c=(*this)^(int(exponent/2));
		if(exponent%2) return *this*c*c;
		else return c*c;
	}
	struct _modulus{
		lag mod,ismod;
		_modulus():mod(),ismod(){}
	} modulus;
	bool sign;
	public:
		//methods
			const BigInt reverse()const{BigInt c(0,0);c.sign=sign;for(int i=0;i<size();i++)c.push_back(getdigit(i));return c;}
			void print(ostream& outs=cout)const{if(!sign) outs<<'-';int i=size();while(i--) outs<<getdigit(i);}
			T_<_T TYPE> void assign(TYPE num){modulus=_modulus();v.clear();if(num<TYPE()){sign=0;num=-num;}else sign=1;do{push_front(num%10);num/=10;}while(num!=0);}
			void assign(const BigInt& b){v=b.v;sign=b.sign;modulus=b.modulus;}
			void assign(const string& s){modulus=_modulus();v.clear();int i=s.length();while(--i) v.push_back(s[i]-'0'); if(s[0]=='-')sign=0; else if(s[0]=='+')sign=1; else{v.push_back(s[i]-'0'); sign=1;} _trim();}
			void assign(const char* _s){modulus=_modulus();string s=_s;v.clear();int i=s.length();while(--i) v.push_back(s[i]-'0'); if(s[0]=='-')sign=0; else if(s[0]=='+')sign=1; else{v.push_back(s[i]-'0'); sign=1;} _trim();}
			void assign(const char& c){modulus=_modulus();v.clear();v.push_back(c-'0');sign=1;}
			T_<_T TYPE> void u_assign(TYPE num){v.clear();sign=1;while(num!=0){v.push_front(num%10);num/=10;}}
			void clear(){assign(0);}
			digitTYPE& front(){return v.back();}
			digitTYPE& back(){return v.front();}
			void push_front(const digitTYPE& num){ v.push_back(num);}
			void push_back(const digitTYPE& num){ v.push_front(num);}
			bool pop_front(){if(v.empty()) return false; v.pop_back(); return true;}
			bool pop_back(){if(v.empty()) return false; v.pop_front(); return true;}
		//constructors
			BigInt():v(1,0),sign(1),modulus(){}
			BigInt(const bool& _a, const bool& _b):sign(1),v(),modulus(){} //no construction
			BigInt(const BigInt& b):v(b.v),sign(b.sign),modulus(){}
			T_<_T TYPE> BigInt(const TYPE& num){ assign(num);}
			T_<_T TYPE> BigInt& operator=(const TYPE& b){ assign(b); return *this;}
		//convert
			T_<_T TYPE> TYPE& to(TYPE& _placeholder) const{_placeholder=TYPE(0);int i=size();while(i--) _placeholder=_placeholder*10+getdigit(i);return sign?_placeholder:-_placeholder;}
			string& to(string& _placeholder) const{_placeholder.clear();if(!sign) _placeholder='-';int i=size();while(i--) _placeholder.push_back(getdigit(i)+'0');return _placeholder;}
			char& to(char& _placeholder) const{_placeholder=getdigit(size()-1)+'0';return _placeholder;}
			T_<_T TYPE> const TYPE to() const{TYPE _placeholder=TYPE();int i=size();while(i--)_placeholder=_placeholder*10+getdigit(i);return sign?_placeholder:-_placeholder;}
			const string to_str() const{string _placeholder;if(!sign) _placeholder='-';int i=size();while(i--)_placeholder.push_back(getdigit(i)+'0');return _placeholder;}
			T_<_T TYPE> vector<TYPE> to_vector(){ return vector<TYPE>(v.rbegin(),v.rend());}
			T_<_T TYPE> deque<TYPE> to_deque(){ return deque<TYPE>(v.rbegin(),v.rend());}
		//accessors
			bool getsign()const{return sign;}
			int size()const{return v.size();}
			bool empty() const{return v.empty();}
			int digits() const{return v.size();}
			const digitTYPE getdigit(const int& index)const{return v[index]; } //faster access
			const digitTYPE digit(const int& index)const{return index<v.size()?v[index]:0;} //sure mapping
			vdig& access(){ return v;} //use built-in deque methods
		//operators
			//unary
			digitTYPE& operator[](const int& index){ return v[index];}
			//addition/subtraction
			BigInt operator+(const BigInt& b) const{
				if(*this==0) return b;
				if(b==0) return *this;
				BigInt c(0,0);
				bool hold=0;
				int i;
				if(sign==b.sign){
					c.sign=sign; //add
					if(size()<b.size()){
						for(i=0;i!=size();i++){
							c.push_front(getdigit(i)+b.getdigit(i)+hold);
							hold=c.front()>9;
							if(hold) c.front()-=10;
						}
						for(i=size();i!=b.size();i++){
							if(hold){
								c.push_front(b.getdigit(i)+1);
								hold=(c.front()==10);
								if(hold) c.front()=0;
							}
							else c.push_front(b.getdigit(i));
						}
					}
					else{
						for(i=0;i!=b.size();i++){
							c.push_front(getdigit(i)+b.getdigit(i)+hold);
							hold=c.front()>9;
							if(hold) c.front()-=10;
						}
						for(i=b.size();i!=size();i++){
							if(hold){
								c.push_front(getdigit(i)+1);
								hold=(c.front()==10);
								if(hold) c.front()=0;
							}
							else c.push_front(getdigit(i));
						}	
					}
					if(hold) c.push_front(1);
				}
				else{ //subtract
					c.sign=unsigned_compare(b);
					if(sign==c.sign){ //islarger
						for(i=0;i!=b.size();i++){
							c.push_front(getdigit(i)-b.getdigit(i)-hold);
							hold=c.front()<0;
							if(hold) c.front()+=10;
							
						}
						for(i=b.size();i!=size();i++){
							if(hold){
								c.push_front(getdigit(i)-1);
								hold=(c.front()==-1);
								if(hold) c.front()=9;
							}
							else c.push_front(getdigit(i));
						}
					}
					else{
						for(i=0;i!=size();i++){
							c.push_front(b.getdigit(i)-getdigit(i)-hold);
							hold=c.front()<0;
							if(hold) c.front()+=10;
						}
						for(i=size();i!=b.size();i++){
							if(hold){
								c.push_front(b.getdigit(i)-1);
								hold=(c.front()==-1);
								if(hold) c.front()=9;
							}
							else c.push_front(b.getdigit(i));
						}
					}
					c._trim();
				}
				return c;
			}
			T_<_T TYPE> BigInt operator+(const TYPE& B) const{return *this+BigInt(B);}
			BigInt& operator++(int _){vdig::iterator it=v.begin();do{(*it)++;if(*it==10){*it=0;it++;}else return *this;} while(it!=v.end());push_front(1);return *this;}
			BigInt& operator--(int _){vdig::iterator it=v.begin();do{(*it)--;if(*it==-1){*it=9;it++;}else return *this;} while(it!=v.end());pop_front();return *this;}
			T_<_T TYPE> BigInt operator-(const TYPE& B) const{return *this+BigInt(-B);}
			BigInt operator-(const BigInt& B) const{return *this+(-B);}
			BigInt& operator+=(const BigInt& b){
				if(b==0) return *this;
				bool hold=0;
				int i;
				if(sign==b.sign){
					if(size()<b.size()){
						for(i=0;i!=size();i++){
							v[i]+=b.getdigit(i)+hold;
							hold=getdigit(i)>9;
							if(hold) v[i]-=10;
						}
						for(i=size();i!=b.size();i++){
							if(hold){
								push_front(b.getdigit(i)+1);
								hold=getdigit(i)==10;
								if(hold) front()=0;
							}
							else push_front(b.getdigit(i));
						}
					}
					else{
						for(i=0;i!=b.size();i++){
							v[i]+=b.getdigit(i)+hold;
							hold=getdigit(i)>9;
							if(hold) v[i]-=10;
						}
						for(i=b.size();i!=size();i++){
							if(hold){
								v[i]++;
								hold=getdigit(i)==10;
								if(hold) v[i]=0;
							}
							else break;
						}
					}
					if(hold) push_front(1);
				}
				else{ //subtract
					sign=unsigned_compare(b);
					if(sign==b.sign){ //islarger
						for(i=0;i!=size();i++){
							v[i]=b.getdigit(i)-getdigit(i)-hold;
							hold=getdigit(i)<0;
							if(hold) v[i]+=10;
						}
						for(i=size();i!=b.size();i++){
							if(hold){
								push_front(b.getdigit(i)-1);
								hold=getdigit(i)==-1;
								if(hold) front()=9;
							}
							else push_front(b.getdigit(i)-1);
						}
					}
					else{
						for(i=0;i!=b.size();i++){
							v[i]-=b.getdigit(i)+hold;
							hold=getdigit(i)<0;
							if(hold) v[i]+=10;
						}
						for(i=b.size();i!=size();i++){
							if(hold){
								v[i]--;
								hold=getdigit(i)==-1;
								if(hold) v[i]=9;
							}
							else break;
						}
					}
					_trim();
				}
				return *this;
			}
			T_<_T TYPE> BigInt& operator+=(const TYPE& B){return *this+=BigInt(B);}
			T_<_T TYPE> BigInt& operator-=(const TYPE& B){return *this+=BigInt(-B);}
			BigInt& operator-=(const BigInt& B){return *this+=(-B);}
			//multiplication/division/modulus
			BigInt operator*(const BigInt& b) const{
				BigInt c;
				digitTYPE hold=0;
				if(size()>b.size()){
					for(int i=0;i!=b.size();i++)
						c+=mult1(b.getdigit(i),i);
				}
				else{
					for(int i=0;i!=size();i++)
						c+=b.mult1(getdigit(i),i);
				}
				c.sign=(sign==b.sign);
				return c;
			}
			T_<_T TYPE> BigInt& operator*(const BigInt& B) const{ return *this*BigInt(B);}
			BigInt& operator*=(const BigInt& b){return *this=*this*b;}
			T_<_T TYPE> BigInt& operator*=(const TYPE& B){return *this=*this*BigInt(B);}
			BigInt operator/(const lag& b){
				BigInt c(0,0);
				c.sign=(sign==(b>-1));
				lag hold=0;
				digitTYPE k;
				for(int i=0;i!=size();i++){
					hold=hold*10+getdigit(size()-i-1);
					k=hold/b;
					c.push_back(k);
					hold-=k*b;
				}
				c._trim();
				modulus.ismod=b;
				modulus.mod=hold;
				return c;
			}
			BigInt operator/(const BigInt& B){return *this/(B.to<lag>());}
			BigInt& operator/=(const lag& b){return *this=*this/b;}
			BigInt& operator/=(const BigInt& B){return *this=*this/(B.to<lag>());}
			const lag operator%(const lag& b){
				if(modulus.ismod==b) return modulus.mod;
				lag hold=0;
				for(int i=0;i!=size();i++){
					hold=hold*10+getdigit(i);
					hold %= b;
				}
				modulus.ismod=-1;
				modulus.mod=hold;
				return hold;
			}
			const BigInt operator%(const BigInt& B){ return BigInt(*this%(B.to<lag>()));}
			BigInt& operator%=(const lag& b){
				if(modulus.ismod==b)
					return *this=modulus.mod;
				lag hold=0;
				for(int i=0;i!=size();i++){
					hold=hold*10+getdigit(i);
					hold %= b;
				}
				modulus.ismod=-1;
				return *this=hold;
			}
			BigInt& operator%=(const BigInt& B){return *this%=(B.to<lag>());}
			BigInt operator^(const lag& exponent)const{if(exponent==0) return BigInt(1); return pow(exponent);}
			T_<_T TYPE> BigInt operator^(const TYPE& exponent)const{ return (*this)^(BigInt(exponent).to<lag>());}
			//comparison
			bool operator<(const BigInt& b) const{
				if(sign==b.sign){
					if(size()==b.size()){
						int i=size();
						while(--i!=-1) if(getdigit(i)!=b.getdigit(i)) return getdigit(i)<b.getdigit(i);
						return 0; //case same
					}
					return size()<b.size();
				}
				return b.sign;
			}
			T_<_T TYPE> bool operator<(const TYPE& B) const{return *this<BigInt(B);}
			bool operator<=(const BigInt& b) const{
				if(sign==b.sign){
					if(size()==b.size()){
						int i=size();
						while(--i!=-1) if(getdigit(i)!=b.getdigit(i)) return getdigit(i)<b.getdigit(i);
						return 1; //case same
					}
					return size()<b.size();
				}
				return b.sign;
			}
			T_<_T TYPE> bool operator<=(const TYPE& B) const{return *this<=BigInt(B);}
			bool operator>(const BigInt& b) const{
				if(sign==b.sign){
					if(size()==b.size()){
						int i=size();
						while(--i!=-1) if(getdigit(i)!=b.getdigit(i)) return getdigit(i)>b.getdigit(i);
						return 0; //case same
					}
					return size()>b.size();
				}
				return sign;
			}
			T_<_T TYPE> bool operator>(const TYPE& B) const{return *this>BigInt(B);}
			bool operator>=(const BigInt& b) const{
				if(sign==b.sign){
					if(size()==b.size()){
						int i=size();
						while(--i!=-1) if(getdigit(i)!=b.getdigit(i)) return getdigit(i)>b.getdigit(i);
						return 1; //case same
					}
					return size()>b.size();
				}
				return sign;
			}
			T_<_T TYPE> bool operator>=(const TYPE& B) const{return *this>=BigInt(B);}
			bool operator==(const BigInt& b) const{
				if(sign==b.sign){
					if(size()==b.size()){
						int i=size();
						while(--i!=-1) if(getdigit(i)!=b.getdigit(i)) return 0;
						return 1; //case same
					}
					return 0;
				}
				return 0;
			}
			bool operator!=(const BigInt& b) const{return !(*this==b);}
			T_<_T TYPE> bool operator==(const TYPE& B) const{return *this==BigInt(B);}
			T_<_T TYPE> bool operator!=(const TYPE& B) const{return !(*this==BigInt(B));}
			//friends
			friend ostream& operator<<(ostream&,const BigInt&);
			friend istream& operator>>(istream&,BigInt&);
			friend const BigInt operator-(BigInt);			
};
const BigInt operator-(BigInt _BigInt){ if(_BigInt!=0) _BigInt.sign=!_BigInt.sign; return _BigInt;}
ostream& operator<<(ostream& outs, const BigInt& _BigInt){if(!_BigInt.sign) outs<<'-';int i=_BigInt.size();while(i--) outs<<char(_BigInt.getdigit(i)+'0');return outs;}
istream& operator>>(istream& ins, BigInt& _BigInt){string _s;ins >> _s;_BigInt.assign(_s);return ins;}
using namespace std;
int main(){
	BigInt x;
	char c[10000];
	while(cin >> c,c[0]!='0'||c[1]!='\0'){
		x = c;
		cout << c << " is ";
		if(x%11!=0) cout << "not ";
		cout << "a multiple of 11." << endl;
	}
}
