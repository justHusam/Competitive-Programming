#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
pair<double, int> res[N];

int main(int argc, char **argv) {
	int t;
	bool newLine = false;
	scanf("%d", &t);
	while (t-- != 0) {
		if (newLine)
			puts("");
		newLine = true;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			res[i] = make_pair(1.0 * x / y, i + 1);
		}
		sort(res, res + n);
		for (int i = 0; i < n; ++i)
			printf("%s%d", i ? " " : "", res[i].second);
		puts("");
	}
	return 0;
}
