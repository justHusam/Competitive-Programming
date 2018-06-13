#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string res[] = { "White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple" };
int a[] = { 255, 192, 128, 0, 255, 128, 255, 128, 0, 0, 0, 0, 0, 0, 255, 128 };
int b[] = { 255, 192, 128, 0, 0, 0, 255, 128, 255, 128, 255, 128, 0, 0, 0, 0 };
int c[] = { 255, 192, 128, 0, 0, 0, 0, 0, 0, 0, 255, 128, 255, 128, 255, 128 };

int main(int argc, char **argv) {
	int x, y, z;
	while (scanf("%d%d%d", &x, &y, &z) && x != -1) {
		vector<pair<int, int> > v;
		for (int i = 0; i < 16; ++i) {
			int r1 = a[i] - x;
			int r2 = b[i] - y;
			int r3 = c[i] - z;
			v.push_back(make_pair(r1 * r1 + r2 * r2 + r3 * r3, i));
		}
		sort(v.begin(), v.end());
		printf("%s\n", res[v[0].second].c_str());
	}
	return 0;
}
