#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n];
		for (int i=0; i<n; ++i) cin >> a[i];
		sort(a, a+n);
		int j;
		int s1 = 0;
		for (j=0; j<n/2; ++j) s1 -= a[j];
		for (; j<n; ++j)	s1 += a[j];

		cout << s1 << endl;
	}
}