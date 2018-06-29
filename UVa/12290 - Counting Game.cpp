#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
	if (n % 7 == 0)
		return true;
	while (n != 0) {
		if (n % 10 == 7)
			return true;
		n /= 10;
	}
	return false;
}

int main(int argc, char **argv) {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) > 0 && n != 0) {
		int x = 1, res = 1, cnt = 0, f = 1;
		while (true) {
			if (x == m && check(res))
				++cnt;
			if (cnt == k)
				break;
			++res;
			if ((f & 1) == 1)
				++x;
			else
				--x;
			if (x == n || x == 1)
				++f;
		}
		printf("%d\n", res);
	}
	return 0;
}
