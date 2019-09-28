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

	vector<int> values((n*(n-1))/2);
	int e = 0;
	for (int i=1; i<=n; ++i){
		for (int j=i+1; j<=n; ++j){
			values[e] = (v[i] + v[j]);
			e++;
		}
	}
	sort(values.begin(), values.end());
	
	int count = 0;
	for (int i=1; i<=n; ++i){
		for (int j=i+1; j<=n; ++j){
			int rem = t - v[i] - v[j]; // find number of occurences of rem in the sorted vector values 
			int p = upper_bound(values.begin(), values.end(), rem) - lower_bound(values.begin(), values.end(), rem);
		
			p -= (upper_bound(m, m+n, rem - v[i]) - lower_bound(m, m+n, rem-v[i]));
			if (rem == 2*v[i]) {
				p += 1;
			}
			p -= (upper_bound(m, m+n, rem - v[j]) - lower_bound(m, m+n, rem-v[j]));
			if (rem == 2*v[j]){
				p+=1;
			}
			if (rem == v[i] + v[j]){
				p+=1;
			}
			count += p;

			
		}
	}
	cout << count/6 << endl;

	return 0;
}