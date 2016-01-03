/**
	UVa 11161 - Help My Brother (II)
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.248s Java
	O(n) pregen + O(1) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		BigInteger f[] = new BigInteger[1505];
		f[0] = BigInteger.ONE;
		f[1] = BigInteger.ONE;
		int i;
		for( i=2; i<f.length; ++i )
			f[i] = f[i-1].add(f[i-2]);
		for( i=0; i<f.length; ++i )
			f[i] = f[i].subtract( BigInteger.ONE );
		String a;
		int set=0;
		while( !(a=br.readLine()).equals("0") ){
			pw.println( "Set " + (++set) + ":" );
			i = Integer.parseInt(a);
			pw.println( f[i].shiftLeft(1).add(f[i-1]).shiftRight(1) );
		}
		
		pw.close();
	}
}

