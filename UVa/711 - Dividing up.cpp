#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[7], cum[7];
short vis[360001][6], vs;

bool calc(int i, int w) {
	if (w == 0)
		return true;
	if (w < 0 || i == 7 || w - cum[6] - cum[i - 1] > 0)
		return false;
	if (vis[w][i] == vs)
		return false;
	vis[w][i] = vs;
	bool res = false;
	for (int j = 0; j <= a[i] && !res; ++j)
		res |= calc(i + 1, w - j * i);
	return res;
}

int main(int argc, char **argv) {
	int cas = 1;
	while (true) {
		int sum = 0;
		for (int i = 1; i <= 6; ++i) {
			scanf("%d", &a[i]);
			sum += a[i] * i;
			cum[i] = cum[i - 1] + a[i] * i;
		}
		if (sum == 0)
			break;
		++vs;
		printf("Collection #%d:\n", cas++);
		if (sum % 2 == 0 && calc(0, sum / 2))
			puts("Can be divided.\n");
		else
			puts("Can't be divided.\n");
	}
	return 0;
}
