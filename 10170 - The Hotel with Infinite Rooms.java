/**
	UVa 10170 - The Hotel with Infinite Rooms
	by Rico Tiongson
	Submitted: November 2, 2013
	Accepted 0.995s Java
	O(1) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	static long f( int x ){
		return BigInteger.valueOf(x).multiply( BigInteger.valueOf(x-1) ).shiftRight(1).longValue();
	}
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		String in, sp[];
		int S;
		long D;
		while( (in = br.readLine()) != null ){
			sp = in.trim().split( "\\s+" );
			S = Integer.parseInt( sp[0] );
			D = Long.parseLong( sp[1] );
			long C = -2L * ( D + f(S) - 1L );
			double x = ( 1.0 + Math.sqrt( 1 - 4.0 * C ) ) / 2.0;
			pw.println( (int)( Math.floor(x) + 1e-7 ) );
		}
		
		pw.close();
	}
}