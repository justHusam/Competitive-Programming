#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e7 + 1;
vector<int> p;
bitset<N> bs;

int main(int argc, char **argv) {
	for (int i = 3; i * i < N; i += 2)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	p.push_back(2);
	for (int i = 3; i < N; i += 2)
		if (!bs[i])
			p.push_back(i);
	int n;
	while (scanf("%d", &n) > 0) {
		int a[4] = { };
		for (size_t i = 0; i < p.size() && p[i] <= n; ++i) {
			int rem = n - p[i] - 4;
			int k = lower_bound(p.begin(), p.end(), rem) - p.begin();
			if (k != (int) p.size() && p[k] == rem) {
				a[0] = a[1] = 2;
				a[2] = p[i];
				a[3] = rem;
				break;
			}
			rem = n - p[i] - 5;
			k = lower_bound(p.begin(), p.end(), rem) - p.begin();
			if (k != (int) p.size() && p[k] == rem) {
				a[0] = 2;
				a[1] = 3;
				a[2] = p[i];
				a[3] = rem;
				break;
			}
		}
		if (a[0] == 0)
			puts("Impossible.");
		else
			printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
	}
	return 0;
}
