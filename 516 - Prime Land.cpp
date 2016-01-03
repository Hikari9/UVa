/**
	UVa 516 - Prime Land
	by Rico Tiongson
	Submitted: August 29, 2013
	Accepted 0.036s C++
	O(nloglognsqrtn) time
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#define mx 32767
using namespace std;
bool notPr[mx];
vector<int> pr;
vector<pair<int,int> > pf[mx];
int i, j, k, c, prime, expo, num;
char line[200001], *p;
int power( int base, int ex ){
	if( ex==1 ) return base;
	int half = power( base, ex >> 1 );
	if( ex & 1 ) return base * half * half;
	return half * half;
}
int main(){
	pr.push_back(2);
	for( j=4, c=2; j<mx; j+=2, ++c ){
		notPr[j] = true;
	}
	for( i=3; i<mx; i+=2 ){
		if( !notPr[i] ){
			pr.push_back(i);
			for( j=i*i; j<mx; j+=i ){
				notPr[j] = true;
			}
		}
	}
	for( i=2; i<mx; ++i ){
		k = i;
		for( j=0; j<pr.size() && pr[j]*pr[j]<=k; ++j ){
			if( k%pr[j]==0 ){
				pf[i].push_back(make_pair(pr[j],1));
				k /= pr[j];
				while( k%pr[j]==0 ){
					++pf[i].back().second;
					k /= pr[j];
				}
			}
		}
		if( k>1 ) pf[i].push_back(make_pair(k,1));
	}
	// for( i=0; i<mx; ++i ){
		// cout << i << ": ";
		// for( j=0; j<pf[i].size(); ++j ){
			// cout << "(" << pf[i][j].first << "," << pf[i][j].second << ") ";
		// }
		// cout << endl;
	// }
	while( gets(line) ){
		if( line[0]=='0' && line[1]=='\0' ) return 0;
		num = 1;
		for( p=strtok(line," "); p!=NULL; p=strtok(NULL," ") ){
			prime = atoi(p);
			p = strtok(NULL," ");
			expo = atoi(p);
			num *= power( prime, expo );
		}
		--num;
		// printf( "NUM: %d\n", num );
		if( /* num >=0 && */ !pf[num].empty() ){
			printf( "%d %d", pf[num].back().first, pf[num].back().second );
			for( i=pf[num].size()-2; i>=0; --i ){
				printf( " %d %d", pf[num][i].first, pf[num][i].second );
			}
		}
		putchar( '\n' );
	}
}
