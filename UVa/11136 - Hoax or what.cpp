#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

multiset<int> st;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		st.clear();
		ll sum = 0;
		for (int i = 0, m, x; i < n; ++i) {
			scanf("%d", &m);
			while (m-- != 0) {
				scanf("%d", &x);
				st.insert(x);
			}
			assert(st.size() >= 2);
			sum += *(--st.end()) - *st.begin();
			st.erase(st.begin());
			st.erase(--st.end());
		}
		printf("%lld\n", sum);
	}
	return 0;
}