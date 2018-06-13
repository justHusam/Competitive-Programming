#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], p[100];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			p[i] = i;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (abs(a[i] - a[j]) <= k)
					p[find(i)] = find(j);
		int comp = 0;
		for (int i = 0; i < n; ++i)
			if (find(i) == i)
				++comp;
		printf("Case #%d: %d\n", cas++, comp);
	}
	return 0;
}
