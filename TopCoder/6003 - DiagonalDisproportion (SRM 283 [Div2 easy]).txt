#include <bits/stdc++.h>
using namespace std;

class DiagonalDisproportion {

public:
	int getDisproportion(vector<string> matrix) {
		int sm1 = 0, sm2 = 0;
		for (int i = 0; i < matrix.size(); i++)
			sm1 += int(matrix[i][i] - '0');
		for (int i = (int) matrix.size() - 1, j = 0; i >= 0; i--, j++)
			sm2 += int(matrix[j][i] - '0');
		return sm1 - sm2;
	}
};
