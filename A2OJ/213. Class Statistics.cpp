#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

int main(int argc, char **argv) {
	int t, k = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		int res = 0;
		sort(v.begin(), v.end());
		for (int i = 1; i < n; ++i)
			res = max(res, v[i] - v[i - 1]);
		printf("Class %d\n", k++);
		printf("Max %d, Min %d, Largest gap %d\n", v.back(), v[0], res);
	}
	return 0;
}
