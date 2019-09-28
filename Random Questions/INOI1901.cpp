#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int C[n], P[m], T[m];

		for (int i=0; i<n; ++i) cin >> C[i];
		for (int i=0; i<m; ++i) cin >> P[i];
		for (int i=0; i<m; ++i) cin >> T[i];

		vector< ii > jobs(m);
		for (int i=0; i<m; ++i){
			jobs[i] = make_pair(T[i], P[i]);
		}
		sort(jobs.begin(), jobs.end());

		int **dp = new int*[n+1];
		for (int i=0; i<=n; ++i) dp[i] = new int[m+1];

		// Not possible is indexed by -1
		dp[0][0] = 0;
		for (int i=1; i<=n; ++i){
			dp[i][0] = C[i-1] + dp[i-1][0];
		}
		for (int j=1; j<=m; ++j){
			ii cur = jobs[j-1];
		
			if (dp[0][j-1] != -1 && cur.first > dp[0][j-1]){
				int v2;
				if (cur.first - cur.second > dp[0][j-1]){
					v2 = cur.first;
				}
				else {
					v2 = dp[0][j-1] + cur.second;
				}
				dp[0][j] = v2;
			}
			else {
				dp[0][j] = -1;
			}
				
			
		}
		for (int i=1; i<=n; ++i){
			for (int j=1; j<=m; ++j){
				// case 1 if i+j job is from pool of C[1...n]

				int v1;
				if (dp[i-1][j] == -1){
					v1 = -1;
				}
				else {
					v1 = dp[i-1][j] + C[i-1];
				}

				// case 2 if i+j job is from P[1....m] (in jobs)
				ii cur = jobs[j-1];

				if (dp[i][j-1] != -1){
					if (cur.first > dp[i][j-1]){
						int v2;
						if (cur.first - cur.second > dp[i][j-1]){
							v2 = cur.first;
						}
						else {
							v2 = dp[i][j-1] + cur.second;
						}

						if (v1 != -1)
							dp[i][j] = min(v1, v2);
						else 
							dp[i][j] = v2;
					}
					else {
						dp[i][j] = v1;
					}
				}
				else {
					dp[i][j] = v1;
				}
				
			}
		}

		cout << dp[n][m] << endl;

	}
	return 0;
}