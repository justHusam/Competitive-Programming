#include<bits/stdc++.h>
using namespace std;

const int N = 100;
long long g[N][N];
int n;

bool checkE() {
	int m = n >> 1;
	for (int i = 0, c = n - 1; i < m; ++i, --c)
		for (int j = 0, d = n - 1; j < m; ++j, --d)
			if (g[i][j] != g[c][d])
				return false;
	for (int i = 0, c = n - 1; i < m; ++i, --c)
		for (int j = n - 1, d = 0; j >= m; --j, ++d)
			if (g[i][j] != g[c][d])
				return false;
	return true;
}

bool checkO() {
	int m = n >> 1;
	for (int i = 0, c = n - 1; i < m; ++i, --c)
		for (int j = 0, d = n - 1; j < m; ++j, --d)
			if (g[i][j] != g[c][d])
				return false;
	for (int i = 0, c = n - 1; i < m; ++i, --c)
		for (int j = n - 1, d = 0; j >= m; --j, ++d)
			if (g[i][j] != g[c][d])
				return false;
	for (int i = 0, b = n - 1; i != b; ++i, --b)
		if (g[m][i] != g[m][b] || g[i][m] != g[b][m])
			return false;
	return true;
}

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		char c, cc;
		scanf(" %c %c%d", &c, &cc, &n);
		bool good = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf("%lld", g[i] + j);
				good &= g[i][j] >= 0;
			}
		printf("Test #%d: ", k++);
		if (!good) {
			puts("Non-symmetric.");
			continue;
		}
		if ((n & 1) == 1 && checkO())
			puts("Symmetric.");
		else if ((n & 1) == 0 && checkE())
			puts("Symmetric.");
		else
			puts("Non-symmetric.");
	}
	return 0;
}
