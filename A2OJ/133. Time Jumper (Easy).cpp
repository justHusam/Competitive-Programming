#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int y, n, v[10];
		scanf("%d%d", &y, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		set<int> st;
		int Max = 1 << n;
		for (int mask = 1; mask < Max; ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				if (((mask >> i) & 1) == 1)
					sum += v[i];
			st.insert(sum);
		}
		set<int>::iterator it;
		for (it = st.begin(); it != st.end(); ++it)
			printf("%d\n", *it + y);
	}
	return 0;
}
