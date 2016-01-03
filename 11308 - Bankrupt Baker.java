/**
	UVa 11308 - Bankrupt Baker
	by Rico Tiongson
	Submitted: August 18, 2013
	Accepted 0.819s Java
	O(nlogn) time
*/
import java.util.*;
import java.io.*;

public class Main{
	public static void main( String args[] ) throws IOException{
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( new OutputStreamWriter( System.out ) );
		
		HashMap<String,Integer> hm = new HashMap<String,Integer>();
		ArrayList<recipeType> re = new ArrayList<recipeType>();
		
		String title, a, s[];
		String recipe;
		int price;
		int t = Integer.parseInt( br.readLine() );
		int m, n, b, i, j, c;
		while( t-->0 ){
			hm.clear();
			title = br.readLine();
			a = br.readLine(); 
			s = a.split(" ");
			m = Integer.parseInt(s[0]);
			n = Integer.parseInt(s[1]);
			b = Integer.parseInt(s[2]);
			for( i=0; i<m; ++i ){
				a = br.readLine();
				s = a.split(" ");
				hm.put( s[0], Integer.parseInt(s[1]) );			
			}
			re.clear();
			for( i=0; i<n; ++i ){
				recipe = br.readLine();
				price = 0;
				m = Integer.parseInt(br.readLine());
				for( j=0; j<m; ++j ){
					a = br.readLine();
					s = a.split(" ");
					if( hm.containsKey(s[0]) )
						price += hm.get(s[0])*Integer.parseInt(s[1]);
				}
				if( price <= b )
					re.add( new recipeType( recipe, price ) );
			}
			Collections.sort(re);
			pw.println( title.toUpperCase() );
			if( re.isEmpty() )
				pw.println( "Too expensive!" );
			else{
				for( i=0; i<re.size(); ++i )
				pw.println( re.get(i).getName() );
			}
			pw.println();
		}
		
		pw.close();
	}
}
class recipeType implements Comparable<recipeType> {
	private int price;
	private String name;
	public recipeType(){price=0;name=new String();}
	public recipeType( String n, int p ){ price=p; name=n; }
	public String getName(){ return name; }
	@Override
	public int compareTo( recipeType b ){
		if( price==b.price )
			return name.compareTo(b.name);
		return price-b.price;
	}
}