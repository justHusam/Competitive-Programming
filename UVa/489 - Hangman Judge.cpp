#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

char x[1111], y[1111];

string calc() {
	int f[26] = { }, vis[26] = { };
	for (int i = 0; x[i]; ++i)
		++f[x[i] - 'a'];
	int all = strlen(x), w = 0;
	for (int i = 0; y[i] && w < 7 && all; ++i)
		if (!vis[y[i] - 'a']) {
			vis[y[i] - 'a'] = true;
			w += !f[y[i] - 'a'];
			all -= f[y[i] - 'a'];
		}
	if (w == 7)
		return "You lose.";
	if (all == 0)
		return "You win.";
	return "You chickened out.";
}

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != -1) {
		scanf("%s%s", x, y);
		printf("Round %d\n%s\n", n, calc().c_str());
	}
	return 0;
}
