#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n != 0) {
		vector<int> res;
		int w = 0;
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			int need = max(x - w, 0);
			w += need;
			while (need-- != 0)
				res.push_back(i);
		}
		for (size_t i = 0; i < res.size(); ++i)
			printf("%s%d", i ? " " : "", res[i]);
		puts("");
	}
	return 0;
}
