#include <bits/stdc++.h>
using namespace std;

struct node {
	bool leaf;
	struct l_child;
	struct r_child;
	int value;
	int occur;
}

node get_node(){
	node x; x.l_child = NULL; x.r_child = NULL; x.value = NULL; x.occur = 0; return x;
}

node populate_trie(int block, int l, int r, int *a, int ins) {
	node baap = get_node();
	node 
	for (int i=l; i<r; ++i){
		for (int bit = 15; bit>=0; --bit){
			int b = (a[i]&(1<<bit));
			if (b){
				if (baap.r_child == NULL)
					baap.r_child = get_node(); baap.r_child.leaf = (bit==0);
			}
		}
	}
}

signed main(){
	int n, q; cin >> n >> q;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];
	int block = sqrt(n);
	int count = 0;
	for (int i=0; i<n; i+= block){
		count++;
	}	
	node tries[count]; int z = 0;
	int left[count];
	for (int i=0; i<n; i+= block){
		node baap; baap.leaf = false; baap.l_child = NULL; baap.r_child = NULL; baap.value = NULL; baap.occur = 0;
		for (int j=i; j<i+block; ++j){
			node *cur = &baap;
			for (int bit = 15; bit>=0; --bit){
				int b = a[j]&(1<<bit);
				if (b){
					if ((*cur).r_child == NULL){
						node next; node.leaf = (bit==0); node.l_child = NULL; node.r_child = NULL; node.value = NULL; node.occur = 1;
						(*cur).r_child = next;
					}
					else {
						(*cur).r_child.leaf = (bit == 0);
						(*cur).r_child.occur++;
					}
					cur = &((*cur).r_child);
				}
				else {
					if ((*cur).l_child == NULL){
						node next; node.leaf = (bit==0); node.l_child = NULL; node.r_child = NULL; node.value = NULL; node.occur = 1;
						(*cur).l_child = next;
					}
					else {
						(*cur).l_child.leaf = (bit == 0);
					}
					cur = &((*cur).l_child);
				}

			}
		}
		tries[z] = baap; left[z] = 0; z++;
	}

	while (q--){
		int code; cin >> code;
		if (code){

		}
	}

}