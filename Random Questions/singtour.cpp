#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> score(n, 0);
		vector< pair<int, int> > left(n), right(n);

		for (int i=0; i<n; ++i){
			pair<int, int> l, r;
			int a, b; cin >> a >> b;
			l = make_pair(a, i); left[i] = l;
			r = make_pair(b, i); right[i] = r;			
		}
		sort(left.begin(), left.end());
		sort(right.begin(), right.end());

		for (int i=0; i<n; ++i){
			score[left[i].second] +=  n - i - 1;
			score[right[i].second] += i;
		}
		for (int i=0; i<n; ++i){
			cout << score[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}