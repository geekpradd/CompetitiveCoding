#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m, k; cin >> n >> m >> k;
		int A[n][m], S[n][m];
		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j){
				cin >> A[i][j];
				if (j>0) {
					S[i][j] = A[i][j] + S[i][j-1]; 
				}
				else {
					S[i][j] = A[i][j];
				}
			}
		}		
		int dp1[n][m][k+1], dp2[n][m][k+1];
		for (int j=0; j<m; ++j){
			for (int l=0; l<=k; ++l){
				dp1[0][j][l] = S[0][j];
				if (j!=0){
					dp2[0][j][l] = S[0][j-1];
				}
				else {
					dp2[0][j][l] = 0;
				}
			}
		}

		for (int i=1; i<n; ++i){
			for (int j=0; j<m; ++j){
				dp1[i][j][0] = S[i][j] + dp1[i-1][j][0];

				if (j!=0){
					dp2[i][j][0] = S[i][j-1] + dp2[i-1][j][0];
				}
				else {
					dp2[i][j][0] = dp2[i-1][j][0];
				}
				
				for (int l=1; l<=k; ++l){
					dp1[i][j][l] = S[i][j]; dp2[i][j][l] = (j!=0 ? S[i][j-1] : 0);
					if (j!=0){
						dp1[i][j][l] += max(dp1[i-1][j-1][l-1], dp1[i-1][j][l]);
						dp2[i][j][l] += min(dp2[i-1][j-1][l-1], dp2[i-1][j][l]);
					}
					else {
						dp1[i][j][l] += dp1[i-1][j][l];
						dp2[i][j][l] += dp2[i-1][j][l];
					}
				}
			}
		}

		int s[m];
		s[m-1] = dp1[n-1][m-1][k];
		for (int i = m-2; i>=0; --i){
			s[i] = max(s[i+1], dp1[n-1][i][k]);
		}

		int ans = INT_MIN;
		for (int i=0; i<=m-2-k;++i){
			ans = max(ans, s[i+k+1] - dp2[n-1][i][k]);
		}

		cout << ans << endl;
	}

	return 0;
}