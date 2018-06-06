#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, x, y, num = 1;
		scanf("%d%d%d", &n, &x, &y);
		vector<int> sol;
		if (y == 1) {
			while (n-- != 0) {
				if (x == num)
					++num;
				sol.push_back(num++);
			}
		} else {
			if (x <= n) {
				for (int i = 0; i < n; ++i)
					sol.push_back(i + 1);
			} else {
				while (n-- > 1)
					sol.push_back(num++);
				sol.push_back(x);
			}
		}
		for (size_t i = 0; i < sol.size(); ++i)
			printf("%s%d", i ? " " : "", sol[i]);
		puts("");
	}
	return 0;
}
