import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok;
		String s;
		while ((s = in.readLine()) != null) {
			int n = Integer.parseInt(s);
			BigInteger dp[] = new BigInteger[n + 1];
			dp[0] = BigInteger.ONE;
			for (int i = 1; i <= n; ++i) {
				dp[i] = BigInteger.ZERO;
				for (int j = 1; j <= 3; ++j)
					if (i - j >= 0) {
						if (j == 1)
							dp[i] = dp[i].add(dp[i - j].shiftLeft(1));
						else
							dp[i] = dp[i].add(dp[i - j]);
					}
			}
			out.write(dp[n] + "\n");
		}
		out.close();
	}
}