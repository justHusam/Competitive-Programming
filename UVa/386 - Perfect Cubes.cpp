#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 201, oo = 8000001;
int at[oo];
vector<vector<int> > sol[N];

int main(int argc, char **argv) {
	for (int i = 1; i < N; ++i)
		at[i * i * i] = i;
	for (int i = 2; i < N; ++i)
		for (int j = i; j < N; ++j)
			for (int k = j; k < N; ++k) {
				int a = i * i * i + j * j * j + k * k * k;
				if (a >= oo)
					break;
				a = at[a];
				if (a != 0) {
					sol[a].push_back(vector<int>());
					sol[a].back().push_back(i);
					sol[a].back().push_back(j);
					sol[a].back().push_back(k);
				}
			}
	for (int i = 1; i < N; ++i)
		for (size_t j = 0; j < sol[i].size(); ++j)
			printf("Cube = %d, Triple = (%d,%d,%d)\n", i, sol[i][j][0], sol[i][j][1], sol[i][j][2]);
	return 0;
}
