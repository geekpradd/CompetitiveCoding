#include <iostream>
using namespace std;

// array representation of binary trees

void fix_heap(int ar[], int i, int last){
	int largest = i;
	if ((2*i+1) <= last){
		if (ar[2*i+1] > ar[largest]){
			largest = 2*i + 1;
		}		
	}
	if ((2*i+2) <= last){
		if (ar[2*i+2] > ar[largest]){
			largest = 2*i + 2;
		}		
	}
	int t = ar[largest], v = ar[i];
	ar[i] = t; ar[largest] = v;

	if (largest != i){
		fix_heap(ar, largest, last);
	}
}

void make_heap(int ar[], int size){
	int st = size/2; st--;
	for (int i=st; i>=0; --i){
		fix_heap(ar, i, size-1);
	}
}

void heapsort(int ar[], int size){
	make_heap(ar, size);
	
	for (int i=0; i<size; ++i){
		int lar = ar[0]; int rep = ar[size - 1 - i];
		ar[0] = rep; ar[size-1-i] = lar;
		fix_heap(ar, 0, size - 2 - i);
	} 
}
int main(){
	int n; cin >> n;
	int V[n];
	for (int i=0; i<n; ++i) cin >> V[i];
	heapsort(V, n);
 	for (int i=0; i<n; ++i){
 		cout << V[i] << " ";
 	}
 	cout << endl;
}