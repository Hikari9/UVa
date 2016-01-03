/**
	UVa 763 - Fibinary Numbers
	by Rico Tiongson
	Submitted: July 30, 2013
	Accepted 0.665s Java
	O(n) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	public static int i, j;
	public static BigInteger fib[] = new BigInteger[105], ans;
	public static boolean f = false;
	public static String a, b;
	public static StringBuilder sb;
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.valueOf( 2 );
		
		for( i=2; i<fib.length; ++i ){
			fib[i] = fib[i-1].add( fib[i-2] );
		}
		
		while( (a=br.readLine()) != null ){
			if( f ) pw.println();
			else f = true;
			b = br.readLine();
			br.readLine();
			
			ans = parse( a ).add( parse( b ) );
			
			sb = new StringBuilder();
			
			for( i=fib.length-1; i>=0; --i ){
				if( ans.compareTo( fib[i] ) >= 0 ){
					sb.append( '1' );
					ans = ans.subtract( fib[i] );
				}
				else if( sb.length()!=0 ){
					sb.append( '0' );
				}
				
			}
			if( sb.length()==0 ) pw.print( "0\n" );
			else pw.println( sb );
			
		}
		
		pw.close();
	}
	public static BigInteger parse( String x ){
		ans = BigInteger.ZERO;
		for( i=0; i<x.length(); ++i ){
			if( x.charAt( i )=='1' ){
				ans = ans.add( fib[x.length()-i-1] );
			}
		}
		return ans;
	}
}
