#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int c[1001][1001];
int s[1001][1001];
int fact[1001];

int power(int x, unsigned int y) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2) % MOD; 
    p = (p * p) % MOD; 
  
    return (y%2 == 0)? p : (x * p) % MOD; 
}

int inverse(int n){
	return (power(n, MOD-2))%MOD;
}

signed main(){
	int t; cin >> t;

	c[0][0] = 1;
	s[0][0] = 1;
	fact[0] = 1;
	for (int i=1; i<=1000; ++i){
		fact[i] = (fact[i-1]*i)%MOD;
		c[i][0] = 1;
		s[i][0] = 1;
		for (int j=1; j<=i; ++j){
			
			c[i][j] = (c[i][j-1]*((i-j+1))%MOD*inverse(j))%MOD;

			if (j==1)
				s[i][j] = c[i][j];
			else
				s[i][j] = (s[i][j-2] + c[i][j])%MOD;
		}
		c[0][i] = 0;
	}


	while (t--){
		int n; cin >> n;

		int a[n];
		for (int i=0; i<n; ++i) cin >> a[i];

		vector<int> count(2*n+1, 0);
		vector<int> left(2*n+1, -1);
		vector<int> right(2*n+1, -1);

		sort(a, a+n);

		for (int i=0; i<n; ++i){
			count[a[i]]++;
			if (left[a[i]]== -1)
				left[a[i]] = i;
			right[a[i]] = max(right[a[i]], i);

		}
		int val = 0;
		for (int i=0; i<n-1; ++i){
			if (a[i] == a[i+1]){
				int k = right[a[i]] - left[a[i]] + 1;

				
				for (int p = 2; p<=k; ++p){
					int ri = left[a[i]] + p - 2;
					if (ri > n-k){
						if (n-k % 2 == ri%2)
							ri = n-k;
						else
							ri = n-k-1;
					}
					int li = left[a[i]]-p;
					int subt;
					if (li < 0){
						subt = 0;
					}
					else {
						subt = s[n-k][li];
					}
					// cout << "ri " << ri << " li " << li << endl;
					// cout << "added " << s[n-k][ri] - subt << " p = " << p << endl; 
					int multipler = (((s[n-k][ri] - subt)%MOD)*c[k][p]*fact[p])%MOD;
					// cout << "mult" << multipler<< endl;
					val = (val + multipler)%MOD;
				}
	
				i = right[a[i]];
			}
		}
		val = (val + power(2, n-1))%MOD;

		cout << val << endl;

	}
}