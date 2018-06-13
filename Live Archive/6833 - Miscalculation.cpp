#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[20];
int res, n;

bool M() {
	vector<ll> st;
	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i]))
			st.push_back(s[i] - '0');
		else if (s[i] == '*') {
			ll b = st.back() * (s[i + 1] - '0');
			st.pop_back();
			st.push_back(b);
			++i;
		}
	}
	ll w = 0;
	for (size_t i = 0; i < st.size(); ++i)
		w += st[i];
	return w == res;
}

bool L() {
	ll w = s[0] - '0';
	for (int i = 1; i < n; i += 2) {
		if (s[i] == '+')
			w += s[i + 1] - '0';
		else
			w *= s[i + 1] - '0';
	}
	return w == res;
}

int main(int argc, char **argv) {
	while (scanf("%s%d", s, &res) > 0) {
		n = strlen(s);
		bool a = M();
		bool b = L();
		if (a && b)
			puts("U");
		else if (a)
			puts("M");
		else if (b)
			puts("L");
		else
			puts("I");
	}
	return 0;
}
