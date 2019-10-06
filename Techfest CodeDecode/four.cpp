#include <bits/stdc++.h>
using namespace std;

bool check(int n){
	vector<int> val10;
	int k = n;
	while (k>0){
		val10.push_back(k%10);
		k = k/10;
	}

	vector<int> val3;
	while (n>0){
		val3.push_back(n%3);
		n = n/3;
	}
	// cout << "base10" << endl;
	for (int i=0; i<val10.size(); ++i){
		// cout << val10[i] << " ";
		if (val10[i]!=val10[val10.size()-1-i])
			return 0;
	}
	// cout << endl;
	for (int i=0; i<val3.size(); ++i){

		// cout << val3[i] << " ";
		if (val3[i]!=val3[val3.size()-1-i])
			return 0;
	}

	return 1;
}


signed main(){
	int s = 0;
	for (int i=1; i<122019; ++i){
		if (check(i)){
			s+=i;
		}
	}
	cout << s << endl;
}