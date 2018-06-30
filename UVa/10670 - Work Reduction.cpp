#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int with, need, n;
char z[111];
vector<pair<int, string> > res;

int calc(int A, int B) {
	int w = with, res = 0;
	while (w != need) {
		int take = (w + 1) >> 1;
		if (w - take >= need) {
			res += min(B, take * A);
			w -= take;
		} else {
			res += (w - need) * A;
			break;
		}
	}
	return res;
}

int main(int argc, char **argv) {
	int t, cas = 1;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%d%d%d", &with, &need, &n);
		res.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", z);
			string s = z;
			res.push_back(make_pair(0, s.substr(0, s.find(':'))));
			int a = atoi(s.substr(s.find(':') + 1, s.find(',') - s.find(':') - 1).c_str());
			int b = atoi(s.substr(s.find(',') + 1).c_str());
			res.back().first = calc(a, b);
		}
		sort(res.begin(), res.end());
		printf("Case %d\n", cas++);
		for (int i = 0; i < n; ++i)
			printf("%s %d\n", res[i].second.c_str(), res[i].first);
	}
	return 0;
}
