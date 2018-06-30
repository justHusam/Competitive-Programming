import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	static final int N = 301;
	static BigInteger[] fact = new BigInteger[N];
	static BigInteger[] dp = new BigInteger[N];

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok;
		String line;
		dp[0] = fact[0] = BigInteger.ONE;
		for (int i = 1; i < N; ++i)
			dp[i] = dp[i - 1].multiply(BigInteger.valueOf(2 * i * (2 * i - 1))).divide(BigInteger.valueOf((i + 1) * i));
		while (true) {
			int n = Integer.parseInt(in.readLine());
			if (n == 0)
				break;
			out.write(dp[n].multiply(fact[n]) + "\n");
		}
		out.flush();
	}

}