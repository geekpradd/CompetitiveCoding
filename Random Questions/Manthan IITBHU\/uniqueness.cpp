#include <bits/stdc++.h>
#define int long long
#include <climits>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int v[n]; map<int, int> count;

	for (int i=0; i<n; ++i) {
		cin >> v[i];
		if (count.find(v[i]) != count.end())
			count[v[i]]++;
		else
			count[v[i]] = 1;
	}
	int len = INT_MAX;
	int only_once = 0;

	for (int i=0; i<n; ++i){
		if (count[v[i]] == 1) only_once++;
	}

	if (only_once == n){
		len = 0;
	}
	for (int i=0; i<n; ++i){
		map<int, int> copy = count;
		int cur_unique = only_once;
		for (int j=i; j<n; ++j){
			copy[v[j]]--;
			if (copy[v[j]]==1)
				cur_unique++;
			else if (copy[v[j]] == 0)
				cur_unique--;
			// cout << "i " << i << " j " << j <<endl;
			// cout << "erased " << v[j] << endl;
			// cout << "set size" << copy.size()<< " rest size" << n-(j-i+1) << endl; 
			if (cur_unique == n - (j-i+1)){
				len = min(len, j-i+1);
			}
		}

	}

	cout << len << endl;
	return 0;



}