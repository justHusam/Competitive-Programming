#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, cas = 1;
	while (scanf("%d", &n) > 0 && n != 0) {
		long long res = 0;
		for (int i = 1; i <= n; ++i) {
			int rem = n - i;
			int mnG = i + 1;
			int mxR = i - 1;
			if (mxR <= 0 || mnG + i + 1 > n)
				continue;
			int canR = min(mxR, rem - mnG);
			int canG = rem - canR;
			if (canR <= 0 || canR >= i || canG <= 0 || canG <= i)
				continue;
			res += min(canR, rem - canG);
		}
		printf("Case %d: %lld\n", cas++, res);
	}
	return 0;
}
