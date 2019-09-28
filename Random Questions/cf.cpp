#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m, k; cin >> n >> m >> k;
	int steps = 0, discarded = 0, cur_batch = 0;

	int p[m], cur = -1;
	for (int i=0; i<m; ++i){
		cin >> p[i];
		// cout << "my discarded is " << discarded << endl;
		int cur_ = (p[i]-1-discarded)/k;
		// cout << "with " << p[i] << " got " << cur_ << endl;
		if (cur_ == cur){
			cur_batch++;
		}
		else {
			steps++;
			discarded += cur_batch;
			cur = (p[i]-1-discarded)/k;
			
			cur_batch = 1;
			
		}
		
		// cout << "discarded is " << discarded << endl;
	} 

	cout << steps << endl;
	return 0;

		
}