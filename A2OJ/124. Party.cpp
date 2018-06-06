#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int d, n;
		scanf("%d%d", &d, &n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		sort(v.rbegin(), v.rend());
		int res = 0, day = 1;
		for (int i = 0; i < n; ++i) {
			if (day + v[i] + 1 > d)
				continue;
			++day;
			++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
