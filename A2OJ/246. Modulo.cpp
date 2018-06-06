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
		set<int> st;
		for (int i = 0, x; i < 10; ++i) {
			scanf("%d", &x);
			st.insert(x % 42);
		}
		printf("%d\n", (int) st.size());
	}
	return 0;
}
