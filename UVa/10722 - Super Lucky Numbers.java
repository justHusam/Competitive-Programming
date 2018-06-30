import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer strtok;
		while (true) {
			String line = in.readLine();
			strtok = new StringTokenizer(line);
			int base = Integer.parseInt(strtok.nextToken());
			int n = Integer.parseInt(strtok.nextToken());
			if (base == 0 && n == 0)
				break;
			BigInteger[][] dp = new BigInteger[2][2];
			BigInteger B = BigInteger.valueOf(base - 1);
			dp[0][0] = BigInteger.valueOf(base - 2);
			dp[0][1] = BigInteger.valueOf(1);
			int at = 0;
			for (int i = 1; i < n; ++i) {
				at ^= 1;
				dp[at][1] = dp[at ^ 1][0].add(dp[at ^ 1][1]);
				dp[at][0] = dp[at][1].multiply(B).subtract(dp[at ^ 1][1]);
			}
			System.out.println(dp[at][0].add(dp[at][1]));
		}
	}
}