#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool comp(int l, int r, int i, vector<int> &a, int g){
	if (i == l || i == r)
		return true;

	int ind_r = lower_bound(a.begin(), a.end(), a[i+1]-g) - a.begin();
	int ind = lower_bound(a.begin(), a.end(), a[i]-g) - a.begin();
	if (ind_r>=i)
		return false;
	if (ind == ind_r){
		if (ind==i-1 && i-1==0)
			return true;
		else if(ind==i-1)
			return false;
	}
	

	return comp(l, i-1, ind, a, g);

}


signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;

	while (t--){
		int n, d; cin >> n >> d;
		vector<int> a(n);
		bool pass = true;

		int in;
		for (int i=0; i<n; ++i){
			cin >> a[i];
			
		} 
		in = a[0];
		sort(a.begin(), a.end());

		for (int i=0; i<n-1; ++i){
			int gap = a[i+1] - a[i];
			if (gap > d)
				pass = false;
		}

		if (!pass){
			cout << "NO" << endl; continue;
		}

		int index = lower_bound(a.begin(), a.end(), in) - a.begin();

		bool res = comp(0, n-1, index, a, d);

		cout << (res ? "YES": "NO") << endl;

	}
}