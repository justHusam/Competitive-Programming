#include <bits/stdc++.h>
using namespace std;

int n, c;
long long A[10], B[10];
vector<int> v;

inline int calc() {
	int res = 0;
	long long with = c;
	for (int i = 0; i < n; ++i) {
		if (A[v[i]] > with)
			break;
		++res;
		with -= A[v[i]];
		with += B[v[i]];
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d", &n, &c);
		v.clear();
		for (int i = 0; i < n; ++i)
			cin >> A[i] >> B[i];
		for (int i = 0; i < n; ++i)
			v.push_back(i);
		int res = 0;
		do {
			res = max(res, calc());
		} while (next_permutation(v.begin(), v.end()));
		cout << res << endl;
	}
	return 0;
}
