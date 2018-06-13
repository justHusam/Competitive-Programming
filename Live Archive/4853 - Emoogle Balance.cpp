#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, cas = 1;
	while (scanf("%d", &n) && n != 0) {
		int a = 0, b = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if (x <= 0)
				++a;
			else
				++b;
		}
		printf("Case %d: %d\n", cas++, b - a);
	}
	return 0;
}
