#include <bits/stdc++.h>
using namespace std;

int count(int n){
	if (n==0) return 0;
	int b = 0;
	for (int m = 0; m < 31; ++m){
		if (n&(1<<m))
			b = m+1;
	}

	int s = 0;
	for (int i=b-1; i>0; --i){
		for (int j=1; j<=i; ++j){
			if (i%j==0)
				s++;
		}
	}
	int c = 1 << (b-1);
	int v = 0;
	while (c > 0 && n&c){
		v++;
		c = c >> 1;
	}
	for (int i=1; i<v; ++i){
		if (b%i==0) s++;
	}

	if (b%v==0){
		int gen = (1<<v) - 1;
		
		int num = 0;
		for (int i=b-v;i>=0; i-=2*v){
			num += gen*(1<<i);
		}
		// cout << "genee" << num << endl;
		// cout << "gen is " << gen << endl;
		// cout << "B is " << b << " v is " << v << endl;
		if (num <= n)
			s++;
	}
	return s;
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int l, r; cin >> l >> r;
		l--;
		cout << count(r) - count(l) << endl;
	}

	return 0;
}