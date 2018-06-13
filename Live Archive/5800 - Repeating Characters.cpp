#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string s, res;
	int T, csNum, n;
	cin >> T;
	while (T-- != 0) {
		string res = "";
		cin >> csNum >> n >> s;
		for (size_t i = 0; i < s.length(); ++i)
			for (int j = 1; j <= n; ++j)
				res += s[i];
		cout << csNum << " " << res << endl;
	}
	return 0;
}
