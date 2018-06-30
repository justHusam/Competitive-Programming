import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer strtok;
		while (true) {
			strtok = new StringTokenizer(in.readLine());
			int a[] = new int[4], sum = 0;
			for (int i = 0; i < 4; ++i) {
				a[i] = Integer.parseInt(strtok.nextToken());
				sum += a[i];
			}
			if (sum == 0) {
				break;
			}
			GregorianCalendar cal = new GregorianCalendar(a[3], a[2] - 1, a[1]);
			cal.add(Calendar.DATE, a[0]);
			a[1] = cal.get(Calendar.DATE);
			a[2] = cal.get(Calendar.MONTH) + 1;
			a[3] = cal.get(Calendar.YEAR);
			System.out.println(a[1] + " " + a[2] + " " + a[3]);
		}
	}
}