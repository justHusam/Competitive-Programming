#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double p[] = { 0, 0.1, 0.15, 0.2, 0.25 };
int m[] = { 180000, 300000, 400000, 300000, 2000000000 };

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int k;
		scanf("%d", &k);
		double res = 0;
		for (int i = 0; i < 5; ++i) {
			res += p[i] * min(k, m[i]);
			k -= min(k, m[i]);
		}
		if (res > 0)
			res = max(res, 2000.0);
		printf("Case %d: %d\n", cas++, (int) ceil(res));
	}
	return 0;
}
