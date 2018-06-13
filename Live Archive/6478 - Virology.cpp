#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int freq[10];

bool calc(int at, int x, int y, int sz) {
	if (x == 4 && y == 1 && sz == 0)
		return true;
	if (at == 10 || sz == 0 || sz < (4 - x) + (1 - y) * 2)
		return false;
	bool can = calc(at + 1, x, y, sz);
	if (!can && freq[at] > 1 && y == 0) {
		freq[at] -= 2;
		can |= calc(at + 1, x, y + 1, sz - 2);
		freq[at] += 2;
	}
	if (!can && freq[at] > 2 && x < 4) {
		freq[at] -= 3;
		can |= calc(at + 1, x + 1, y, sz - 3);
		freq[at] += 3;
	}
	if (!can && at < 8 && freq[at] > 0 && freq[at + 1] > 0 && freq[at + 2] > 0 && x < 4) {
		--freq[at];
		--freq[at + 1];
		--freq[at + 2];
		can |= calc(at + 1, x + 1, y, sz - 3);
		++freq[at];
		++freq[at + 1];
		++freq[at + 2];
	}
	if (!can && at > 2 && freq[at] > 0 && freq[at - 1] > 0 && freq[at - 2] > 0 && x < 4) {
		--freq[at];
		--freq[at - 1];
		--freq[at - 2];
		can |= calc(at + 1, x + 1, y, sz - 3);
		++freq[at];
		++freq[at - 1];
		++freq[at - 2];
	}
	if (!can && at > 1 && freq[at] > 0 && freq[at - 1] > 0 && freq[at + 1] > 0 && x < 4) {
		--freq[at];
		--freq[at - 1];
		--freq[at + 1];
		can |= calc(at + 1, x + 1, y, sz - 3);
		++freq[at];
		++freq[at - 1];
		++freq[at + 1];

	}
	return can;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		memset(freq, 0, sizeof freq);
		for (int i = 0, x; i < 14; ++i) {
			scanf("%d", &x);
			++freq[x];
		}
		if (calc(1, 0, 0, 14))
			puts("Vulnerable");
		else
			puts("Immune");
	}
	return 0;
}
