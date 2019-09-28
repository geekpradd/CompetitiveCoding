#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m; cin >> n >> m;

	if (n%2)
		cout << n/2 + 1 << endl;
	else
		cout << n/2 << endl;
	return 0;
}