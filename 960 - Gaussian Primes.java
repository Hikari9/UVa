/**
	UVa 960 - Gaussian Primes
	by Rico Tiongson
	Submitted: August 22, 2013
	Accepted 0.192s Java
	O(n^2) time
*/
import java.util.*;
import java.io.*;

public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		int t = Integer.parseInt( br.readLine() );
		String s[];
		int a, b, c, d, n, num;
		int lim = 151;
		boolean breaker;
		while( t-- != 0 ){
			s = br.readLine().split( " " );
			a = Integer.parseInt( s[0] );
			b = Integer.parseInt( s[1] );
			n = a*a + b*b;
			// get a + bi
			breaker = false;
			Here:
			for( c=0; c<lim; ++c ){
				for( d=0; d<lim; ++d ){
					num = c*c + d*d;
					if( num<2 || num>=n ) continue;
					if( (a*c + b*d)%num==0 && (b*c - a*d)%num==0 ){
						pw.println( "C" );
						breaker = true;
						break Here;
					}
				}
			}
			if( !breaker ) pw.println( "P" );
		}
		pw.close();
	}
}
