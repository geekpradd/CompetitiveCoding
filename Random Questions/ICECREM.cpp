#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int w[n], p[n], v[n];
		for (int i=0; i<n; ++i)
			cin >> w[i] >> p[i] >> v[i];
		int h = n/2; int siz = pow(2, h);
		vector<ii> values;

		for (int i=0; i<siz; ++i){
			int profit = 0;
			int time = 0;
			bool poss = true;
			for (int j=0; j<h; ++j){
				int tracker = 1 << j;
				if (tracker&i){
					// jth guy is set
					if (time <= w[j]){
						time += p[j]; profit += v[j];
					}
					else 
						poss = false;
				}
			}
			if (!poss) continue;
			values.push_back(make_pair(time, profit));
		}

		sort(values.begin(), values.end());
		int maxe[values.size()]; maxe[0] = values[0].second;
		for (int i=1; i<values.size(); ++i){
			maxe[i] = max(maxe[i-1],values[i].second);
		}
		int rem = n-h; siz = pow(2, rem);
		int best = 0;

		for (int i=0; i<siz; ++i){
			int profit = 0;
			int time = 0;
			int gap = INT_MAX;
			bool poss = true;
			for (int j=0; j<rem; ++j){
				int tracker = 1 << j;
				if (tracker&i){
					// jth guy is set
					if (time <= w[j+h]){
						gap = min(gap, w[j+h] - time);
						time += p[j+h]; profit += v[j+h];
					}
					else 
						poss = false;
				}
			}
			if (!poss) continue;
			ii check = make_pair(gap + 1, 0);
			int index = lower_bound(values.begin(), values.end(), check) - 1 - values.begin();
			if (index < 0) continue;
			best = max(best, profit + maxe[index]);
			
		}

		cout << best << endl;
	}

	return 0;
}