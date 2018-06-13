#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, p;
	while (scanf("%d", &n) && n != 0) {
		scanf("%d", &p);
		vector<int> v;
		if (p % 2 == 0)
			v.push_back(p - 1);
		else
			v.push_back(p + 1);
		int x = p - 1, y = v[0] - 1;
		v.push_back(n - x);
		v.push_back(n - y);
		sort(v.begin(), v.end());
		printf("%d", v[0]);
		for (int i = 1; i < 3; ++i)
			printf(" %d", v[i]);
		puts("");
	}
	return 0;
}
