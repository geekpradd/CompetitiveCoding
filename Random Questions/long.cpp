#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> gcd(1000001, 0);
vector<int> final(1000001, 0);

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];

	vector<int> total;
	vector<int> previous;
	map<int, int> counter;

	for (int i=n-1; i>=0; --i){
		vector<int> current;
		map<int, int> currcounter;

	
		current.push_back(a[i]);

		currcounter[a[i]] = 1;

		for (int j=0; j<previous.size(); ++j){
			int val = __gcd(a[i], previous[j]);
			if (!currcounter.count(val))
				current.push_back(val);

			if (currcounter.count(val)){
				currcounter[val] = currcounter[val] + counter[previous[j]];
			}
			else {
				currcounter[val] = counter[previous[j]];
			}
		}

		previous = current;
		counter = currcounter;

		for (int i=0; i<previous.size(); ++i){
			if (previous[i]<=1000000){
				if (gcd[previous[i]] == 0)
					total.push_back(previous[i]);
				gcd[previous[i]] += counter[previous[i]];
			}
			
		}
	}

	for (int i=0; i<total.size(); ++i){
		int val = total[i];
		for (int k = 1; k*val <= 1000000; ++k){
			final[k*val] += gcd[val];
		}
	}

	int q;
	cin >> q;
	while (q--){
		int a; cin >> a;
		cout << final[a] << endl;
	}

}