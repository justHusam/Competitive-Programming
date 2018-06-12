#include <bits/stdc++.h>
using namespace std;

class GridGenerator {

public:
	int generate(vector<int> row, vector<int> col) {
		int cum[15][15] = { }, sz = row.size();
		for (int i = 1; i <= sz; ++i) {
			cum[1][i] = row[i - 1];
			cum[i][1] = col[i - 1];
		}
		for (int i = 2; i <= sz; ++i)
			for (int j = 2; j <= sz; ++j)
				cum[i][j] = cum[i - 1][j - 1] + cum[i][j - 1] + cum[i - 1][j];
		return cum[sz][sz];
	}
};

int main(int argc, char **argv) {
	return 0;
}
