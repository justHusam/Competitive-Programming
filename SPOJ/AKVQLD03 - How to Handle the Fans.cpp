#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
int n, q, BIT[N], a, b;
char s[10];

inline void add(int idx, int val) {
	while (idx < N) {
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

inline int get(int idx) {
	int res = 0;
	while (idx != 0) {
		res += BIT[idx];
		idx -= idx & -idx;
	}
	return res;
}

int main(int argc, char **argv) {
	scanf("%d%d", &n, &q);
	while (q-- != 0) {
		scanf("%s%d%d", s, &a, &b);
		if (s[0] == 'a')
			add(a, b);
		else
			printf("%d\n", get(b) - get(a - 1));
	}
	return 0;
}
