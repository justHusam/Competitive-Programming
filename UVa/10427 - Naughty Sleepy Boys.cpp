#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e8;
vector<int> v;

int main(int argc, char **argv) {
	v.push_back(0);
	for (int i = 1;; ++i) {
		v.push_back(v.back() + floor(log10(i)) + 1);
		if (v.back() >= N)
			break;
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		int k = lower_bound(v.begin(), v.end(), n) - v.begin();
		int need = v[k] - n;
		while (need != 0) {
			--need;
			k /= 10;
		}
		printf("%d\n", k % 10);
	}
	return 0;
}
