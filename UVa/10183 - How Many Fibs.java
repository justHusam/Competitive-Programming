import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

	static BigInteger max = BigInteger.TEN.pow(100);
	static ArrayList<BigInteger> dp = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		StringTokenizer strtok;
		String line;
		dp.add(BigInteger.valueOf(1));
		dp.add(BigInteger.valueOf(2));
		while (true) {
			int sz = dp.size();
			BigInteger add = dp.get(sz - 1).add(dp.get(sz - 2));
			if (add.compareTo(max) == 1)
				break;
			dp.add(add);
		}
		while ((line = in.readLine()) != null) {
			strtok = new StringTokenizer(line);
			BigInteger l = new BigInteger(strtok.nextToken());
			BigInteger r = new BigInteger(strtok.nextToken());
			if (l.compareTo(BigInteger.ZERO) == 0 && r.compareTo(BigInteger.ZERO) == 0)
				break;
			int res = 0;
			for (int i = 0; i < dp.size(); ++i) {
				if (dp.get(i).compareTo(r) == 1)
					break;
				if (dp.get(i).compareTo(l) != -1)
					++res;
			}
			out.write(res + "\n");
		}
		out.flush();
	}
}