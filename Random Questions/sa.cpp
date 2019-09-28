#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;
	while (t--){
		int n, d;
		cin >> n >> d;
		int a[n];
		// int s[n];
		for (int i=0; i<n; ++i){
			cin >> a[i];
		}
		// 	if (i==0)
		// 		s[i] = a[i];
		// 	else
		// 		s[i] = a[i] + s[i-1];
		// } 
		sort(a, a+n);
		int sum = 0;
		for (int i=n-1; i>0; --i){
			// int l = upper_bound(a, a+n, a[i]-d)-a;
			// cout << "for i " << i << " got " << l << endl;
			// int k = i-l;
			// sum += k*a[i];
			// if (i!=0){
			// 	if (l!=0)
			// 		sum += s[i-1]-s[l-1];
			// 	else
			// 		sum += s[i-1];
			// }
			if (a[i] - a[i-1] < d){
				sum += a[i] + a[i-1];
				i--;
			}


			
		}
		cout << sum << endl;
	}
	return 0;
}