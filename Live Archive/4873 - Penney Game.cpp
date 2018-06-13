#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
	string P[] = { "TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
	int T;
	cin >> T;
	while (T-- != 0) {
		map<string, int> freq;
		for (int i = 0; i < 8; ++i)
			freq.insert(make_pair(P[i], 0));
		int csNum;
		string s;
		cin >> csNum >> s;
		for (size_t i = 0; i < s.length(); ++i)
			if (i + 2 < s.length()) {
				string sub = s.substr(i, 3);
				if (freq.find(sub) != freq.end())
					++freq[sub];
			}
		printf("%d", csNum);
		for (int i = 0; i < 8; ++i)
			printf(" %d", freq[P[i]]);
		puts("");
	}
	return 0;
}
