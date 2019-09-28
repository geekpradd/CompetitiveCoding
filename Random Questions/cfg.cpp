#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, k, sum = 0;
	cin >> n >> k;
	int a[n], b[n]; 
	for (int i=0; i<n; ++i) cin >> a[i];
	b[0] = 0;

	for (int i=1; i<n; ++i){
		b[i] = a[i] - a[i-1]; sum += b[i];
	}
	sort(b, b+n);
	for (int i=n-1; i> n-k; --i){
		sum -= b[i];
	}

	cout << sum << endl;

}