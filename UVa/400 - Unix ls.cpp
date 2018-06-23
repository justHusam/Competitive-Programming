#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (cin >> n) {
		int mx = 0;
		cin.ignore();
		vector<string> v(n);
		for (int i = 0; i < n; ++i) {
			getline(cin, v[i]);
			mx = max(mx, (int) v[i].size());
		}
		sort(v.begin(), v.end());
		int C = 62 / (mx + 2);
		int R = ceil(n / (double) C);
		for (size_t i = 0; i < v.size(); ++i)
			for (int j = v[i].length(); j < mx + 2; j++)
				v[i] += ' ';
		cout << "------------------------------------------------------------\n";
		for (int i = 0; i < R; i++) {
			for (int j = 1, k = 0; j <= C && k + i < v.size(); j++, k += R)
				cout << v[i + k];
			cout << endl;
		}
	}
	return 0;
}
