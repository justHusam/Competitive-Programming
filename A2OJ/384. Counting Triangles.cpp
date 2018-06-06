#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100;
int n, x[N], y[N];

inline bool check(int a, int b, int c) {
	return (y[a] - y[b]) * (x[c] - x[b]) != (y[c] - y[b]) * (x[a] - x[b]);
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k)
					if (check(i, j, k))
						++res;
		printf("Test case #%d: %d triangle(s) can be formed.\n\n", cas++, res);
	}
	return 0;
}
