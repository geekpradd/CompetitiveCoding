#include <bits/stdc++.h>
using namespace std;

int s(int n){
	int sum = 0;
	while (n>0){
		int d = n%10;
		n = n/10;
		sum += d;
	}
	return sum;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int count = 0;
	for (int i = n - 90; i<=n; ++i){
		if (i > 0){
			if (i + s(i) + s(s(i)) == n)
				count++;
		}
	}

	cout << count << endl;
	return 0;
}