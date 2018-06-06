#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> v(m);
		for (int i = 0; i < m; ++i)
			scanf("%d", &v[i]);
		int mid = n / 2, res = 0;
		if ((n & 1) == 1)
			++mid;
		for (int i = 0; i < m; ++i)
			if (v[i] >= mid)
				++res;
		printf("Case %d: %d\n", k++, res);
	}
	return 0;
}
