#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) && n != 0) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		sort(v.begin(), v.end());
		int pos = v.size() - 2;
		for (int i = v.size() - 1; pos >= 0; pos--)
			if (v[pos] < v[i])
				break;
		printf("%d\n", v[pos]);
	}
	return 0;
}
