#include <bits/stdc++.h>
#define int long long
using namespace std;
// Merge Sort Tree

int count(vector<int> &vec, int k){

	return vec.end() - upper_bound(vec.begin(), vec.end(), k);
}

void build_tree(vector<int> * seg, int l, int r, int * array, int i){
	if (l==r){
		vector<int> base(1);
		base[0] = array[l];
		seg[i]= base;
	}
	else {
		build_tree(seg, l, (r+l-1)/2, array, 2*i + 1); vector<int> a = seg[2*i + 1];
		build_tree(seg, (r+l+1)/2, r, array, 2*i+2); vector<int> b = seg[2*i + 2];

		int tot = a.size() + b.size(), a_ptr = 0, b_ptr = 0;

		seg[i].resize(tot);

		for (int j=0; j<tot; ++j){
			if (a_ptr >= a.size()){
				seg[i][j] = b[b_ptr]; b_ptr++;
			}
			else if (b_ptr >= b.size()){
				seg[i][j] = a[a_ptr]; a_ptr++; 
			}
			else if (a[a_ptr] < b[b_ptr]){
				seg[i][j] = a[a_ptr]; a_ptr++; 
			}
			else {
				seg[i][j] = b[b_ptr]; b_ptr++;

			}
		}


	}
}

int query(vector<int>* seg, int l, int r, int i,int ql, int qr, int k){
	if (l >= ql && r <= qr){
		// cout << "found effective for l " << l << " r " << r << endl;
		// cout << count(seg[i], k) << endl;
		return count(seg[i], k);
	}
	else if (r < ql || l > qr){
		return 0;
	}
	else {
		int q = 0;
		if ((r+l-1)/2 >= ql) {
			q += query(seg, l, (r+l-1)/2, 2*i + 1, ql, qr, k);
		}
		if ((r+l+1)/2 <= qr){
			q += query(seg,(r+l+1)/2, r,  2*i + 2, ql, qr, k);
		}
		return q;
	

	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int a[n];
	for (int i=0; i<n; ++i) cin >> a[i];

	int ceil = log2(n) + 1;
	int size = pow(2, ceil+8);
	vector<int> *seg_tree = new vector<int>[size];

	build_tree(seg_tree, 0, n-1, a, 0);

	int q; cin >> q;
	int last_ans = -1;
	while (q--){
		int ql, qr, k; cin >> ql >> qr >> k;
		if (last_ans!= -1){
			ql = ql ^ last_ans;
			qr = qr ^ last_ans;
			k  = k ^ last_ans;
		}
		last_ans =  query(seg_tree, 0, n-1, 0, ql-1, qr-1, k);
		cout << last_ans << endl;
	}

	return 0;
}