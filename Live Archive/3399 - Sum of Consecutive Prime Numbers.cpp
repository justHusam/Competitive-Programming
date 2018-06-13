#include <bits/stdc++.h>
using namespace std;

const int N = 30001;
bitset<N> bs;
vector<int> p, cum;
int n;

int main(int argc, char **argv) {
	bs[0] = bs[1] = 1;
	for (int i = 2; i * i < N; ++i)
		if (!bs[i])
			for (int j = i * i; j < N; j += i)
				bs[j] = 1;
	for (int i = 0; i < N; ++i)
		if (!bs[i])
			p.push_back(i);
	cum.push_back(p[0]);
	for (int i = 1; i < p.size(); ++i)
		cum.push_back(cum.back() + p[i]);
	while (scanf("%d", &n) && n != 0) {
		int res = 0;
		for (int i = 0; i < p.size() && p[i] <= n; ++i) {
			int v = (i > 0) ? cum[i - 1] : 0;
			int k = lower_bound(cum.begin(), cum.end(), v + n) - cum.begin();
			if (k < cum.size() && v + n == cum[k])
				++res;
		}
		printf("%d\n", res);
	}
	return 0;
}
