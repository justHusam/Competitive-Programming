#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n;
		scanf("%d", &n);
		vector<int> v1(n), v2;
		for (int i = 0; i < n; ++i)
			scanf("%d", &v1[i]);
		v2 = v1;
		sort(v2.begin(), v2.end());
		int res = 0;
		for (int i = 0; i < n; ++i)
			res += (v1[i] == v2[i]);
		printf("%d\n", res);
	}
	return 0;
}
