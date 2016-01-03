/**
	CodeForces 281A - Word Capitalization
	by Rico Tiongson
	Submitted: November 22, 2013
	Accepted 0.124s Java 7
	O(1) time
*/
import java.util.*;
import java.io.*;

public class Main {
	public static void main( String args[] ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
		
		char c = (char)br.read();
		pw.print( Character.toUpperCase(c) );
		pw.println( br.readLine() );
		
		pw.close();
	}
}