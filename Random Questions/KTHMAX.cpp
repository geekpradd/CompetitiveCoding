#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
using namespace std;

//O((N+Q)logN) using Segment trees

void update(vector<int> &lseg, vector<int> &rseg, int i, int l, int r, int ind){
	if (i<l || i>r)
		return;

	if (l==r){
		lseg[ind] = i; rseg[ind] = i;
		return; 
	}
	
	int mid = (r-l)/2 + l;
	update(lseg, rseg, i, l, mid, 2*ind + 1);
	update(lseg, rseg, i, mid + 1, r, 2*ind + 2);

 	rseg[ind] = max(rseg[2*ind+1], rseg[2*ind+2]);
 	if (lseg[2*ind+1] == 0)
 		lseg[ind] = lseg[2*ind+2];
 	else 
 		lseg[ind] = lseg[2*ind+1];

 	
}

int lquery(vector<int>& seg, int ql, int qr, int ind, int l, int r){
	if (r < ql || l > qr)
		return 0;
	if (r<=qr && l>=ql){

		return seg[ind];
	} 
	int mid = (r-l)/2 + l;
	int lval = lquery(seg, ql, qr, 2*ind+1, l, mid);
	int rval = lquery(seg, ql, qr, 2*ind+2, mid+1, r);
	if (lval == 0)
		return rval;
	else
		return lval;

}

int rquery(vector<int>& seg, int ql, int qr, int ind, int l, int r){
	if (r < ql || l > qr)
		return 0;
	if (r<=qr && l>=ql)
		return seg[ind];
	int mid = (r-l)/2 + l;
	int lval = rquery(seg, ql, qr, 2*ind+1, l, mid);
	int rval = rquery(seg, ql, qr, 2*ind+2, mid+1, r);
	if (rval == 0)
		return lval;
	else
		return rval;

}

signed main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		int ceil = log2(n) + 4; int siz = pow(2, ceil);
		vector<int> l_seg(siz, 0);
		vector<int> r_seg(siz, 0);


		ii a[n];
		for (int i=0; i<n; ++i){
			int v; cin >> v;
			a[i] = make_pair(v, i+1);
		}

		sort(a, a+n);

		int prev_val;
		int c = 0;
		vector<int> top_vals;
		vector<int> counter;

		for (int i=n-1; i>=0; --i){
			int index = a[i].second;
		

			int r_ind = lquery(l_seg, index+1, n, 0, 1, n);
			int l_ind = rquery(r_seg, 1, index-1, 0, 1, n);


			if (!r_ind)
				r_ind = n+1;
			if (!l_ind)
				l_ind = 0;
			int count = (r_ind - index)*(index - l_ind);
			c += count;
			counter.push_back(c);
			top_vals.push_back(a[i].first);

				
			update(l_seg, r_seg, index, 1, n, 0);
		}
		while (m--){
			int in; cin >> in;
			int index = lower_bound(counter.begin(), counter.end(), in) - counter.begin();
			cout << top_vals[index] << endl;
		}
	}
}