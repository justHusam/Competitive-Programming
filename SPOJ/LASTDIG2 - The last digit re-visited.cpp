#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[1111];

ll Pow(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = Pow(a, b >> 1);
	res = res * res % 10;
	if ((b & 1) == 1)
		res = res * a % 10;
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		ll b, a = 0;
		scanf("%s%lld", s, &b);
		for (int i = 0; s[i]; ++i)
			a = (a * 10 + (s[i] - '0')) % 10;
		printf("%lld\n", Pow(a, b));
	}
	return 0;
}
