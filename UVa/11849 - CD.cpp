#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		if (n == 0 && m == 0)
			break;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int res = 0;
		for (int i = 0, x; i < m; ++i) {
			scanf("%d", &x);
			if (binary_search(v.begin(), v.end(), x))
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
