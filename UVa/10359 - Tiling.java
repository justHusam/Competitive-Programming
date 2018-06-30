import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	static final int N = 251;
	static BigInteger[] dp = new BigInteger[N];

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok;
		String line;
		dp[0] = dp[1] = BigInteger.ONE;
		dp[2] = BigInteger.valueOf(3);
		for (int i = 3; i < N; ++i)
			dp[i] = dp[i - 1].add(dp[i - 2].shiftLeft(1));
		while ((line = in.readLine()) != null) {
			int n = Integer.parseInt(line);
			out.write(dp[n] + "\n");
		}
		out.flush();
	}

}