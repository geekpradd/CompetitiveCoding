#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int m; cin >> m;

		vector<int> divisors;
		set<int> vals;

		for (int i=1; i*i<=m; ++i){
			if (m%i==0){
				if (i*i != m){
					divisors.push_back(m/i);
					vals.insert(m/i);
				}
				
				divisors.push_back(i);
				vals.insert(i);
			}
		}

		for (int i=0; i<divisors.size(); ++i){
			for (int j=0; j<divisors.size(); ++j){
				if (divisors[i]*divisors[j] < m){
					vals.insert(divisors[i]*divisors[j]);
				}
			}
		}

		set<int>::iterator b = vals.begin();
		cout << vals.size() << endl;
		for (; b!= vals.end(); ++b){
			cout << *b + m << endl;
		}
	}
}