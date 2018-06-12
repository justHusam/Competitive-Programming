#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DevuAndGame {
public:
	string canWin(vector<int> nextLevel) {
		int at = 0;
		vector<bool> vis(nextLevel.size());
		while (at != -1) {
			if (vis[at])
				break;
			vis[at] = true;
			at = nextLevel[at];
		}
		if (at == -1)
			return "Win";
		return "Lose";
	}
};
