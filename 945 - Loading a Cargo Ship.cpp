/**
	UVa 945 - Loading a Cargo Ship
	by Rico Tiongson
	Submitted: July 6, 2013
	Accepted 0.018s C++
	O(n) time
*/
#include<cstdio>
#include<cstring>
// using namespace std;
int c, p, i, j, mn, cargo, unused, unloaded, cw[10], num[10], pw[1000];
char st[10][1000];
bool f=false;
int main(){
	while( scanf("%d",&c) ==1){
		if(f) putchar('\n');
		else f=true;
		++c;
		// c = getchar()-'0';
		// int cw[ ++c ];
		// int num[c];
		// char st[c][1000];
		cargo = unused = unloaded = 0;
		memset( num, 0, sizeof( num ) );
		memset( st, ':', sizeof( st ) );
		getchar();
		// puts("YO");
		for( i=1; i<c; ++i ){
			scanf("%d", cw+i);
			getchar();
		}
		getchar();
		scanf("%d", &p);
		if(p>999) p=999;
		// p = min(p, 999);
		getchar();
		// int pw[p];
		for( i=0; i<p; ++i ){
			// cin >> pw[i];
			pw[i] = getchar()-'0';
			getchar();
		}
		for( i=0; i<p; ++i ){
			// get min
			mn = 1;
			for( j=2; j<c; ++j ){
				// choose
				if( num[j] < num[mn] || (num[j]==num[mn]&&cw[j]>cw[mn]) ){
					mn = j;
				}
			}
			if( cw[mn] < pw[i] ) break;
			st[mn][ num[mn] ] = pw[i]+'0';
			cw[mn] -= pw[i];
			cargo += pw[i];
			++num[mn];
		}
		for( ; i<p; ++i ){
			unloaded += pw[i];
		}
		mn = 0;
		for( i=1; i<c; ++i ){
			unused += cw[i];
			if( num[i]>mn ) mn = num[i];
		}
		for( --mn; mn>=0; --mn ){
			putchar( st[1][mn] );
			for( i=2; i<c; ++i ){
				putchar(' ');
				putchar( st[i][mn] );
			}
			putchar('\n');
		}
		putchar('=');
		for( i=2; i<c; ++i ){
			putchar('=');
			putchar('=');
		}
		putchar('\n');
		putchar('1');
		for( i=2; i<c; ++i ){
			putchar(' ');
			putchar(i+'0');
		}
		printf("\n\ncargo weight: %d\n", cargo);
		printf("unused weight: %d\n",unused);
		printf("unloaded weight: %d\n",unloaded);
		// cout << "cargo weight: " << cargo << endl;
		// cout << "unused weight: " << unused << endl;
		// cout << "unloaded weight: " << unloaded << endl;
	}
}
