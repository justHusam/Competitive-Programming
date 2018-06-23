#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	vector<int> v;
	map<int, int> hs;
	while (scanf("%d", &n) > 0) {
		if (!hs[n])
			v.push_back(n);
		++hs[n];
	}
	for (size_t i = 0; i < v.size(); ++i)
		printf("%d %d\n", v[i], hs[v[i]]);
	return 0;
}
