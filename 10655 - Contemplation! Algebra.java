import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	static BigInteger[][] multiply(BigInteger a[][], BigInteger b[][]) {
		int p = a.length;
		int q = a[0].length;
		int r = b[0].length;
		BigInteger ans[][] = new BigInteger[p][r];
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < r; ++j) {
				ans[i][j] = BigInteger.ZERO;
				for (int k = 0; k < q; ++k) {
					ans[i][j] = ans[i][j].add(a[i][k].multiply(b[k][j]));
				}
			}
		return ans;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		String s;
		while ((s = br.readLine()) != null) {
			if (s.equals("0 0")) break;
			String[] sp = s.split(" ");
			int p = Integer.parseInt(sp[0]);
			int q = Integer.parseInt(sp[1]);
			int n = Integer.parseInt(sp[2]);
			BigInteger m[][] = new BigInteger[2][2];
			BigInteger a[][] = new BigInteger[2][2];
			m[0][0] = BigInteger.valueOf(p);
			m[0][1] = BigInteger.valueOf(-1L * q);
			m[1][0] = a[0][0] = a[1][1] = BigInteger.ONE;
			m[1][1] = a[0][1] = a[1][0] = BigInteger.ZERO;
			while (n > 0) {
				if ((n & 1) == 1)
					a = multiply(a, m);
				if ((n >>= 1) != 0)
					m = multiply(m, m);
			}
			pw.println(a[1][0].multiply(BigInteger.valueOf(p)).add(a[1][1].shiftLeft(1)));
		}
		pw.close();
	}
}