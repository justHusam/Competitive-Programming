#include<bits/stdc++.h>
using namespace std;

class BacteriesColony {

public:
	vector<int> performTheExperiment(vector<int> colonies) {
		while (true) {
			vector<int> add(colonies.size(), 0);
			bool can = false;
			for (size_t i = 1; i + 1 < colonies.size(); ++i) {
				if (colonies[i] > colonies[i - 1] && colonies[i] > colonies[i + 1])
					add[i] = -1, can = true;
				else if (colonies[i] < colonies[i - 1] && colonies[i] < colonies[i + 1])
					add[i] = 1, can = true;
			}
			if (!can)
				break;
			for (size_t i = 0; i < (int) colonies.size(); ++i)
				colonies[i] += add[i];
		}
		return colonies;
	}
};
