#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int res = 0;
		for (int i = n; i <= m; ++i) {
			int msk = 0;
			bool ok = true;
			for (int j = i; j != 0 && ok; j /= 10) {
				int d = j % 10;
				if (((msk >> d) & 1) == 1)
					ok = false;
				msk |= 1 << d;
			}
			if (ok)
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
