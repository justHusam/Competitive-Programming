#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct state {
	double a, b;
	string s;
	state(double a, double b, string &s) :
			a(a), b(b), s(s) {
	}
};

vector<state> v;
char s[111];

bool check(double str) {
	double w = str, s = v[0].b, pos = 0, need, add = 0;
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i].s == "Fuel consumption") {
			need = (v[i].a - pos) / 100 * s + (v[i].a - pos) * add;
			if (need > w)
				return false;
			w -= need;
			s = v[i].b;
			pos = v[i].a;
		} else if (v[i].s == "Leak") {
			need = (v[i].a - pos) / 100 * s + (v[i].a - pos) * add;
			if (need > w)
				return false;
			w -= need;
			pos = v[i].a;
			++add;
		} else if (v[i].s == "Gas station") {
			need = (v[i].a - pos) / 100 * s + (v[i].a - pos) * add;
			if (need > w)
				return false;
			w -= need;
			pos = v[i].a;
			w = str;
		} else if (v[i].s == "Mechanic") {
			need = (v[i].a - pos) / 100 * s + (v[i].a - pos) * add;
			if (need > w)
				return false;
			w -= need;
			pos = v[i].a;
			add = 0;
		} else if (v[i].s == "Goal") {
			need = (v[i].a - pos) / 100 * s + (v[i].a - pos) * add;
			if (need > w)
				return false;
		}
	}
	return true;
}

int main(int argc, char **argv) {
	while (gets(s) > 0 && strcmp(s, "0 Fuel consumption 0")) {
		v.clear();
		while (true) {
			stringstream ss(s);
			double a, b = -1;
			string z, x;
			ss >> a >> z;
			if (z == "Fuel" || z == "Gas") {
				ss >> x;
				z += " " + x;
			}
			if (z == "Fuel consumption")
				ss >> b;
			v.push_back(state(a, b, z));
			if (z == "Goal")
				break;
			gets(s);
		}
		double s = 0, e = 1e9, m, res = 2e9;
		for (int it = 0; it < 64; ++it) {
			m = (s + e) / 2;
			if (check(m)) {
				e = m;
				res = min(res, m);
			} else
				s = m;
		}
		printf("%.3lf\n", res);
	}
	return 0;
}
