#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		vector<int> sum;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				sum.push_back(v[i] + v[j]);
		sort(sum.begin(), sum.end());
		int q;
		scanf("%d", &q);
		static int k = 1;
		printf("Case %d:\n", k++);
		while (q-- != 0) {
			int x;
			scanf("%d", &x);
			int p = lower_bound(sum.begin(), sum.end(), x) - sum.begin();
			int def1 = abs(x - sum[p]), def2 = 2e9;
			if (p - 1 >= 0)
				def2 = abs(x - sum[p - 1]);
			int res;
			if (def1 < def2)
				res = sum[p];
			else
				res = sum[p - 1];
			printf("Closest sum to %d is %d.\n", x, res);
		}
	}
	return 0;
}
