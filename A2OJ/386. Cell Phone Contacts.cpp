#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
map<string, int> hs;
char a[100], b[100];
vector<vector<string> > A, B;
vector<pair<string, string> > all;
vector<pair<ll, int> > temp;

inline string getPH(string &s) {
	string res = "(";
	for (int i = 0; i < s.size(); ++i) {
		res += s[i];
		if (i == 2)
			res += ")";
		if (i == 5)
			res += "-";
	}
	return res;
}

inline void doPH(vector<string> &v) {
	temp.clear();
	for (int i = 0; i < v.size(); ++i) {
		ll x = 0;
		for (int j = 0; j < v[i].size(); ++j)
			x = x * 10 + (v[i][j] - '0');
		temp.push_back(make_pair(x, i));
	}
	sort(temp.begin(), temp.end());
	puts("Phone:");
	for (int i = 0; i < temp.size(); ++i) {
		string p = getPH(v[temp[i].second]);
		puts(p.c_str());
	}
}

inline void doEM(vector<string> &v) {
	sort(v.begin(), v.end());
	puts("E-Mail:");
	for (int i = 0; i < v.size(); ++i)
		puts(v[i].c_str());
}

int main(int argc, char **argv) {
	int cas = 1;
	while (scanf("%d", &n) && n != 0) {
		hs.clear();
		A.clear();
		B.clear();
		all.clear();
		int idx = 0;
		for (int i = 0; i < n; ++i) {
			string s = "";
			scanf("%s%s", a, b);
			s += a;
			s += " ";
			s += b;
			if (hs.find(s) == hs.end()) {
				hs[s] = idx++;
				A.push_back(vector<string>());
				B.push_back(vector<string>());
				all.push_back(make_pair(b, a));
			}
			int pos = hs[s];
			scanf("%s", a);
			bool phone = true;
			for (int j = 0; a[j] && phone; ++j)
				phone &= a[j] >= '0' && a[j] <= '9';
			if (phone)
				A[pos].push_back(a);
			else
				B[pos].push_back(a);
		}
		sort(all.begin(), all.end());
		printf("Contact list #%d:\n", cas++);
		for (int i = 0; i < all.size(); ++i) {
			string s = all[i].second + " " + all[i].first;
			puts(s.c_str());
			int idx = hs[s];
			doPH(A[idx]);
			doEM(B[idx]);
			puts("###");
		}
		puts("");
	}
	return 0;
}
