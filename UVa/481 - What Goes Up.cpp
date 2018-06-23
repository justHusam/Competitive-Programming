#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> a, v, p, idx;

int main(int argc, char **argv) {
	int x;
	while (scanf("%d", &x) > 0)
		a.push_back(x);
	int n = a.size();
	p.resize(n, -1);
	idx.resize(n, -1);
	idx[0] = 0;
	v.push_back(a[0]);
	for (int i = 1; i < n; ++i) {
		if (a[i] < v[0])
			idx[0] = i;
		else if (a[i] > v.back()) {
			p[i] = idx[v.size() - 1];
			idx[v.size()] = i;
			v.push_back(a[i]);
		} else {
			int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			p[i] = idx[pos - 1];
			idx[pos] = i;
			v[pos] = a[i];
		}
	}
	vector<int> res;
	for (int i = idx[v.size() - 1]; i != -1; i = p[i])
		res.push_back(a[i]);
	reverse(res.begin(), res.end());
	printf("%d\n-\n", (int) res.size());
	for (size_t i = 0; i < res.size(); ++i)
		printf("%d\n", res[i]);
	return 0;
}
