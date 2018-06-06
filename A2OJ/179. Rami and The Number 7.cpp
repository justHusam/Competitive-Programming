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
		ll n;
		cin >> n;
		ll g = __gcd(n, 7LL);
		ll m = n * 7;
		cout << m / g << "\n";
	}
	return 0;
}
