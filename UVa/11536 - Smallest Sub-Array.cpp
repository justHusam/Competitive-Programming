#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k, a[1000001], freq[1001];

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &n, &m, &k);
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		for (int i = 3; i < n; ++i)
			a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
		memset(freq, 0, sizeof freq);
		queue<int> qu;
		int res = 2e9, sz = 0;
		for (int i = 0; i < n; ++i) {
			qu.push(a[i]);
			if (a[i] <= k && !freq[a[i]])
				++sz;
			++freq[a[i]];
			while (sz == k) {
				res = min(res, (int) qu.size());
				int fr = qu.front();
				qu.pop();
				--freq[fr];
				if (fr <= k && !freq[fr])
					--sz;
			}
		}
		printf("Case %d: ", cas++);
		if (res == 2e9)
			puts("sequence nai");
		else
			printf("%d\n", res);
	}
	return 0;
}
