#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e3;
int n, v[N];

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		sort(v, v + n);
		int res = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				res += n - (lower_bound(v, v + n, v[i] + v[j] + 1) - v);
		printf("%d\n", res);
	}
	return 0;
}
