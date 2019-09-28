#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, l; cin >> n >> l;
		int a[n]; 
		for (int i=0; i<n; ++i) cin >> a[i];

		sort(a, a+n);
		int distinct = 0; int prev = -1;
		vector<ii> b;

		for (int i=0; i<n; ++i){
			if (a[i]!=prev){
				distinct++;
				prev = a[i];
				b.push_back(make_pair(a[i], i+1));
			}
		}

		if (distinct < l){
			cout << "0" << endl;
		}
		else {
			sort(b.begin(), b.end());
			int m = distinct;
			cout << m << endl;
			// dp[i][j]: Max cost for interesting sequence of length j that COMPULSARILY has b[i] as last element
			int **dp = new int*[m];
			for (int i=0; i<m; ++i){
				dp[i] = new int[l+1];
			}
			for (int i=0; i<m; ++i){
				dp[i][1] = 0;
			}
			for (int i=1; i<m; ++i){
				for (int j=2; j<i+2; ++j){
					int best = -1;
					for (int k=i-1; k>=j-2; --k){
						int v = dp[k][j-1];
						int gap = b[i].second - b[k].second; int best2;
						if (v == 0){
							best2 = gap;
						}
						else if (gap >= v){
							best2 = v; 
						}
						else {
							best2 = gap;
						}
						best = max(best, best2);
					}
					dp[i][j] = best;
					cout << "Set dp[" << i+1 << "][" << j << "] as " << dp[i][j] << endl;
				}
			}
			int ans = dp[l-1][l];
			for (int i=l; i<m; ++i){
				ans = max(ans, dp[i][l]);
			}
			cout << ans << endl;
		}			
	}
}