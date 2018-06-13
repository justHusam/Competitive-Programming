#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[12];

bool checl(int s, int e) {
	ll x = a[s - 1], y = a[e + 1];
	for (int i = s; i <= e; ++i)
		if (a[i] <= x || a[i] <= y)
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int cas;
		scanf("%d", &cas);
		for (int i = 0; i < 12; ++i)
			scanf("%d", &a[i]);
		int res = 0;
		for (int i = 1; i < 11; ++i)
			for (int j = i; j < 11; ++j)
				res += checl(i, j);
		printf("%d %d\n", cas, res);
	}
	return 0;
}
