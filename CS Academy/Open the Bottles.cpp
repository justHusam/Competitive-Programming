#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int res = 0;
	for (int i = 0; i < 3; ++i) {
		int mn = 1e9;
		for (int j = 0, x; j < 3; ++j) {
			scanf("%d", &x);
			mn = min(mn, x);
		}
		res += mn;
	}
	printf("%d\n", res);
	return 0;
}
