#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int a, b, c, f, s, t;
	cin >> a >> b >> c;
	if (a >= b && a >= c && b >= c)
		f = c, s = b, t = a;
	else if (a >= b && a >= c && c >= b)
		f = b, s = c, t = a;
	else if (b >= a && b >= c && a >= c)
		f = c, s = a, t = b;
	else if (b >= a && b >= c && c >= a)
		f = a, s = c, t = b;
	else if (c >= a && c >= b && a >= b)
		f = b, s = a, t = c;
	else if (c >= a && c >= b && b >= a)
		f = a, s = b, t = c;
	cout << f << endl << s << endl << t << endl << endl;
	cout << a << endl << b << endl << c << endl;
	return 0;
}
