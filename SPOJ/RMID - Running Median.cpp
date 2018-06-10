#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
	int x;
	while (scanf("%d", &x) > 0) {
		set<int> st;
		st.insert(x);
		set<int>::iterator it = st.begin(), nIt;
		while (scanf("%d", &x) && x) {
			if (x == -1) {
				printf("%d\n", *it);
				set<int>::iterator temp = it;
				if (st.size() % 2 == 0)
					++temp;
				else
					--temp;
				int val = *temp;
				st.erase(it);
				it = st.find(val);
			} else {
				st.insert(x);
				if (st.size() & 1)
					++it;
			}
		}
		puts("");
	}
	return 0;
}
