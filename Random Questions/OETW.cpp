#include <bits/stdc++.h>
#define LARGE 10000000
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;

	while (t--){
		int n, sum = 0;
		cin >> n;
		int a[n];
		int left = LARGE;
		for (int i=0; i<n;++i){
			cin >> a[i]; sum+=a[i];
			if (left == LARGE && a[i] == 1)
				left = i;
		}
		
		int right = LARGE;
		for (int i=n-1; i>=0; --i){
			if (right == LARGE && a[i] == 1)
				right = i;
		}
		int other_parity = max(sum - left*2 - 1, sum - 2*(n-right-1) - 1);
		if (left == LARGE && right == LARGE){
			cout << (sum+1)/2 << endl;
		}
		else {
			cout << (sum+1)/2 + (other_parity+1)/2 << endl;
		}
	}

	return 0;
}