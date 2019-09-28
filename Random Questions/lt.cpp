#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n, q; cin >> n >> q;
		int v[n], b[n];
		for (int i=0; i<n; ++i){
			cin >> v[i];
			b[i] = v[i];
		} 
		sort(b, b+n);

		while (q--){
			int x, y; cin >> x >> y;
			cout << abs(v[y-1]-v[x-1]) + (y-x) << " ";
			int c;
			if (v[x-1]<=v[y-1]){
				cout << upper_bound(b, b+n, v[y-1]) - lower_bound(b, b+n, v[x-1]) << endl;
			}
			else {
				cout << upper_bound(b, b+n, v[x-1]) - lower_bound(b, b+n, v[y-1]) << endl;

			}
		}


	}
}