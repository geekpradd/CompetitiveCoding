#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t;
	cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		int a[n];
		for (int i=0; i<n; ++i) cin >> a[i];
		for (int i=0; i<=n/2; ++i){
			if (i==(n/2) && n%2==0)
				continue;

			int cyc = (n + k-i)/n;

			if ((n+k-i)==n*cyc)
				cyc--;

			// cout << "got cyc " << cyc << endl;
			int cyc2=(n+k-(n-1-i))/n;

			if ((n+k-(n-1-i))==n*cyc2)
				cyc2--;

			int tot = cyc + cyc2;

			// cout << "got cyc2 "  << cyc2 <<endl;
			if ((n-1)==i*2){
				tot = cyc;
				if (tot)
					a[i] = 0;
			}
			else {
				if (tot%6==1){
					a[i] = a[i]^a[n-1-i];
				}
				if (tot%6 == 2){
					int ts = a[i]; a[i] = a[i]^a[n-1-i]; a[n-1-i] = ts;
				}	
				if (tot%6==3){
					int ts = a[i]; a[i] = a[n-1-i]; a[n-1-i] = ts;
				}
				if (tot%6==4){
					int ts = a[i]^a[n-1-i]; a[i] = a[n-1-i]; a[n-1-i] = ts;
				}
				if (tot%6==5){
					a[n-1-i] = a[i]^a[n-1-i];
				}
			}

		}

		for (int i=0; i<n; ++i)
			cout << a[i] << " ";

		cout << endl;
	}

	return 0;
}