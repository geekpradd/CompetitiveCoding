#include <bits/stdc++.h>
#define tuple<int, int, int> ti;
using namespace std;

signed main(){
	int n, t;
	cin >> n >> t; 
	int a[n];
	for (int i=0; i<n;++i) cin >> a[i];

	vector<ti> values((n*(n-1))/2);
	int counter = 0;
	for (int i=0; i<n; ++i){
		for (int j=i+1; j<n; ++j){
			ti current = make_tuple(a[i] + a[j], i, j);
			values[counter] = current; counter++;
		}
	}

	sort(values.begin(), values.end());

	// use two pointer method for getting values. Complexity is O(n^2)

	int left_pointer = 0, right_pointer = (n*(n-1))/2 - 1;
	int count = 0;
	while (left_pointer < right_pointer){
		int cur_sum = values[left_pointer] + values[right_pointer];
		if (cur_sum == t){
			
		}
	}

}