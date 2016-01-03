/**
	UVa 10852 - Less Prime
	by Rico Tiongson
	Submitted: August 29, 2013
	Accepted 0.019s C++
	O(nloglogn) pregen + O(sqrtn) time
*/
#include<iostream>
#include<cstring>
#include<vector>
#define mn 100
#define mx 10001
using namespace std;

bool *isPr;
vector<int> pr;
void sieve(int);

int t, n, i, j, ans, ansx, mod;

int main(){
	sieve(mx);
	cin >> t;
	while( t-- ){
		cin >> n;
		ans = -1;
		for( i=0; i<pr.size() && pr[i]<=n; ++i ){
			mod = n%pr[i];
			if( ans < mod ){
				ans = mod;
				ansx = pr[i];
			}
		}
		cout << ansx << endl;
	}
}

void sieve( int mxNum ){
	isPr = new bool[mxNum];
	memset( isPr, -1, mxNum );
	pr.clear();
	pr.push_back(2);
	for( j=4; j<mxNum; j+=2 ){
		isPr[j] = false;
	}
	for( i=3; i<mxNum; i+=2 ){
		if( isPr[i] ){
			pr.push_back(i);
			for( j=i*i; j<mxNum; j+=i ){
				isPr[j] = false;
			}
		}
	}
}

