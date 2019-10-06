#include <bits/stdc++.h>
using namespace std;

int f(int n){
	if (n==1)
		return 1;
	else 
		return n*f(n-1);
}

int d(int n){
	if (n==0)
		return 1;
	int s = f(n);
	int prev = f(n);
	for (int i=1; i<=n;++i){
		prev = -1*prev/i;
		s += prev;
	}

	return s;
}

signed main(){
	int m = 5;
	for (int n=1; n<=m; ++n){
		cout << "n = " << n << endl;
		int c[n+1];
		c[0] = 1;

		for (int i=1; i<=n; ++i){
			c[i] = ((c[i-1]*(n-i+1))/i);
		}

		double s = 0;
		for (int i=1; i<=n; ++i){
			cout << "i " << i << " c " << c[i] << endl;
			cout << "d " << d(n-i) << endl;
			cout << " added " << c[i]*d(n-i)*i << endl;
			s += c[i]*d(n-i)*i;
		}

		cout << "got s  " << s  << endl;
		s = s/f(n);

		cout << s << endl;
	}
}