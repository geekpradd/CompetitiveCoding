#include <bits/stdc++.h>
#include <climits>
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	if (n<=6){
		cout << m << endl;
		return 0;
	}

	vector<int> count(8, 0);
	for (int i=0; i<m; ++i){
		int a, b; cin >> a >> b;
		count[a]++; count[b]++;
	}

	int mini = INT_MAX;
	for (int i=1; i<=7; ++i){
		mini = min(mini, count[i]);
	}

	int ans;
	if (mini > 0){
		ans = m - mini + 1;
	}
	else {
		ans = m - mini;
	}

	cout << ans << endl;
	return 0;
}