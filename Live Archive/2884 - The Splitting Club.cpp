#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 121;
int n, freq[N];
double r;
vector<int> v;

int main(int argc, char **argv) {
	while (scanf("%d%lf", &n, &r) && n != 0) {
		memset(freq, 0, sizeof freq);
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			freq[b] += a;
		}
		v.clear();
		for (int i = 1; i < N; ++i)
			if (freq[i] != 0)
				v.push_back(freq[i]);
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < n; ++i) {
			++res;
			int at = i + 1;
			while (at < n && v[i] * r >= v[at])
				++at;
			i = at - 1;
		}
		printf("%d\n", res);
	}
	return 0;
}
