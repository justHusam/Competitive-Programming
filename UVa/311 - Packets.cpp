#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

ll v[7];

ll calc6() {
	return v[6];
}

ll calc5() {
	v[1] -= min(v[1], 11 * v[5]);
	return v[5];
}

ll calc4() {
	ll w = v[4] * 20;
	ll x = min(v[2], w / 4);
	v[2] -= x;
	w -= x * 4;
	v[1] -= min(v[1], w);
	return v[4];
}

ll calc3() {
	ll res = v[3] / 4, mod = v[3] % 4;
	if (mod != 0) {
		++res;
		ll w = 36 - mod * 9, x;
		if (mod == 3)
			x = min(v[2], 1LL);
		else if (mod == 2)
			x = min(v[2], 3LL);
		else
			x = min(v[2], 5LL);
		w -= x * 4;
		v[2] -= x;
		v[1] -= min(v[1], w);
	}
	return res;
}

ll calc2() {
	ll res = v[2] / 9;
	if (v[2] % 9) {
		++res;
		v[1] -= min(v[1], 36 - (v[2] % 9) * 4);
	}
	return res;
}

ll calc1() {
	return v[1] / 36 + (v[1] % 36 != 0);
}

ll calc() {
	ll res = 0;
	res += calc6();
	res += calc5();
	res += calc4();
	res += calc3();
	res += calc2();
	res += calc1();
	return res;
}

int main(int argc, char **argv) {
	while (true) {
		ll all = 0;
		for (int i = 1; i < 7; ++i) {
			scanf("%lld", v + i);
			all += v[i];
		}
		if (all == 0)
			break;
		printf("%lld\n", calc());
	}
	return 0;
}
