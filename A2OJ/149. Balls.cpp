#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	int T;
	scanf("%d", &T);
	while (T-- != 0) {
		int p, n;
		scanf("%d %d", &p, &n);
		map<char, vector<int> > hs;
		char ch;
		for (int i = 0, c; i < n; ++i) {
			scanf(" %c %d", &ch, &c);
			hs[ch].push_back(c);
		}
		map<char, vector<int> >::iterator it;
		int r = 0, b = 0, g = 0;
		for (it = hs.begin(); it != hs.end(); ++it) {
			sort(it->second.begin(), it->second.end());
			int c = 0, d = 0;
			for (size_t i = 0; i < it->second.size(); ++i) {
				if (c + it->second[i] > p)
					break;
				c += it->second[i];
				d++;
			}
			if (it->first == 'B')
				b = d;
			else if (it->first == 'G')
				g = d;
			else if (it->first == 'R')
				r = d;
		}
		printf("Red balls = %d\nGreen balls = %d\nBlue balls = %d\n\n", r, g, b);
	}
	return 0;
}
