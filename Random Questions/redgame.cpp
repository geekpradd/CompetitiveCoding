#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, k, sum = 0; cin >> n >> k;
		int a[n];
		for (int i=0; i<n; ++i){
			cin >> a[i]; sum+= a[i];
		} 
		sort(a, a+n);
		int prev = 0, times = 0;

		for (int i=0; i<n; ++i){
			if (a[i] > k && i<n-1){
				prev = (a[i] - prev - k);
				times += prev;
			}
		}

		cout << sum - 2*times << endl;
	}

	return 0;
}