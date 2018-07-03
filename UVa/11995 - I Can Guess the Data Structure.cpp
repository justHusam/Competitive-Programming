#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

int n;
vector<pair<int, int> > v;

bool checkST() {
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		if (v[i].first == 1) {
			st.push_back(v[i].second);
			continue;
		}
		if (st.empty() || st.back() != v[i].second)
			return false;
		st.pop_back();
	}
	return true;
}

bool checkQU() {
	queue<int> qu;
	for (int i = 0; i < n; ++i) {
		if (v[i].first == 1) {
			qu.push(v[i].second);
			continue;
		}
		if (qu.empty() || qu.front() != v[i].second)
			return false;
		qu.pop();
	}
	return true;
}

bool checkPQ() {
	priority_queue<int> qu;
	for (int i = 0; i < n; ++i) {
		if (v[i].first == 1) {
			qu.push(v[i].second);
			continue;
		}
		if (qu.empty() || qu.top() != v[i].second)
			return false;
		qu.pop();
	}
	return true;
}

string calc() {
	int a = checkST();
	int b = checkQU();
	int c = checkPQ();
	int d = a + b + c;
	if (d == 0)
		return "impossible";
	if (d > 1)
		return "not sure";
	if (a == 1)
		return "stack";
	if (b == 1)
		return "queue";
	return "priority queue";
}

int main(int argc, char **argv) {
	while (scanf("%d", &n) > 0) {
		v.clear();
		v.resize(n);
		for (int a = 0; a < n; ++a)
			scanf("%d%d", &v[a].first, &v[a].second);
		puts(calc().c_str());
	}
	return 0;
}
