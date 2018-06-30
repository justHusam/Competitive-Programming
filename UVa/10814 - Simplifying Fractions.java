import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer strtok;
		int t = Integer.parseInt(in.readLine());
		while (t-- != 0) {
			strtok = new StringTokenizer(in.readLine());
			BigInteger a = new BigInteger(strtok.nextToken());
			strtok.nextToken();
			BigInteger b = new BigInteger(strtok.nextToken());
			BigInteger g = a.gcd(b);
			a = a.divide(g);
			b = b.divide(g);
			System.out.println(a + " / " + b);
		}
	}
}