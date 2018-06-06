#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
bool can[N];
int n, m;

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		while (a <= n) {
			can[a] = true;
			a += b;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res += !can[i];
	printf("%d\n", res);
	return 0;
}
