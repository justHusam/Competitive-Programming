#include <bits/stdc++.h>
using namespace std;

int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int main(int argc, char **argv) {
	string A, B;
	while (cin >> A >> B) {
		int f1 = A[0] - 'a' + 1;
		int f2 = A[1] - '0';
		int t1 = B[0] - 'a' + 1;
		int t2 = B[1] - '0';
		queue<pair<int, int> > qu;
		qu.push(make_pair(f1, f2));
		int cost[9][9] = { };
		while (!qu.empty()) {
			pair<int, int> e = qu.front();
			qu.pop();
			if (e.first == t1 && e.second == t2)
				break;
			for (int i = 0; i < 8; i++) {
				int tx = e.first + dx[i];
				int ty = e.second + dy[i];
				if (tx > 0 && ty > 0 && tx <= 8 && ty <= 8 && cost[tx][ty] == 0) {
					cost[tx][ty] = cost[e.first][e.second] + 1;
					qu.push(make_pair(tx, ty));
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", A.c_str(), B.c_str(), cost[t1][t2]);
	}
	return 0;
}
