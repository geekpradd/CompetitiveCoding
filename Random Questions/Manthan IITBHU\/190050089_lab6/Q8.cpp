#include <iostream>
using namespace std;

int transfer(int &acc1, int &acc2, int amount){
	if (amount >= 0 && acc1 >= amount){
		acc1 -= amount;
		acc2 += amount;
		return 1;
	}
	else if (amount < 0 && acc2 >= -1*amount){
		acc2 += amount;
		acc1 -= amount;
		return 1;
	}
	return 0;
}

int main(){
	int a, b;
	cin >> a >> b;

	int trans, count = 0;
	cin >> trans;
	while (trans != 0){
		count += transfer(a, b, trans);
		cin >> trans;
	}

	cout << a << " " << b << " " <<  count << endl;
	return 0;
}