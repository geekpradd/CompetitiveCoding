#include <iostream>
#include <cmath>
using namespace std;

int main(){
	// find a^(1/b)
	int a, b; cin >> a >> b;
	double epsilon = 1e-15;
	double left = 0, right = a;
	while (right - left >epsilon){
		double mid = (left + right)/2;
		if (pow(mid, b)-a>=0){
			right = mid;
		}
		else {
			left = mid;
		}
	}

	cout << right << endl;
}