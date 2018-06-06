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
		int n;
		scanf("%d", &n);
		map<int, int> hs;
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			++hs[x];
		}
		map<int, int>::iterator it;
		ll s = 0;
		for (it = hs.begin(); it != hs.end(); ++it)
			s += it->second / 4;
		cout << s << "\n";
	}
	return 0;
}
