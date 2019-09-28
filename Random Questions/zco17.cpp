#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int m, t; cin >> m >> t;
	int* values = new int[t+1];
	int* pairval = new int[2*t + 1];

	for (int i=0; i<=t; ++i){
		values[i] = 0;
		pairval[i] = 0;
		pairval[i+t] = 0;
	}


	vector<int> v;
	for (int i=0; i<m; ++i){
		int inp; cin >> inp;
		if (inp <= t){
			v.push_back(inp);
			values[inp]++;
		}
	}

	int n = v.size();
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			pairval[v[i]+v[j]]++;
		}
	}

	int count = 0;

	for (int i=0; i<n; ++i) {
		for (int j = i+1; j<n; ++j){
			int rem = t - v[i] - v[j];

			int p;
			if (rem >= 0){
				p = pairval[rem];
			}
			else 
				p = 0;

			if (rem - v[i] >= 0){
				p -= values[rem-v[i]];
			}
			if (rem == 2*v[i]) p++;

			if (rem - v[j] >= 0){
				p -= values[rem-v[j]];
			}
			if (rem == 2*v[j]) p++;

			if (rem == v[i] + v[j]) p++;

			count += p;
		}
	}

	cout << count/6 << endl;

	return 0;
}	