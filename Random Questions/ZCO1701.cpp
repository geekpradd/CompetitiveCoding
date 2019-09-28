#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, t; cin >> n >> t;
	int v[n+1], m[n];
	for (int i=1; i<=n; ++i){
		cin >> v[i];
		m[i-1] = v[i];
	} 
	sort(m, m+n);

	// a b c d
	
	vector<int> values(n*n - n);
	int e = 0;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (j!=i){
				values[e] = (v[i] + v[j]);;
				e++;
			}
		}
	}
	sort(values.begin(), values.end());
	
	int count = 0;
	for (int i=1; i<=n; ++i){
		for (int j=1; j<=n; ++j){
			if (j!=i){
				int rem = t - v[i] - v[j]; // find number of occurences of rem in the sorted vector values 
				int p = upper_bound(values.begin(), values.end(), rem) - lower_bound(values.begin(), values.end(), rem);
		
				p -= 2*(upper_bound(m, m+n, rem - v[i]) - lower_bound(m, m+n, rem-v[i]));
				if (rem == 2*v[i]) {
					p += 2;
				}
				p -= 2*(upper_bound(m, m+n, rem - v[j]) - lower_bound(m, m+n, rem-v[j]));
				if (rem == 2*v[j]){
					p+=2;
				}
				if (rem == v[i] + v[j]){
					p+=2;
				}
				count += p;

			}
		}
	}
	cout << count/24 << endl;

	return 0;
}