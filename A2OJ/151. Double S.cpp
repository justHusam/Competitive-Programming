#include <bits/stdc++.h>
using namespace std;


int v[10], k, n;

bool calc(int s, int p, int f) {
	if (s == k && f != 0)
		return true;
	if (s > k || p == n)
		return false;
	return calc(s, p + 1, f) || calc(s + v[p], p + 1, 1);
}

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		scanf("%d%d", &k, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		if (calc(0, 0, 0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
