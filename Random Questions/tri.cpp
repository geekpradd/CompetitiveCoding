#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a[] = {1, 2, 3, 3};
	cout << lower_bound(a, a + 4, 3) - a - 4 << endl;
}