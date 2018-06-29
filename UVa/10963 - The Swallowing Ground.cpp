#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, diff, a, b;
		scanf("%d", &n);
		bool can = true;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a, &b);
			int d = abs(a - b);
			if (i != 0 && d != diff)
				can = false;
			diff = d;
		}
		if (can)
			puts("yes");
		else
			puts("no");
		if (t != 0)
			puts("");
	}
	return 0;
}
