/**
	UVa 12412 - A Typical Homework (a.k.a Shi Xiong Bang Bang Mang)
	by Rico Tiongson
	Submitted: August 1, 2013
	Accepted 0.022s C++
	O(WTF) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<cctype>
using namespace std;
#define m1 ("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n")
#define m2 ("Please enter the SID, CID, name and four scores. Enter 0 to finish.")
#define m3 ("Please enter SID or name. Enter 0 to finish.")
// #define m4 "Please enter SID or name. Enter 0 to finish."
#define m5 ("Please enter class ID, 0 for the whole statistics.")
#define eps 0.0001

struct node{
	string name;
	int CID, s[4], rank, total;
	double ave;
	node() {}
	node( const node& _ ): name( _.name ), CID( _.CID ), rank( _.rank ){
		total = 0;
		for( int i=0; i<4; ++i ){
			s[i] = _.s[i];
			total += s[i];
		}
		ave = double(total)/4.0 + eps;
	}
	node& operator=( const node& _ ){
		name = _.name;
		CID = _.CID;
		rank = _.rank;
		total = 0;
		for( int i=0; i<4; ++i ){
			s[i] = _.s[i];
			total += s[i];
		}
		ave = double(total)/4.0 + eps;
	}
	void printRank( const string& SID ){
		cout << rank << ' ' << SID << ' ' << CID << ' ' << name << ' ' << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << ' ' << total;
		printf( " %.2lf\n", ave );
	}
} test;
istream& operator>>( istream& in, node& _ ){ return in >> _.CID >> _.name >> _.s[0] >> _.s[1] >> _.s[2] >> _.s[3]; /* normalize(); return in; */ }
string SID, ZERO("0");
int cnt;
typedef map<string,node> Map;
Map m;
vector<node*> v;
Map::iterator it;
pair<Map::iterator,bool> itIns;
map<string,list<Map::iterator> > n;
map<string,list<Map::iterator> >::iterator itn;
list<Map::iterator>::iterator lit;
void ins();
void rem();
void que();
void lol();
void stat();
int main(){
	int cmd;
	while( true ){
		cout << m1;
		cin >> cmd;
		switch( cmd ){
			case 1: ins(); break;
			case 2: rem(); break;
			case 3: que(); break;
			case 4: lol(); break;
			case 5: stat(); break;
			case 0: return 0;
		}
	}
}
void ins(){
	while( true ){
		cout << m2 << '\n';
		cin >> SID;
		if( SID==ZERO ) break;
		cin >> test;
		itIns = m.insert( make_pair( SID, test ) );
		if( itIns.second ){ // inserted
			n[test.name].push_back( itIns.first );
		}
		else cout << "Duplicated SID." << '\n';
	}
}
void rem(){
	// int cnt;
	while( true ){
		cnt = 0;
		cout << m3 << '\n';
		cin >> SID;
		if( SID==ZERO ) break;
		if( isdigit( SID[0] ) ){
			it = m.find( SID );
			if( it!=m.end() ){
				itn = n.find( it->second.name );
				itn->second.remove( it );
				if( itn->second.empty() ) n.erase( itn );
				m.erase( it );
				++cnt;
			}
		}
		else{
			itn = n.find( SID );
			if( itn!=n.end() ){
				cnt = itn->second.size();
				for( lit=itn->second.begin(); lit!=itn->second.end(); ++lit ){
					m.erase( *lit );
				}
				n.erase( itn );
			}
		}
		cout << cnt << " student(s) removed." << '\n';
	}
}
bool byRank( const node* lhs, const node* rhs ){
	return lhs->total > rhs->total;
}
void que(){
	// makeRank
	if( !m.empty() ){
		v.clear();
		for( it=m.begin(); it!=m.end(); ++it ){
			v.push_back( & (it->second) );
		}
		sort( v.begin(), v.end(), byRank );
		v[0]->rank = 1;
		for( int i=1; i<v.size(); ++i ){
			if( v[i]->total==v[i-1]->total ) v[i]->rank = v[i-1]->rank;
			else v[i]->rank = (i+1);
		}
	}
	while( true ){
		cout << m3 << '\n';
		cin >> SID;
		if( SID==ZERO ) break;
		if( isdigit( SID[0] ) ){
			it = m.find( SID );
			if( it!=m.end() ){
				it->second.printRank( it->first );
			}
		}
		else{
			itn = n.find( SID );
			if( itn!=n.end() ){
				for( lit=itn->second.begin(); lit!=itn->second.end(); ++lit ){
					(*lit)->second.printRank( (*lit)->first );
				}
			}
		}
	}
}
void lol(){
	cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << '\n';
}
double Ave[4];
int Total[4], Pass[4], Fail[4], p[5], CID, pa;
void stat(){
	cout << m5 << '\n';
	
	memset( Total, 0, sizeof Total );
	memset( Pass, 0, sizeof Pass );
	memset( Fail, 0, sizeof Fail );
	memset( p, 0, sizeof p );
	cnt = 0;
	cin >> CID;
	if( CID>0 ){
		for( it=m.begin(); it!=m.end(); ++it ){
			if( CID==it->second.CID ){
				++cnt;
				pa = 0;
				for( int i=0; i<4; ++i ){
					Total[i] += it->second.s[i];
					if( it->second.s[i] >= 60 ){
						++Pass[i];
						++pa;
					}
					else ++Fail[i];
				}
				if( !pa ) ++p[0];
				else{
					for( int i=1; i<=pa; ++i ) ++p[i];
				}
			}
		}
	}
	else{
		// all
		cnt = m.size();
		for( it=m.begin(); it!=m.end(); ++it ){
			pa = 0;
			for( int i=0; i<4; ++i ){
				Total[i] += it->second.s[i];
				if( it->second.s[i] >= 60 ){
					++Pass[i];
					++pa;
				}
				else ++Fail[i];
			}
			if( pa==0 ) ++p[0];
			else{
				for( int i=1; i<=pa; ++i ) ++p[i];
			}
		}
	}
	// memset( Ave, 0, sizeof Ave );
	if( cnt ){
		for( int i=0; i<4; ++i ) Ave[i] = double(Total[i])/cnt + eps;
	}
	else for( int i=0; i<4; ++i ) Ave[i] = eps;
	printf("Chinese\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\nMathematics\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\nEnglish\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\nProgramming\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\nOverall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n", Ave[0], Pass[0], Fail[0], Ave[1], Pass[1], Fail[1], Ave[2], Pass[2], Fail[2], Ave[3], Pass[3], Fail[3], p[4], p[3], p[2], p[1], p[0]);
}
