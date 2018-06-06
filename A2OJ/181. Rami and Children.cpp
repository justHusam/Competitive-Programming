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
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int last, temp;
		while (true) {
			temp = -1;
			for (int i = 0; i < n; ++i) {
				if (v[i] == 0)
					continue;
				v[i] -= min(v[i], m);
				temp = i;
			}
			if (temp == -1)
				break;
			last = temp;
		}
		cout << last + 1 << "\n";
	}
	return 0;
}
