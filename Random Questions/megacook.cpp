#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



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
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--){
		int n, m, k;
		cin >> n >> m >> k;
		int c[n+1];
		c[0] = 1;

		for (int i=1; i<=n; ++i){
			c[i] = (c[i-1]*((n-i+1))%MOD*inverse(i))%MOD;
		}

		int ans = 0;
		int accum = 1;
		for (int i = 0; i<=n-k; ++i){
			
			ans = ( ans + (c[n-i]*accum)%MOD)%MOD;
			accum  = (accum*((m-1)%MOD))%MOD;
		}

		cout << ans << endl;
	}
}