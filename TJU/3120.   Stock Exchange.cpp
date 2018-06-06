#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[100000];
vector<int> v;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		if (n == 0) {
			puts("0");
			continue;
		}
		v.clear();
		v.push_back(a[0]);
		for (int i = 1; i < n; ++i)
			if (a[i] > v.back())
				v.push_back(a[i]);
			else
				v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
		printf("%d\n", (int) v.size());
	}
	return 0;
}
