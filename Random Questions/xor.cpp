#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int a, b, n; cin >> a >> b >> n;
		if (n%3 == 0)
			cout << a^b << endl;
		else if (n%3== 1)
			cout << a << endl;
		else
			cout << b << endl;
	}
	return 0;
}