#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

bool bs[] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 };
#define eps 1e-9;
double a, b, dp[20][20][20];
bool vis[20][20][20];

class PrimeSoccer {
public:
	double getProbability(int skillOfTeamA, int skillOfTeamB) {
		a = (double) skillOfTeamA / 100;
		b = (double) skillOfTeamB / 100;
		return calc(0, 0, 0);
	}
	inline double calc(int x, int y, int i) {
		if (i == 18)
			return bs[x] || bs[y];
		if (vis[x][y][i])
			return dp[x][y][i];
		vis[x][y][i] = 1;
		double r1 = calc(x, y, i + 1) * (1 - a) * (1 - b);
		double r2 = calc(x, y + 1, i + 1) * (1 - a) * b;
		double r3 = calc(x + 1, y, i + 1) * a * (1 - b);
		double r4 = calc(x + 1, y + 1, i + 1) * a * b;
		return dp[x][y][i] = r1 + r2 + r3 + r4;
	}
};
