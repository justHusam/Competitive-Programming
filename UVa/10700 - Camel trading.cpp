#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[111];
vector<int> v;
vector<ll> st;

ll Min() {
	st.clear();
	ll with = v[0];
	for (int i = 1; i < v.size(); i += 2) {
		if (v[i] == 0) {
			st.push_back(with);
			with = v[i + 1];
		} else {
			with *= v[i + 1];
		}
	}
	st.push_back(with);
	ll res = 0;
	for (int i = 0; i < st.size(); ++i) {
		res += st[i];
	}
	return res;
}

ll Max() {
	st.clear();
	ll with = v[0];
	for (int i = 1; i < v.size(); i += 2) {
		if (v[i] == 1) {
			st.push_back(with);
			with = v[i + 1];
		} else {
			with += v[i + 1];
		}
	}
	st.push_back(with);
	ll res = 1;
	for (int i = 0; i < st.size(); ++i) {
		res *= st[i];
	}
	return res;
}

int main(int argc, char **argv) {
	int t;
	scanf("%d", &t);
	while (t-- != 0) {
		scanf("%s", s);
		int n = strlen(s);
		v.clear();
		for (int i = 0; i < n; ++i) {
			if (!isdigit(s[i])) {
				v.push_back(s[i] == '*');
				continue;
			}
			int x = s[i] - '0';
			if (i + 1 < n && isdigit(s[i + 1])) {
				++i;
				x = x * 10 + (s[i] - '0');
			}
			v.push_back(x);
		}
		ll mx = Max();
		ll mn = Min();
		printf("The maximum and minimum are %lld and %lld.\n", mx, mn);
	}
	return 0;

}
