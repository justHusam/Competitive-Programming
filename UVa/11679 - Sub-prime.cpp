#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 20;
int n, m, w[N];

int main(int argc, char **argv) {
	while (scanf("%d%d", &n, &m) > 0 && (n != 0 && m != 0)) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &w[i]);
		int a, b, c;
		bool can = true;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			--a, --b;
			w[a] -= c;
			w[b] += c;
		}
		for (int i = 0; i < n && can; ++i)
			can &= w[i] >= 0;
		if (can)
			puts("S");
		else
			puts("N");
	}
	return 0;
}
