#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 101;
char a[N], b[N];
int n, m, freq[26];
vector<char> v;
vector<string> sol;

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s%s", a, b);
		memset(freq, 0, sizeof freq);
		n = strlen(a);
		m = strlen(b);
		for (int i = 0; i < n; ++i)
			++freq[a[i] - 'a'];
		v.clear();
		int bad = 0, len = n;
		for (int i = 0; i < m; ++i) {
			int x = b[i] - 'a';
			if (freq[x] > 0) {
				len -= freq[x];
				freq[x] = -1;
			} else if (freq[x] == 0) {
				++bad;
				v.push_back(b[i]);
			}
			if (bad == 6 || len == 0)
				break;
		}
		sol.clear();
		sol.push_back("+=======" + string(n << 1, '=') + "+"); //  0
		sol.push_back("|Word:  " + string(n << 1, ' ') + '|'); //  1
		sol.push_back("|Misses:" + string(n << 1, ' ') + '|'); //  2
		sol.push_back("|  +===+" + string(n << 1, ' ') + '|'); //  3
		sol.push_back("|  |   |" + string(n << 1, ' ') + '|'); //  4
		sol.push_back("|      |" + string(n << 1, ' ') + '|'); //  5
		sol.push_back("|      |" + string(n << 1, ' ') + '|'); //  6
		sol.push_back("|      |" + string(n << 1, ' ') + '|'); //  7
		sol.push_back("|      |" + string(n << 1, ' ') + '|'); //  8
		sol.push_back("|=======" + string(n << 1, ' ') + '|'); //  9
		sol.push_back("+=======" + string(n << 1, '=') + "+"); // 10
		if (bad >= 1)
			sol[5][3] = 'O';
		if (bad >= 2)
			sol[6][3] = '|';
		if (bad >= 3)
			sol[6][2] = '/';
		if (bad >= 4)
			sol[6][4] = '\\';
		if (bad >= 5)
			sol[7][2] = '/';
		if (bad >= 6)
			sol[7][4] = '\\';
		int pos = 8;
		for (int i = 0; i < n; ++i) {
			if (freq[a[i] - 'a'] != -1)
				sol[1][pos] = '*';
			else
				sol[1][pos] = a[i];
			pos += 2;
		}
		pos = 9;
		for (int i = 0; i < v.size(); ++i) {
			if (i != 0)
				sol[2][pos++] = ',';
			sol[2][pos++] = v[i];
		}
		for (int i = 0; i < sol.size(); ++i)
			puts(sol[i].c_str());
		if (t != 0)
			puts("");
	}
	return 0;
}
