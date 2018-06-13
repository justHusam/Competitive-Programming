#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	vector<int> v;
	for (int i = 1;; ++i) {
		if (i * (i + 1) / 2 > 1000)
			break;
		v.push_back(i * (i + 1) / 2);
	}
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		int k;
		scanf("%d", &k);
		int can = 0;
		for (size_t i = 0; i < v.size() && !can; ++i)
			for (size_t j = i; j < v.size() && !can; ++j) {
				int rem = k - v[i] - v[j];
				if (rem <= 0)
					break;
				if (binary_search(v.begin(), v.end(), rem))
					can = 1;
			}
		printf("%d\n", can);
	}
	return 0;
}
