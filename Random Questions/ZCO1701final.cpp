#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n, t;
	cin >> n >> t;
	int *dict = new int[t+1];
	for (int i=0; i<=t; ++i){
		dict[i] = 0;
	}
	vector<int> values;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		if (x < t){
			values.push_back(x);
			dict[x]++;
		}
	}
}