/**
	UVa 11946 - Code Number
	by Rico Tiongson
	Submitted: August 23, 2013
	Accepted 0.172s Java
	O(n) time
*/
import java.util.*;
import java.io.*;
public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		String a, m = "OIZEASGTBP";
		int n = Integer.parseInt( br.readLine() );
		while( n != 0 ){
			while( (a=br.readLine())!=null ){
				if( a.isEmpty() ) break;
				for( int i=0; i<a.length(); ++i ){
					if( Character.isDigit( a.charAt(i) ) )
						pw.print( m.charAt( a.charAt(i)-'0' ) );
					else
						pw.print( a.charAt(i) );
				}
				pw.print('\n');
			}
			if( --n != 0 ) pw.print('\n');
		}
		pw.close();
	}
}
