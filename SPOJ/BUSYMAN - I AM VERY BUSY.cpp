#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n;
pair<int, int> v[N];

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &v[i].second, &v[i].first);
		sort(v, v + n);
		int res = 1, end = v[0].first;
		for (int i = 1; i < n; ++i) {
			int at = i;
			while (at < n && v[at].second < end)
				++at;
			if (at != n) {
				++res;
				end = v[at].first;
			}
			i = at;
		}
		printf("%d\n", res);
	}
	return 0;
}
