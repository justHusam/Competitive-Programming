#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool check(string s) {
	int n = s.size();
	for (int i = 0, j = n - 1; i < n / 2; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	while (T-- != 0) {
		int k;
		scanf("%d", &k);
		vector<string> v(k);
		for (int i = 0; i < k; ++i)
			cin >> v[i];
		int ii = -1, jj = -1;
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < k; ++j)
				if (check(v[i] + v[j])) {
					ii = i;
					jj = j;
					i = j = k;
				}
		if (ii == -1)
			puts("0");
		else
			cout << v[ii] + v[jj] << "\n";
	}
	return 0;
}
