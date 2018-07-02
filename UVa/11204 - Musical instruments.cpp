#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, m, freq[36] = { }, res = 1;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i)
			for (int j = 0, x; j < n; ++j) {
				scanf("%d", &x);
				if (x == 1)
					++freq[j];
			}
		for (int i = 0; i < n; ++i)
			if (freq[i] != 0)
				res *= freq[i];
		printf("%d\n", res);
	}
	return 0;
}
