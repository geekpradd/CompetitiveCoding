#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	int n = 305201920*2;
	cout << "A" << endl;
	int count = 0;
	for (int i=2; i<=n; ++i){
		cout << "att " << i << endl;
		if (n%i==0){
			int lamb = i-1;
			int rem = n/i;
			int del = rem - lamb;
			if (del%2==0)
				count++;
		}
	}

	cout << count << endl;

	return 0;
}