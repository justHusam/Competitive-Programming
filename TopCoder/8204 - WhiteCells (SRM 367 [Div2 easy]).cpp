#include <bits/stdc++.h>
using namespace std;


class WhiteCells {

public:
	int countOccupied(vector<string> board) {

		int res = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i][j] == 'F' && ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)))
					++res;
		return res;
	}
};
