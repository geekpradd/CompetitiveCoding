#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n; cin >> n;
	int v[n+1];
	for (int i=0; i<n; ++i){
		char in; cin >> in;
		if (in=='(') v[i] = 1;
		else
			v[i] = -1;
	}
	v[n] = 1;
	int dp[n+1];
	// 0 means either ) or no valid from that index starting with (
	dp[n-1] = 0; dp[n] = 0;

	for (int i=n-2; i>=0; --i){
		if (v[i] == -1){
			dp[i] = 0; continue;
		}

		if (v[i+1] == -1)
			dp[i] = 2 + dp[i+2];
		else {
			int fin = dp[i+1];
			if (v[i+fin+1] == 1)
				dp[i] = 0;
			else{
				dp[i] = fin + 2 + dp[i+fin+2];
			}
		}

		cout << "at i " << i << " got " << dp[i] << endl;
	}
}