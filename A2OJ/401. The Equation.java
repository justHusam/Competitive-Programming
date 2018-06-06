import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer strtok;
		int t = Integer.parseInt(in.readLine()), k = 1;
		while (t-- > 0) {
			strtok = new StringTokenizer(in.readLine());
			int x = Integer.parseInt(strtok.nextToken());
			int n = Integer.parseInt(strtok.nextToken());
			int y = Integer.parseInt(strtok.nextToken());
			BigDecimal res = BigDecimal.ONE;
			for (int i = 1; i <= n; ++i)
				res = res.add(calc(x, i, y));
			System.out.println("Case " + (k++) + ":\n" + res);
		}
	}

	static String a, b, c;

	static BigDecimal calc(int x, int n, int y) {
		a = x + "";
		b = n + "";
		c = (y - n) + "";
		return ((new BigDecimal(a)).pow(n).add(new BigDecimal(b))).divide(new BigDecimal(c));
	}
}