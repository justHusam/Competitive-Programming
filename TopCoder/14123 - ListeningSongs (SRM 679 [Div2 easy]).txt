#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class ListeningSongs {
public:
	int listen(vector<int> durations1, vector<int> durations2, int minutes, int T) {
		if (T > (int) durations1.size() || T > (int) durations2.size())
			return -1;
		sort(durations1.rbegin(), durations1.rend());
		sort(durations2.rbegin(), durations2.rend());
		minutes *= 60;
		int res = 0;
		for (int i = 0; i < T; ++i) {
			int x = durations1.back();
			durations1.pop_back();
			if (x > minutes)
				return -1;
			minutes -= x;
			++res;
		}
		for (int i = 0; i < T; ++i) {
			int x = durations2.back();
			durations2.pop_back();
			if (x > minutes)
				return -1;
			minutes -= x;
			++res;
		}
		vector<int> v;
		for (size_t i = 0; i < durations1.size(); ++i)
			v.push_back(durations1[i]);
		for (size_t i = 0; i < durations2.size(); ++i)
			v.push_back(durations2[i]);
		sort(v.begin(), v.end());
		for (size_t i = 0; i < v.size(); ++i) {
			if (v[i] > minutes)
				break;
			++res;
			minutes -= v[i];
		}
		return res;
	}
};
