#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(true);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int j[n]; for (int i=0; i<n; ++i) cin >> j[i];
		vector<int> vals;

		for (int i=0; i<n; ++i){
			int b; cin >> b;
			if(j[i]==1)
				vals.push_back(b);
		}

		int decr = 0;
		int index = -1;
		for (int i=0; i<vals.size()-1; ++i){
			if (vals.size()<2)
				break;
			if (vals[i]>= vals[i+1])
				decr++;
		}
		if (decr > 1){
			cout << "#itsnot_arjun" << endl;
		} 
		else {
			cout << "#laughing_arjun" << endl;
		}

	}

	return 0;
}