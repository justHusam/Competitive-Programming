#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, a[N], b[N];
queue<int> qu, w;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		ll best = LLONG_MAX;
		for (int it = 0; it < 2; ++it) {
			for (int i = 0; i < n; ++i)
				b[i] = a[i];
			assert(qu.empty() && w.empty());
			ll need = 0;
			for (int i = 0; i < n; ++i) {
				if (b[i] < 0) {
					b[i] *= -1;
					while (!qu.empty() && b[i] != 0) {
						int can = min(b[i], b[qu.front()]);
						b[i] -= can;
						b[qu.front()] -= can;
						need += can * (i - qu.front());
						if (b[qu.front()] == 0)
							qu.pop();
					}
					if (b[i] > 0)
						w.push(i);
					continue;
				}
				if (b[i] > 0) {
					while (!w.empty() && b[i] != 0) {
						int can = min(b[i], b[w.front()]);
						b[i] -= can;
						b[w.front()] -= can;
						need += can * (i - w.front());
						if (b[w.front()] == 0)
							w.pop();
					}
					if (b[i] > 0)
						qu.push(i);
				}
			}
			best = min(best, need);
			reverse(a, a + n);
		}
		printf("%lld\n", best);
	}
	return 0;
}