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
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int s = 0;
		for (int i = 0; i < n; ++i)
			s += v[i];
		int d = 0, r = 0;
		if ((s % n) != 0)
			d = s % n;
		int in = s / n;
		int w = d;
		for (int i = 0; i < n && w; ++i)
			if (v[i] > in) {
				int c = min(v[i] - in, w);
				w -= c;
				v[i] -= c;
			}
		for (int i = 0; i < n; ++i)
			if (v[i] > in)
				r += v[i] - in;
		cout << d << " " << r << "\n";
	}
	return 0;
}
