#include <bits/stdc++.h>
using namespace std;

int n, freq[1000000], b[10000];
vector<vector<int> > sol;

int main(int argc, char **argv) {
	bool f = false;
	while(scanf("%d",&n) && n){
		if(f)
			puts("");
		f = true;
		memset(freq, 0, sizeof freq);
		int mx = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&b[i]);
			++freq[b[i]];
			mx = max(mx, freq[b[i]]);
		}
		sol.clear();
		sol.resize(mx);
		sort(b, b + n);
		int at = 0;
		for(int i = 0; i < n; ++i){
			sol[at].push_back(b[i]);
			at = (at + 1) % mx;
		}
		printf("%d\n",mx);
		for(int i = 0; i < mx; ++i, puts(""))
			for(int j = 0; j < sol[i].size(); ++j)
				printf("%s%d",j?" ":"",sol[i][j]);
	}
	return 0;
}