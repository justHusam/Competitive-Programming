#include<bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 100;
int freq[N];
vector<int> g[N];

class TravellingSalesmanEasy {

public:

	int getMaxProfit(int M, vector<int> profit, vector<int> city, vector<int> visit) {
		for (size_t i = 0; i < visit.size(); ++i)
			++freq[visit[i] - 1];
		for (size_t i = 0; i < city.size(); ++i)
			g[city[i] - 1].push_back(profit[i]);
		for (int i = 0; i < M; ++i)
			sort(g[i].rbegin(), g[i].rend());
		int res = 0;
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < min(freq[i], (int) g[i].size()); ++j)
				res += g[i][j];
		return res;
	}
};
