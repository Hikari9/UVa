/**
	UVa 1232 - SKYLINE
	by Rico Tiongson
	Submitted: October 20, 2013
	Accepted 1.666s Java
	O(nlogn) time
*/
import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
	static final int MX = 131073;
	static int t, n;
	static int l, r, h;
	static int[] st = new int[MX<<2];
	static int[] dt = new int[MX<<2];
	static int overlaps;
	
	static void renew( int p ){
		st[p] = max( st[p], dt[p] );
		int next = p << 1;
		dt[next] = max( dt[next], dt[p] );
		dt[next+1] = max( dt[next+1], dt[p] );
		dt[p] = -1;
	}
	
	static void modify( int p, int L, int R ){
		if( r < L || l > R ) return;
		int M = (L + R) >> 1;
		int next = p << 1;
		if( l <= L && R <= r ){
			dt[p] = max( dt[p], h );
			if( max( dt[p], st[p] ) <= h ){
				renew( p );
				if( L == R ){
					++overlaps;
					return;
				}
				modify( next, L, M );
				modify( next+1, M+1, R );
			}
			return;
		}
		renew( p );
		modify( next, L, M );
		modify( next+1, M+1, R );
		st[p] = min( max( st[next], dt[next] ), max( st[next+1], dt[next+1] ) );
	}
	
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		String[] s;
		t = Integer.parseInt( br.readLine() );
		while( t-- != 0 ){
			n = Integer.parseInt( br.readLine() );
			Arrays.fill( st, 0 );
			Arrays.fill( dt, -1 );
			overlaps = 0;
			while( n-- != 0 ){
				s = br.readLine().split(" ");
				l = Integer.parseInt( s[0] );
				r = Integer.parseInt( s[1] ) - 1;
				h = Integer.parseInt( s[2] );
				modify( 1, 1, MX-1 );
			}
			pw.println( overlaps );
		}
		pw.close();
	}
}