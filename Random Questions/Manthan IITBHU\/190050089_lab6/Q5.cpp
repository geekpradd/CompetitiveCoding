#include <iostream>
using namespace std;

int get_gcd(int a, int b){
	if (b == 0)
		return a;
	else
		return get_gcd(b, a%b);
}

int get_lcm(int a, int b){
	return (a*b)/get_gcd(a, b);
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << get_gcd(a, b) << endl;
	cout << get_lcm(a,b) << endl;

	return 0;
}