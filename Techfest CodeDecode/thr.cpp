#include <bits/stdc++.h>
using namespace std;

int s(int n){
	int l = 0;
	while (n>0){
		int digit = n%10;
		n = n/10;
		l += digit;
	}

	return l;
}

int p(int n){
	int l = 1;
	while (n>0){
		int digit = n%10;
		n = n/10;
		l *= digit;
	}

	return l;
}

signed main(){
	int c = 0;
	for (int i=1000; i<10000; ++i){
		if (p(p(i)) - s(s(i))==10){
			c++;
			cout << i << endl;
		}
	}

	cout << c << endl;
}