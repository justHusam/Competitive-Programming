#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * You got a dream, you gotta protect it.
 */

const int N = 2e6 + 9;
char s[N];
int n;
vector<int> R, D;

int main(int argc, char **argv) {

	while (scanf("%d", &n) > 0 && n != 0) {
		scanf("%s", s);
		bool can = false;
		R.clear();
		D.clear();
		for (int i = 0; i < n && !can; ++i) {
			can |= s[i] == 'Z';
			if (s[i] == 'R')
				R.push_back(i);
			else if (s[i] == 'D')
				D.push_back(i);
		}
		if (can) {
			puts("0");
			continue;
		}
		int res = 2e9;
		for (size_t i = 0; i < R.size(); ++i) {
			int idx = lower_bound(D.begin(), D.end(), R[i]) - D.begin();
			if (idx == (int) D.size())
				res = min(res, R[i] - D.back());
			else {
				res = min(res, D[idx] - R[i]);
				if (idx)
					res = min(res, R[i] - D[idx - 1]);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
