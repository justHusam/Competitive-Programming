#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

bool check(int m) {
	int w = n;
	for (int i = 1; i <= m; ++i) {
		if (w % m != 1)
			return false;
		w -= w / m + 1;
	}
	return w % m == 0;
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n >= 0) {
		int res = 0;
		for (int i = 5; i >= 2 && res == 0; --i)
			if (check(i))
				res = i;
		if (res == 0)
			printf("%d coconuts, no solution\n", n);
		else
			printf("%d coconuts, %d people and 1 monkey\n", n, res);
	}
	return 0;
}
