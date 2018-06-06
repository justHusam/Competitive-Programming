#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int main(int argc, char **argv) {
	int n, t, k;
	cin >> t;
	while (t-- != 0) {
		cin >> n;
		int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
		cin.ignore();
		for (int i = 0; i < n; ++i) {
			string s, x;
			getline(cin, s);
			stringstream ss(s);
			vector<string> v;
			while (ss >> x)
				v.push_back(x);
			int N = v.size();
			if (N == 1)
				++y4;
			else if (v[1] == "y" || v[1] == "yes")
				++y1;
			else {
				int c = 0;
				for (int a = 2; a < N; ++a)
					c += v[a] == "y" || v[a] == "yes";
				y2 += c;
				y3 += !c;
			}
		}
		printf("Roll-call: %d\n", ++k);
		printf("Present: %d out of %d\n", y1, n);
		printf("Needs to study at home: %d out of %d\n", y2, n);
		printf("Needs remedial work after school: %d out of %d\n", y3, n);
		printf("Absent: %d out of %d\n", y4, n);
	}
	return 0;
}
