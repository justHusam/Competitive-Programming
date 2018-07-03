import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
	static BigInteger dp[][] = new BigInteger[10000][100];
	static String x, y;

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok = new StringTokenizer(in.readLine());
		int T = Integer.parseInt(strtok.nextToken());
		while (T-- != 0) {
			x = in.readLine();
			y = in.readLine();
			for (int i = 0; i < x.length(); ++i)
				for (int j = 0; j < y.length(); ++j)
					dp[i][j] = new BigInteger("-1");
			out.println(calc(0, 0));
		}
		in.close();
		out.close();
	}

	static BigInteger calc(int i, int j) {
		if (j == y.length())
			return new BigInteger("1");
		if (i == x.length())
			return new BigInteger("0");
		if (dp[i][j].compareTo(new BigInteger("-1")) == 1)
			return dp[i][j];
		BigInteger res = calc(i + 1, j);
		if (x.charAt(i) == y.charAt(j))
			res = res.add(calc(i + 1, j + 1));
		return dp[i][j] = res;
	}
}