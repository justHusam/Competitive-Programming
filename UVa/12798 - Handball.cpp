#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int res = 0;
		for (int i = 0; i < n; ++i) {
			int ok = 0;
			for (int j = 0, x; j < m; ++j) {
				scanf("%d", &x);
				if(x > 0)
					++ok;
			}
			if (ok == m)
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}