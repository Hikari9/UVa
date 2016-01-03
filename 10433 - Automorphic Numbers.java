/**
	UVa 10433 - Automorphic Numbers
	by Rico Tiongson
	Submitted: August 31, 2013
	Accepted 2.032s Java
	O(n^2) time
*/
import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		String a;
		BigInteger x;
		while( (a=br.readLine())!=null ){
			x = new BigInteger(a);
			if( x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE) ){
				pw.println("Not an Automorphic number.");
				continue;
			}
			x = x.pow(2);
			if( x.toString().endsWith(a) )
				pw.printf("Automorphic number of %d-digit.\n",a.length());
			else
				pw.println("Not an Automorphic number.");
		}
		pw.close();
	}
}
