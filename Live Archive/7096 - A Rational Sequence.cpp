#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, lev;
pair<ll, ll> res;

void go(ll a, ll b, bool f) {
	if (!f) {
		res = make_pair(a + b, b);
		--lev;
		res.second = res.second + res.first * lev;
		return;
	}
	if (a == 1 && b == 1) {
		res = make_pair(-1, -1);
		return;
	}
	if (b == 1) {
		lev += a - 1;
		go(1, 1, true);
		return;
	}
	if (a < b) {
		++lev;
		go(a, b - a, false);
	} else {
		lev += a / b;
		go(a % b, b, true);
	}
}

int main(int argc, char **argv) {
	int t, cas;
	scanf("%d", &t);
	while (t-- != 0) {
		char c;
		scanf("%d%lld %c%lld", &cas, &a, &c, &b);
		if (a == 1 && b == 1) {
			printf("%d 1/2\n", cas);
			continue;
		}
		lev = 0;
		go(a, b, true);
		if (res.first == -1)
			res = make_pair(1, lev + 2);
		printf("%d %lld/%lld\n", cas, res.first, res.second);
	}
	return 0;
}
