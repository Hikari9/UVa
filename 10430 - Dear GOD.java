/**
	UVa 10430 - Dear GOD
	by Rico Tiongson
	Submitted: September 1, 2013
	Accepted 0.322s Java
	O(n+logn) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	public static void main( String args[] ) throws IOException{
	
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		boolean f = false;
		int i, N;
		String a, s[];
		BigInteger T, numerator, denominator, gcd, powers[] = new BigInteger[101];
		
		powers[0] = BigInteger.ONE;
		
		pw.println("Dear GOD, Pardon Me");
		
		while( (a=br.readLine())!=null ){
			if(f) pw.print('\n');
			else f = true;
			s = a.split(" ");
			T = new BigInteger(s[0]);
			N = Integer.parseInt(s[1]);
			for( i=1; i<=N; ++i )
				powers[i] = powers[i-1].multiply(T);
			numerator = BigInteger.ZERO;
			for( i=N-1; i>=0; --i )
				numerator = numerator.add(powers[i]);
			denominator = powers[N];
			gcd = numerator.gcd(denominator);
			pw.println( "X = " + numerator.divide(gcd).toString() + "\nK = " + denominator.divide(gcd).toString() );
		}
		
		pw.close();
		
	}
}
