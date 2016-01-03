/**
	UVa 993 - Product of digits
	by Rico Tiongson
	Submitted: October 29, 2013
	Accepted 0.148s Java
	O(log^3(n)(base 10)) time
*/
import java.util.*;
import java.io.*;

public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		int t = Integer.parseInt( br.readLine().trim() );
		while( t-- != 0 ){
			int n = Integer.parseInt( br.readLine().trim() );
			StringBuilder sb = new StringBuilder();
			if( n < 2 ) sb.append(n);
			for( int i=9; i>1 && n > 1; --i ){
				while( n % i == 0 ){
					sb.append(i);
					n /= i;
				}
			}
			// merge on contact
			if( n > 1 ) pw.println( "-1" );
			else{
				char[] s = sb.toString().toCharArray();
				Arrays.sort(s);
				for( int i=0; i<s.length; ++i )
					pw.print( s[i] );
				pw.println();
			}
		}
		pw.close();
	}
}