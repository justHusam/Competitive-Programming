import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	static final int N = 1001;
	static BigInteger[] dp = new BigInteger[N];

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok;
		String line;
		dp[0] = BigInteger.ONE;
		for (int i = 1; i < N; ++i)
			dp[i] = dp[i - 1].multiply(BigInteger.valueOf(2 * i * (2 * i - 1))).divide(BigInteger.valueOf(i * (i + 1)));
		while ((line = in.readLine()) != null) {
			int n = Integer.parseInt(line);
			out.write(dp[n] + "\n");
		}
		out.flush();
	}

}