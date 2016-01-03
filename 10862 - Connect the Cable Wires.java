/**
	UVa 10862 - Connect the Cable Wires
	by Rico Tiongson
	Submitted: September 15, 2013
	Accepted 0.219s Java
	O(n) pregen + O(1) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	public static void main( String args[] ) throws IOException {
	
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		BigInteger f[] = new BigInteger[4001];
		f[0] = BigInteger.ZERO;
		f[1] = BigInteger.ONE;
		for( int i=2; i<f.length; ++i )
			f[i] = f[i-1].add(f[i-2]);
		
		String a;
		
		while( !(a=br.readLine()).equals("0") )
			pw.println( f[Integer.parseInt(a)<<1] ); 
		
		
		pw.close();
		
	}
}
