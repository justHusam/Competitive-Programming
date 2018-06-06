#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		string s;
		ll m, k;
		cin >> s >> m >> k;
		while (k-- != 0) {
			string x;
			ll t;
			cin >> x >> t;
			if (x == "buy")
				m -= t;
			else
				m += t;
		}
		cout << s << " " << m << endl;
	}
	return 0;
}
