#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n], sum = 0;
		for (int i=0; i<n; ++i){
			 cin >> a[i]; sum += a[i];
		}

		if (n==1){
			cout << -1 << endl; continue;
		}
		if (sum%(n-1)){
			cout << -1 << endl; continue;
		}

		int val = sum/(n-1);

		int count = 0;bool pos = 1;
		for (int i=0; i<n; ++i){
			int cur = val - a[i];

			if (cur == 0 || cur == 1){
				count += cur^1;
			}
			else {
				pos = 0; break;
			}
		}

		if (pos){
			cout << count << endl;
		}
		else {
			cout << -1 << endl;
		}


	}

	return 0;
}