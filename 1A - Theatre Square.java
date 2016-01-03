/**
	CodeForces 1A - Theatre Square
	by Rico Tiongson
	Submitted: November 22, 2013
	Accepted 0.124s Java 7
	O(1) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String[] sp = br.readLine().trim().split( "\\s+" );
		long n, m, a;
		
		n = Long.parseLong( sp[0] );
		m = Long.parseLong( sp[1] );
		a = Long.parseLong( sp[2] );
		
		long diva = (n / a) + (n % a != 0 ? 1 : 0);
		long divb = (m / a) + (m % a != 0 ? 1 : 0);
		pw.println( BigInteger.valueOf(diva).multiply( BigInteger.valueOf(divb) ) );
		
		pw.close();
	}
}