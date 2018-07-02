#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	vector<int> all;
	map<int, int> hs;
	for (int i = 1; i <= 1000; ++i) {
		all.push_back(i * i * i);
		hs[all.back()] = i;
	}
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		int can = false;
		for (size_t i = 0; i < all.size(); ++i)
			if (binary_search(all.begin(), all.end(), n + all[i])) {
				printf("%d %d\n", hs[n + all[i]], hs[all[i]]);
				can = true;
				break;
			}
		if (!can)
			puts("No solution");
	}
	return 0;
}
