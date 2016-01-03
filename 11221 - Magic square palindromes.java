/**
	UVa 11221 - Magic square palindromes
	by Rico Tiongson
	Submitted: November 3, 2013
	Accepted 0.402s Java
	O(4n) time
*/
import java.util.*;
import java.io.*;
public class Main {
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		int tc = 0;
		int t = Integer.parseInt( br.readLine() );
		while( t-- != 0 ){
			String in = br.readLine();
			StringBuilder sb = new StringBuilder();
			for( int i=0; i<in.length(); ++i ){
				if( Character.isLowerCase( in.charAt(i) ) )
					sb.append( in.charAt(i) );
			}
			pw.println( "Case #" + (++tc) + ":" );
			double sqrt = Math.sqrt( sb.length() );
			if( Math.abs(Math.ceil(sqrt) - Math.floor(sqrt)) > 1e-7 ){
				pw.println( "No magic :(" );
				continue;
			}
			if( !isPalindrome( sb.toString() ) ){
				pw.println( "No magic :(" );
				continue;
			}
			int size = (int)sqrt;
			char[] array = new char[sb.length()];
			for( int i=0; i<size; ++i ){
				for( int j=0; j<size; ++j ){
					array[j*size + i] = sb.charAt( i*size + j );
				}
			}
			if( isPalindrome( new String(array) ) ){
				pw.println( size );
			}
			else
				pw.println( "No magic :(" );
		}
		pw.close();
	}
	static boolean isPalindrome( String s ){
		for( int i=0, j=s.length()-1; i<j; ++i, --j ){
			if( s.charAt(i) != s.charAt(j) )
				return false;
		}
		return true;
	}
}
