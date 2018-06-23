#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
bool vis[N];

int main(int argc, char **argv) {
	int caseN = 1, Z, I, M, L;
	while (scanf("%d%d%d%d", &Z, &I, &M, &L) > 0 && Z + I + M + L != 0) {
		memset(vis, false, sizeof vis);
		int res = 0;
		int cur = (Z * L + I) % M;
		while (!vis[cur]) {
			vis[cur] = true;
			cur = (Z * cur + I) % M;
			++res;
		}
		printf("Case %d: %d\n", caseN, res);
	}
	return 0;
}
