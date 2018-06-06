#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	double aa;
	while (cin >> aa) {
		int cnt = 0;
		if (aa >= 0)
			cnt++;
		for (int i = 1; i < 6; ++i) {
			cin >> aa;
			if (aa >= 0)
				cnt++;
		}
		cout << cnt << " valores positivos" << endl;
	}
	return 0;
}
