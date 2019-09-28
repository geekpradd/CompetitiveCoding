#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);

	int q;
	cin >> q;
	while (q--){
		int c, m, x; cin >> c >> m >> x;

		int a1 = min(c,m);
		int  n = (c+m+x)/3;

		cout << min(a1, n) << endl;
	}

	return 0;
}