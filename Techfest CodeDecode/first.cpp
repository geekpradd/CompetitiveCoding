#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	vector<int> vals;
	vals.push_back(1);
	for (int i=1; i<14; ++i){
		int n = 0;
		for (int j=0; j<i; ++j){
			n+=vals[j]*vals[j];
		}
		vals.push_back(n);
	}

	for (int i=0; i<14; ++i){
		cout << vals[i] << endl;
	}

	return 0;
}