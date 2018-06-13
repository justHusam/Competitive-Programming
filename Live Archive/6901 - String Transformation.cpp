#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n;
char a[N], b[N];
set<int> st[2];
set<int>::iterator it;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", a, b);
		n = strlen(a);
		st[0].clear();
		st[1].clear();
		for (int i = 0; i < n; ++i)
			st[a[i] - 'a'].insert(i);
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i])
				continue;
			int need = b[i] - 'a';
			it = st[need].lower_bound(i);
			if (it == st[need].end()) {
				res = -1;
				break;
			}
			res += *it - i;
			a[*it] = a[i];
			st[need].erase(*it);
			st[need ^ 1].insert(*it);
		}
		printf("%lld\n", res);
	}
	return 0;
}
