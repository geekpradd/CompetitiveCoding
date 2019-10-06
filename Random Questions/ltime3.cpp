#include <bits/stdc++.h>
#define int long long
using namespace std;

int compute(int *p, int *v, int *w, int i, int n, int time){
	if (i>=n)
		return 0;
	// cout << "at level " << i << " time " << time << endl;
	int t = time + p[i];
	if (time>w[i])
		return compute(p, v, w, i+1, n, time);
	else
		return max(v[i] + compute(p, v, w, i+1, n, t), compute(p, v, w, i+1, n, time)); 
	
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; 
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int w[n], p[n], v[n];
		for (int i=0; i<n; ++i)
			cin >> w[i] >> p[i] >> v[i];

		cout << compute(p, v, w, 0, n, 0) << endl;
	}

	return 0;

}