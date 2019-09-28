#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;


// O(n) algo. Really nice

signed main(){
	int t; cin >> t;
	while (t--){
		int l = 3*1000000;
		vector<ii> hashmap(l, make_pair(0, 0));
		hashmap[0] = make_pair(1, 0);
		int n; cin >> n;
		int a[n+1], dp[n+1];
		for (int i=1; i<=n; ++i) cin >> a[i];

		dp[0] = 0;
		int start = 0;
		for (int i=1; i<=n; ++i){
			start = start ^ a[i];
			ii cur = hashmap[start];
			dp[i] = dp[i-1] + cur.first*(i-1) - cur.second;
			hashmap[start] = make_pair(cur.first + 1, cur.second + i);
		}

		cout << dp[n] << endl;

	}
	return 0;

}