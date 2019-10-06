#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int  y[n];
		vector<ii> x(n);
		vector<int> maxx;
		for (int i=0; i<n; ++i){
			cin >> x[i].first >> y[i];
			x[i].second = i;
		}
		sort(x.begin(), x.end());
		int val = x[n-1].first;
		int best = y[x[n-1].second];
		if (n==1)
			maxx.push_back(best);
		for (int i=n-2; i>=0; --i){
			if (x[i].first == val){
				best = max(best, y[x[i].second]);
			}
			else {
				maxx.push_back(best);
				val = x[i].first;
				best = y[x[i].second];
				
			}

			if (i==0)
				maxx.push_back(best);
		}
		sort(maxx.begin(), maxx.end());
		if (maxx.size() < 3)
			cout << 0 << endl;
		else 
			cout << maxx[maxx.size()-1] + maxx[maxx.size()-2] + maxx[maxx.size()-3] << endl;
	}

	return 0;
}

			
		
	