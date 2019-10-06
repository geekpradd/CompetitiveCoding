#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		vector<int> maxi(1000001);
		for (int i=0; i<n; ++i){
			cin >> a[i];
			maxi[a[i]] = i;
		} 


		vector<int> sieve(1000001, 0);
		int star = INT_MIN;
		for (int i=0; i<n; ++i){
			int c = 0;

			if (i == maxi[a[i]]){
				for (int k=a[i]; k<=1000000; k+=a[i]){
					c += sieve[k];
				}
				star = max(star, c);
			}
			sieve[a[i]]++;
			
		}

		cout << star << endl;
	}
	return 0;
}