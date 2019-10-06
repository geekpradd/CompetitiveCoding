#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, qu;
		cin >> n >> qu;
		int in[n-1];
		for (int i=0; i <n-1; ++i)
			cin >> in[i];
		int a[n], b[n];
		// int b[n/2 - 1];
		// int *a; int siz;
		// if (n%2 == 0){
		// 	siz = n/2 - 1;
		// }
		// else {
		// 	siz = n/2;
		// }
		// a = new int[siz];
		int c = 0;
		for (int i=0; i<n-1; i+=2){
			if (i==n-2)
				continue;
			a[c] = in[i] - in[i+1];
			// cout << "A[ " << c << " = " << a[c] << endl;

			c++;
		}
		int d = 0;
		for (int i=1; i<n-1; i+=2){
			if (i==n-2)
				continue;
			b[d] = in[i] - in[i+1];
			// cout << "B[ " << d << " = " << b[d] << endl;

			d++;
		}

		int prefa[c], prefb[d];
		prefa[0] = a[0];
		prefb[0] = b[0];
		for (int i=1; i<c; ++i){
			prefa[i] = a[i] + prefa[i-1];
		}
		for (int i=1; i<d; ++i){
			prefb[i] = b[i] + prefb[i-1];
		}
		while(qu--){
			int p, q;
			cin >> p >> q;
			// cout << "p " << p << " q " << q << endl;
			if (p > q){
				int temp = q;
				q = p;
				p = temp;
			}
			// cout << "p " << p << " q " << q << endl;
			if (p%2 == q%2){
				cout << "UNKNOWN" << endl;
				continue;
			}
			if (q == p + 1){
				cout << in[q-2] << endl;
				continue;
			}

			int l = (q-p)/2;
			if (p%2){
				int start = (p-1)/2;
				int val = prefa[start + l - 1];
				if (start != 0 )
					val -= prefa[start - 1];
				val += in[q-2];
				cout << val << endl;
			}
			else {
				int start = (p-2)/2;
				int val = prefb[start + l - 1];
				if (start != 0)
					val -= prefb[start-1];
				val += in[q-2];
				cout << val << endl;
			}
			

		}


	}
}