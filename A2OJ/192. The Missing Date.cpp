#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a += c;
		b += d;
		if (b > 12)
			++a, b %= 12;
		if (!b)
			b = 12;
		cout << a << " " << b << "\n";
	}
	return 0;
}
