#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll a = n / 3;
		ll b = n - a * 3;
		ll r = a * 20;
		if (b != 0)
			r += 20;
		cout << r << endl;
	}
	return 0;
}
