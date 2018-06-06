#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		set<int> st;
		for (int i = a; i < n; i += a)
			st.insert(i);
		for (int i = b; i < n; i += b)
			st.insert(i);
		printf("%d %d %d\n%d\n", n, a, b, (int) st.size());
	}
	return 0;
}
