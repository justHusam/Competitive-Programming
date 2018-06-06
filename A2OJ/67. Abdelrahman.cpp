#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	for (int it = 1; it <= T; ++it) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", it, m - (n - 1));
	}
	return 0;
}
