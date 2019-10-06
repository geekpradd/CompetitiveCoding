#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int sieve[100001];
    for (int i=1; i<=100000; ++i)
        sieve[i] = 0;
    int s[100001]; int v[100001];
    for (int i=2; i<=100000; ++i){
        if (sieve[i])
            continue;
            
        v[i] = i+1;
        for (int j=i; j<=100000; j+=i)
            sieve[j] = i;
    }
    s[0] = 0;
    v[2]= v[1] = s[1] = 1;
    s[2] = 2;
    for (int i=3; i<=100000; ++i){
        int pdiv = sieve[i];
        int exponent = 0, quotient = i;
        while (quotient%pdiv == 0){
            exponent++;
            quotient = quotient/pdiv;
        }
        if (quotient==1){
            if (pdiv == 2)
                v[i] = 1;
            else
                v[i] = (pow(pdiv, exponent+1)-1)/(pdiv-1);
        }
        else {
            int r = pow(pdiv, exponent);
            v[i] = v[quotient]*v[r];
        }
        s[i] = s[i-1] + v[i];
    }
    
    
    int t; cin >> t;
    while (t--){
        int l, r; cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    return 0;
}