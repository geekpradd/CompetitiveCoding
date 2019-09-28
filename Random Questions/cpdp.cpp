#include <bits/stdc++.h>
#define MOD 1000000007 
using namespace std;
int dp[1001][20010];
// dp[i][j], number of good arrays ending at i such that net sum is j - 10000

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i=1; i<=1000; ++i){
		for (int j=0; j<=20009; ++j){
			dp[i][j] = 0;
		}
	}
	int n; cin >> n;
	int a[n];

	for (int i=0; i<n; ++i) cin >> a[i];

	dp[0][a[0] + 10000] = 1; dp[0][-1*a[0] + 10000] = 1;

	int ans = 0;
	for (int i=1; i<n; ++i){
		// cout << "alive " << i << endl;
		for (int j=0; j<= 20009; ++j){
			dp[i][j] = 0;
			if (j - a[i] >= 0 && j - a[i] <= 20009){
				dp[i][j] = (dp[i][j] + dp[i-1][j-a[i]])%MOD;
			}
			if (j+a[i] >= 0 && j+a[i] <= 20009){
				dp[i][j] = (dp[i][j] +  dp[i-1][j+a[i]])%MOD;
			}
		}
		dp[i][a[i]+10000] = (dp[i][a[i]+10000] + 1)%MOD;
		dp[i][-1*a[i]+10000] = (dp[i][-1*a[i]+10000] + 1)%MOD;
		// cout << "got "<< dp[i][10000] << endl;
		ans = (ans + dp[i][10000])%MOD;
	}

	cout << ans << endl;
	return 0;

}