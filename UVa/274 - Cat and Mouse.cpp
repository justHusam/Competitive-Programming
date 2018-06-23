#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int n, mr, cr;
		scanf("%d %d %d", &n, &cr, &mr);
		--mr, --cr;
		vector<vector<bool> > cg, mg, smg;
		cg = mg = smg = vector<vector<bool> >(n, vector<bool>(n, false));
		cg[cr][cr] = mg[mr][mr] = true;
		while (true) {
			int u, v;
			cin >> u >> v;
			if (u < 1 || v < 1)
				break;
			--u, --v;
			cg[u][v] = true;
		}
		string ss;
		cin.ignore();
		while (getline(cin, ss) && ss != "") {
			stringstream sss(ss);
			int u, v;
			sss >> u >> v;
			--u, --v;
			mg[u][v] = smg[u][v] = 1;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					cg[i][j] = cg[i][j] | (cg[i][k] & cg[k][j]);
					mg[i][j] = mg[i][j] | (mg[i][k] & mg[k][j]);
				}
		char f = 'N', s = 'N';
		for (int i = 0; i < n; ++i) {
			if (cg[cr][i] && mg[mr][i]) {
				f = 'Y';
				break;
			}
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (!cg[cr][j])
						smg[i][j] = smg[i][j] | (smg[i][k] & smg[k][j]);
				}
		if (smg[mr][mr])
			s = 'Y';
		printf("%c %c\n", f, s);
		if (T != 0)
			puts("");
	}
	return 0;
}
