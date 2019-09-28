#include <iostream>
using namespace std;

int power(int a, int b){
	int ans = 1;
	for (int i=1; i<=b; ++i){
		ans *= a;
	}
	return ans;
}

int main(){
	int x, y;
	cin >> x >> y;
	cout << power(x, y) << endl;
	cout << power(y, x) << endl;

	return 0;
}