#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, u, d;
	while (scanf("%d%d%d", &n, &u, &d) && n != 0) {
		int res = 0, pos = 0;
		while (true) {
			++res;
			pos += u;
			if (pos >= n)
				break;
			++res;
			pos -= d;
		}
		printf("%d\n", res);
	}
	return 0;
}
