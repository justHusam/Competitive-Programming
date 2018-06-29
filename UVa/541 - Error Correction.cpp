#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int n;
	while (scanf("%d", &n) > 0 && n != 0) {
		int R = 0, C = 0;
		vector<int> row, col;
		int freq[2] = { };
		vector<vector<int> > g(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < n; ++j)
				sum += g[i][j];
			row.push_back(sum);
			if (sum % 2 != 0)
				++freq[0];
		}
		for (int j = 0; j < n; ++j) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				sum += g[i][j];
			col.push_back(sum);
			if (sum % 2 != 0)
				++freq[1];
		}
		if (freq[0] == 0 && freq[1] == 0)
			printf("OK\n");
		else if (freq[0] == 1 && freq[1] == 1) {
			for (size_t i = 0; i < row.size() && R == 0; ++i)
				if (row[i] % 2 != 0)
					R = i + 1;
			for (size_t i = 0; i < col.size() && C == 0; ++i)
				if (col[i] % 2 != 0)
					C = i + 1;
			printf("Change bit (%d,%d)\n", R, C);
		} else
			printf("Corrupt\n");
	}
	return 0;
}
