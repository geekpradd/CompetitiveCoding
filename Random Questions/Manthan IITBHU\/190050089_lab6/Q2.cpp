#include <iostream>
using namespace std;

void print_many(int n, char x){
	for (int i=0; i<n; ++i){
		cout << x;
	}
}

int main(){
	int i; char a;
	cin >> i;
	cin >> a;
	print_many(i, a);

	cout << endl;
	return 0;
}