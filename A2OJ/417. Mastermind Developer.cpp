#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, a[101] = { };
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; j += i)
				a[j] ^= 1;
		int res = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == 0)
				++res;
		printf("%d\n", n - res);
	}
	return 0;
}
