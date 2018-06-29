#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int n, b, a[100];
	while (scanf("%d%d", &n, &b) > 0 && (n != 0 && b != 0)) {
		for (int i = 0; i < b; ++i)
			scanf("%d", &a[i]);
		bool can[100] = {};
		for (int i = 0; i < b; ++i)
			for (int j = i; j < b; ++j)
				can[abs(a[i] - a[j])] = true;
		bool ok = true;
		for (int i = 0; i <= n && ok; ++i)
			ok &= can[i];
		if (ok)
			puts("Y");
		else
			puts("N");
	}
}
