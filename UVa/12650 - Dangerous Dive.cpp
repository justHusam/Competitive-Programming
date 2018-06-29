#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, r;
	while (scanf("%d%d", &n, &r) > 0) {
		const int N = 1e4 + 1;
		bitset<N> bs;
		bs.set();
		set<int> st;
		while (r-- != 0) {
			int x;
			scanf("%d", &x);
			--x;
			bs[x] = 0;
			st.insert(x);
		}
		if ((int) st.size() == n)
			putchar('*');
		else
			for (int i = 0; i < n; ++i)
				if (bs[i])
					printf("%d ", i + 1);
		puts("");
	}
	return 0;
}
