#include <bits/stdc++.h>
#define int long long
using namespace std;

int pow2(int num){
	if (num%2)
		return 0;
	return 1 + pow2(num/2);
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		int p = pow2(n);
		int rem = n/pow(2, p);
		if (p%2){
			cout << "Lose" << '\n' << flush;
			string l; cin >> l;
			if (l == "WA")
				return 0;

			continue;
		}

		cout << "Win" << '\n' << flush;
	
		while (p!=0){ 
			cout << "/2" << '\n' << flush;
			string mov; cin >> mov;

			p-=2;
		}

		while (rem!=0){
			if (rem == 1){
				cout << "-1" << '\n' << flush;
				string final; cin >> final;
				rem = 0;
			}
			else if ((rem+1)/2 % 2){
				cout << "+1" << '\n' << flush;
				string mov; cin >> mov;
				rem = (rem+1)/2;
			}

			else {
				cout << "-1" << '\n' << flush;
				string mov; cin >> mov;
				rem = (rem-1)/2;
			}
		}
	}
}