#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int O = 1e5;
int n, a[10000], freq[200001];
pair<ll, int> nxt[200001], prv[200001];

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		memset(freq, 0, sizeof freq);
		int mn = 2e9, mx = -2e9;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			++freq[a[i] + O];
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}
		prv[mn + O] = make_pair(0, freq[mn + O]);
		for (int i = mn + 1; i <= mx; ++i) {
			prv[i + O].first = prv[i - 1 + O].first + prv[i - 1 + O].second;
			prv[i + O].second = prv[i - 1 + O].second + freq[i + O];
		}
		nxt[mx + O] = make_pair(0, freq[mx + O]);
		for (int i = mx - 1; i >= mn; --i) {
			nxt[i + O].first = nxt[i + 1 + O].first + nxt[i + 1 + O].second;
			nxt[i + O].second = nxt[i + 1 + O].second + freq[i + O];
		}
		ll need = -1;
		for (int i = mn; i <= mx; ++i) {
			ll back = prv[i + O].first;
			ll front = nxt[i + O].first;
			if (back == front && (need == -1 || (front + 1 < need)))
				need = front + 1;
		}
		printf("%lld\n", need);
	}
	return 0;
}
