#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sol;

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0 && n != 0) {
		sol.clear();
		while (n-- != 0) {
			int x;
			scanf("%d", &x);
			if (x != 0)
				sol.push_back(x);
		}
		if (sol.empty())
			sol.push_back(0);
		for (size_t i = 0; i < sol.size(); ++i)
			printf("%s%d", i ? " " : "", sol[i]);
		puts("");
	}
	return 0;
}
