#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		if (n <= 1 || m <= 1) {
			puts("Boring!");
			continue;
		}
		int x = 1;
		vector<int> res;
		for (; x < n; x *= m)
			res.push_back(x);
		if (x == n) {
			printf("%d", n);
			for (int i = res.size() - 1; i >= 0; --i)
				printf(" %d", res[i]);
			puts("");
		} else
			puts("Boring!");
	}
	return 0;
}
