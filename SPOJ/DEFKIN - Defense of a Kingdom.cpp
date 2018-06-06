#include <bits/stdc++.h>
using namespace std;

vector<int> W, H;

int main() {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		W.clear();
		H.clear();
		int w, h, n;
		scanf("%d%d%d", &w, &h, &n);
		W.push_back(0);
		W.push_back(w + 1);
		H.push_back(0);
		H.push_back(h + 1);
		int x, y;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			W.push_back(x);
			H.push_back(y);
		}
		sort(W.begin(), W.end());
		sort(H.begin(), H.end());
		int mxW = 0, mxH = 0;
		for (int i = 0; i < (int) W.size(); ++i) {
			mxW = max(mxW, W[i] - W[i - 1] - 1);
			mxH = max(mxH, H[i] - H[i - 1] - 1);
		}
		printf("%d\n", mxW * mxH);
	}
	return 0;
}
