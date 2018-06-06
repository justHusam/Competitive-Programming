#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e6 + 1;
int n, m, c[100];
bool can[N];

int main(int argc, char **argv) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= m; j += c[i])
			can[j] = true;
	int res = 0;
	for (int i = 1; i <= m; ++i)
		res += can[i];
	printf("%d\n", res);
	return 0;
}
