#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		if(n==1){
			cout << "2" << endl;
			continue;
		}
		bool pa = false;
		for (int i=2; i<31; ++i){
			if (n+1 == 1 << i)
				pa = true;
		}
		if (!pa){
			cout << -1 << endl;
			continue;
		}
		cout << (n>>1) << endl;
	}

	return 0;
}