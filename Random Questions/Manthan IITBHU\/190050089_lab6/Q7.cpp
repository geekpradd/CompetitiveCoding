#include <iostream>
using namespace std;
int a, b, c, d;

int f(int x){
	return a*x*x*x + b*x*x + c*x + d;
}

int main(){
	cin >> a >> b >> c >> d;

	for (int i=0; i<=100; ++i){
		if (f(i) == f(i+1)){
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}