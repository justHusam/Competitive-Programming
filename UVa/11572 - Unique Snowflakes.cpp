#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 1e6;
int v[N], n;

int calc() {
	int res = 1, all = 1, str = 0;
	map<int, int> hs;
	hs[v[0]] = 0;
	for (int i = 1; i < n; ++i) {
		if (hs.find(v[i]) == hs.end() || hs[v[i]] < str)
			hs[v[i]] = i, ++all;
		else {
			all = i - hs[v[i]];
			str = hs[v[i]] + 1;
			hs[v[i]] = i;
		}
		res = max(res, all);
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		printf("%d\n", calc());
	}
	return 0;
}
