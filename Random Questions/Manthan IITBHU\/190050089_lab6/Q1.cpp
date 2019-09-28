#include <iostream>
using namespace std;

void print_many(int n){
	for (int i=0; i<n; ++i){
		cout << "A";
	}
}

int main(){
	int i; cin >> i;
	print_many(i);

	cout << endl;
	return 0;
}