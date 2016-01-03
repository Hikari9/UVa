/**
	UVa 11888 - Abnormal 89's
	by Rico Tiongson
	Submitted: October 22, 2013
	Accepted 0.528s Java
	O(n^2/2) time
*/
import java.util.*;
import java.io.*;

public class Main {
	static boolean Palindrome( String s, int st, int ed ){
		while( st < ed ){
			if( s.charAt(st++) != s.charAt(ed--) ) return false;
		}
		return true;
	}
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		int n = Integer.parseInt( br.readLine() );
		
		while( n-- != 0 ){
			String s = br.readLine();
			boolean found = false;
			for( int i=1; i<s.length(); ++i ){
				if( s.charAt(0) == s.charAt(i-1) && s.charAt(i) == s.charAt(s.length()-1) ){
					if( Palindrome(s, 0, i-1) && Palindrome(s, i, s.length()-1 ) ){
						pw.println( "alindrome" );
						found = true;
						break;
					}
				}
			}
			if( !found ){
				if( Palindrome(s, 0, s.length()-1) ) pw.println( "palindrome" );
				else pw.println( "simple" );
			}
		}
		
		pw.close();
	}
}