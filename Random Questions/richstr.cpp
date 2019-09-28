#include <bits/stdc++.h>
#define int long long
#define iii pair<int, pair<int, int>>
using namespace std;

void build(int* seg_tree, int l, int r, int i, int* ar){
	if (l==r){
		seg_tree[i] = 0;
	}
	else {
		int mid = (r+l-1)/2;
		build(seg_tree, l, mid, 2*i+1, ar); build(seg_tree, mid+1, r, 2*i+2, ar);
		bool status = seg_tree[2*i+1] | seg_tree[2*i+2];
		if (ar[mid] == ar[mid+1])
			status = status | 1;
		if (mid-1>=l){
			if (ar[mid-1] == ar[mid+1])
				status = status | 1;
		}
		if(mid+2<=r){
			if (ar[mid] == ar[mid+2])
				status = status | 1;
			if (mid-1>=l){
				if (ar[mid-1] == ar[mid+1])
					status = status | 1;
			}
		}
		// cout << "Setting  " << l << " and right " << r << " as " << status << endl;
		seg_tree[i] = status;
	}
}

int query(int* seg_tree, int ql, int qr, int l, int r, int i, int* ar){
	if (ql <= l && qr>=r){
		return seg_tree[i];
	}
	else if (ql > r || qr < l){
		return 0;
	}
	else { // overlap	
		int mid  = (r+l-1)/2;
		int left = query(seg_tree, ql, qr, l, mid, 2*i+1, ar);
		int right = query(seg_tree, ql, qr, mid+1, r, 2*i+2, ar);
		if (ql > mid)
			return right;
		if (qr<mid+1)
			return left;

		int status = right | left;

		if (ar[mid] == ar[mid+1])
			status = status | 1;
		if (mid-1>=l){
			if (ar[mid-1] == ar[mid+1])
				status = status | 1;
		}
		if(mid+2<=r){
			if (ar[mid] == ar[mid+2])
				status = status | 1;
			if (mid-1>=l){
				if (ar[mid-1] == ar[mid+1])
					status = status | 1;
			}
		}

		return status;

	}
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, q; cin >> n >> q;
		string inp; cin >> inp; int ar[n];
		for (int i=0; i<n; ++i) ar[i] = inp[i] - 'a';

		int ceil = log2(n) + 3;
		int *seg_tree = new int[(int) pow(2, ceil)];
		build(seg_tree, 0, n-1, 0, ar);

		while (q--){
			int l, r; cin >> l >> r;
			l--; r--;
			if (r-l<=1){
				cout << "NO" << endl;
				continue;
			}
			int res = query(seg_tree, l, r, 0, n-1, 0, ar);
			if (res == 0)
				cout << "NO" << endl;
			else 
				cout << "YES" << endl;
		}
	}

	return 0;
}