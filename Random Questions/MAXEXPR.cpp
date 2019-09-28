#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		double k[n], c[n]; 
		for (int i=0; i<n; ++i) cin >> k[i];
		for (int i=0; i<n; ++i) cin >> c[i];

		double v1 = 0, v2 = 0;
		for (int i=0; i<n; ++i){
			double z = 1.0/k[i]; v1 +=z;
			v2 += k[i]*c[i];
		}
		if (v2<0){
			cout << -1 << endl;
		}
		else {
			double s = sqrt(v1*v2);
			double lambda = sqrt(v2/v1);
			cout << s << " ";
			for (int i=0; i<n; ++i){
				double m = lambda/k[i];

				double x = m*m - c[i];
				cout << x << " ";
			}
			cout << endl;
		}
		
	}
	return 0;
}