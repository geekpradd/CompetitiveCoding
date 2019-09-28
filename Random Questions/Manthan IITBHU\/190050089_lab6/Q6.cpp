#include <iostream>
using namespace std;

void swap(int &x, int &y){
	x = x^y;
	y = x^y;
	x = x^y;
}

int main(){
	int n1, n2; cin >> n1 >> n2;
	swap(n1, n2);
	cout << n1 << " " <<  n2 << endl;

	return 0;
}