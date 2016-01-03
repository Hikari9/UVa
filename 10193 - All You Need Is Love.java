/**
	UVa 10193 - All You Need Is Love
	by Rico Tiongson
	Submitted: July 26, 2013
	Accepted 0.182s Java
	O(logn) time
*/
import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		int n = Integer.parseInt( br.readLine() );
		BigInteger x, y;
		for( int i=1; i<=n; ++i ){
			x = new BigInteger( br.readLine(), 2 );
			y = new BigInteger( br.readLine(), 2 );
			// pw.println( x + "\n" + y );
			if( x.gcd( y ).equals( BigInteger.ONE ) ){
				pw.printf("Pair #%d: Love is not all you need!\n", i);
			}
			else{
				pw.printf("Pair #%d: All you need is love!\n", i);
			}
		}
		pw.close();
	}
}
