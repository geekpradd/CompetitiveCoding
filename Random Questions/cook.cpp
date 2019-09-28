#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		int a[n], s[n-1];
		for (int i=0; i<n; ++i) cin >> a[i];

		for (int i=0; i<n-1; ++i) {
			char in; cin >> in;
			if (in == '>') s[i] = -1;
			if (in == '<') s[i] = 1;
			if (in == '=') s[i] = 0;
		}
		bool start = false;
		int prev = a[0];
		int first = a[0];
		int accum = 0;
		bool pass = false;
		bool error = false;

		for (int i=1; i<n; ++i){
			int cur = a[i];
			if (cur == -1 && prev != -1){
				first = prev;
				start = true;
			}


			if (start){
				int check = s[i-1];
				if (accum*check < 0){
					pass = true;
				}
				else {
					accum += check;
				}
			}

			if (cur!=-1 && start){
				if (!pass){
					if (accum > 0 && cur < first + accum)
						error = true;
					if (accum < 0 && cur > first + accum)
						error = true;
					if (accum == 0 && cur != first)
						error = true;
				}

				pass = false;
				start = false;
				accum = 0;

			}

			prev = a[i];

			if (i == n-1 && start){
				if (!pass){
					if (accum < 0 && first + accum < 0)
						error = true;
				}
				
			}

		}

		bool allinc = true;
		int count = 0;
		if (a[0] == -1){
			int val = -1;
			for (int i=1; i<n; ++i){
				count += s[i-1];
				if (s[i-1] == -1){
					allinc = false;
				}
				if (a[i]!=-1){
					val = a[i];
					break;
				}

			}

			if (val < count && allinc)
				error = true;

			if (val == -1)
				error = false;

		}

		if (error)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}