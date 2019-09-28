#include <iostream>
using namespace std;

int get_max(int n1, int n2, int n3){
	if (n2 > n1){
		n2 = n1 ^ n2; n1 = n2^n1; 
		n2 = n2 ^ n1;
	}
	if (n3 > n1){
		return n3;
	}
	else {
		return n1;
	}
}

int main(){
	int a, b, c; cin >> a >> b >> c;
	cout << get_max(a, b, c) << endl;
	return 0;
}