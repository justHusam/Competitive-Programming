#include<bits/stdc++.h>
using namespace std;

int all[6][3] = { { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 }, { 1, 2, 0 }, { 2, 0, 1 }, { 2, 1, 0 } };
int p, q, r, s, x[3], y[3];
vector<int> v[2];

int main(int argc, char **argv) {
	while (scanf("%d%d%d%d", &p, &q, &r, &s) > 0) {
		x[0] = p, x[1] = s, x[2] = r - s;
		y[0] = q, y[1] = r, y[2] = p - q;
		int best = 2e9, I, J;
		for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 6; ++j) {
				int n = 0, m = 0;
				for (int k = 0; k < 3; ++k) {
					if (x[all[i][k]] > y[all[j][k]])
						n += x[all[i][k]] - y[all[j][k]];
					else
						m += y[all[j][k]] - x[all[i][k]];
				}
				if (abs(n - m) < best)
					best = abs(n - m), I = i, J = j;
			}
		v[0].clear(), v[1].clear();
		int with[2] = { };
		for (int i = 0; i < 3; ++i) {
			int n = x[all[I][i]], m = y[all[J][i]], mx = max(n, m), def = abs(n - m), idx = !(n > m);
			while (def-- != 0) {
				v[idx].push_back(mx--);
				if (v[idx].back() != 1)
					++with[idx];
			}
		}
		for (size_t i = 0; i < v[0].size() && with[0] != 0; ++i)
			for (size_t j = 0; j < v[1].size() && with[1] != 0; ++j) {
				int g = __gcd(v[0][i], v[1][j]);
				if (g == 1)
					continue;
				v[0][i] /= g;
				v[1][j] /= g;
				if (v[1][j] == 1)
					--with[1];
				if (v[0][i] == 1) {
					--with[0];
					break;
				}
			}
		long double res[2] = { 1, 1 };
		for (int i = 0; i < 2; ++i)
			for (size_t j = 0; j < v[i].size() && with[i] != 0; ++j) {
				res[i] *= (long double) v[i][j];
				if (v[i][j] != 1)
					--with[i];
			}
		cout << fixed << showpoint << setprecision(5) << res[0] / res[1] << "\n";
	}
	return 0;
}
