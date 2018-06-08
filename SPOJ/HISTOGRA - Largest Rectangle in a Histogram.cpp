#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, h[N], l[N], r[N];
vector<int> st;

int main(int argc, char **argv) {
	while (scanf("%d", &n) && n != 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &h[i]);
		st.clear();
		for (int i = 0; i < n; ++i) {
			while (!st.empty() && h[st.back()] >= h[i])
				st.pop_back();
			l[i] = st.empty() ? -1 : st.back();
			st.push_back(i);
		}
		st.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && h[st.back()] >= h[i])
				st.pop_back();
			r[i] = st.empty() ? n : st.back();
			st.push_back(i);
		}
		ll res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, (ll) h[i] * (r[i] - l[i] - 1));
		printf("%lld\n", res);
	}
	return 0;
}

