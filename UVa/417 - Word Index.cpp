#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

map<string, int> hs;
vector<string> g[10];
char s[111];

int main(int argc, char **argv) {
	for (char i = 'a'; i <= 'z'; ++i) {
		string A = "";
		A += i;
		g[A.size()].push_back(A);
		for (char j = i + 1; j <= 'z'; ++j) {
			string B = A + j;
			g[B.size()].push_back(B);
			for (char k = j + 1; k <= 'z'; ++k) {
				string C = B + k;
				g[C.size()].push_back(C);
				for (char l = k + 1; l <= 'z'; ++l) {
					string D = C + l;
					g[D.size()].push_back(D);
					for (char e = l + 1; e <= 'z'; ++e) {
						string E = D + e;
						g[E.size()].push_back(E);
					}
				}
			}
		}
	}
	for (int i = 1; i < 6; ++i)
		sort(g[i].begin(), g[i].end());
	int id = 0;
	for (int i = 1; i < 6; ++i)
		for (size_t j = 0; j < g[i].size(); ++j)
			hs[g[i][j]] = ++id;
	while (scanf("%s", s) > 0)
		printf("%d\n", hs[s]);
	return 0;
}
