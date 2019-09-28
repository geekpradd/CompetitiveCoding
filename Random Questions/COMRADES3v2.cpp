#include <bits/stdc++.h>
#define int long long
using namespace std;
int mapper[100004];
// lazy value when updated does not update seg tree value

int dfs(int cur, vector<int> *adj, vector<int> &array, int* size){
	array.push_back(cur);
	mapper[cur] = array.size();
	size[cur] = 1;
	for (int i=0; i<adj[cur].size(); ++i){
		int to = adj[cur][i];
		size[cur] += dfs(to, adj, array, size);
	}

	return size[cur];
}

int build_tree(int * seg_tree, int l, int r, int i, int* lazy, int* len){
	lazy[i] = -1;
	if (l == r){ 
		len[i] = 1;
		seg_tree[i] = 1;
	}
	else {
		int mid = (r+l-1)/2;
		seg_tree[i] = build_tree(seg_tree, l, mid, 2*i+1,lazy ,len) + build_tree(seg_tree, mid+1, r, 2*i+2, lazy, len);
		len[i] = len[2*i+1] + len[2*i+2];

	}
	return seg_tree[i]; 
}

int update(int* seg_tree, int l, int r, int ul, int ur, int i, int* lazy, int* len, bool type){
	if (ul <=l && ur>=r){
		seg_tree[i] = type*len[i];
		lazy[i] = type;
		return seg_tree[i];
	}
	else if (ul > r || ur < l){
		return 0;
	}
	else {
		int mid = (r+l-1)/2;
		lazy[2*i+1] = lazy[i]; lazy[2*i+2] = lazy[i];
		if (lazy[i] != -1){
			seg_tree[2*i + 1] = lazy[i]*(len[2*i+1]); seg_tree[2*i+2] = lazy[i]*len[2*i+2];
		}
		lazy[i] = -1;
		int cur_val = 0;
		if (ul <= mid){
			cur_val += update(seg_tree	, l, mid, ul, ur, 2*i+1, lazy, len, type);
		}
		else {
			cur_val += seg_tree[2*i+1];
		}
		if (ur >= mid+1){
			cur_val += update(seg_tree	, mid+1, r, ul, ur, 2*i+2, lazy, len, type);
		}
		else {
			cur_val += seg_tree[2*i+2];
		}
		seg_tree[i] = cur_val; return cur_val;
	}
}

int query(int* seg_tree, int l, int r, int ql, int qr, int i, int* lazy, int* len){
	if (ql <= l && qr >= r){
		if (l==r && lazy[i]!=-1){
			seg_tree[i] = lazy[i]; lazy[i]=-1;
		}
		if (lazy[i]!=-1)
			return lazy[i]*len[i];
		else
			return seg_tree[i];


	}
	else if (ql > r || qr < l){
		return 0;
	}
	else {
		int mid = (r+l-1)/2;
		if (lazy[i] != -1){
			lazy[2*i+1] = lazy[i]; lazy[2*i+2] = lazy[i];
			seg_tree[2*i+1] = lazy[i]*len[2*i+1]; seg_tree[2*i+2] = lazy[i]*len[2*i+2];
			seg_tree[i] = len[i]*lazy[i];
		}
		lazy[i] = -1;
		int ret = 0;
		ret += (ql > mid ? 0 : query(seg_tree, l, mid, ql, qr,2*i+1, lazy, len) );
		ret += (qr < mid+1? 0 : + query(seg_tree, mid+1, r, ql, qr, 2*i+2, lazy, len));
		
		return ret;
	}
}
signed main(){
	int n; cin >> n;
	int baap[n+1], root, size[n+1], len[3*n+1];
	vector<int> adj[n+1];

	for (int i=1; i<= n; ++i){
		cin >> baap[i];
		adj[baap[i]].push_back(i);
		if (!baap[i]) root = i;
	}
	vector<int> array;
	dfs(root, adj, array, size);
	int q; cin >> q; 
	int ceil = log2(n) + 1;
	int alloc_size = pow(2, ceil+8);
	int seg_tree[alloc_size	], lazy[alloc_size];

	build_tree(seg_tree, 1, n, 0, lazy, len);
	while (q--){
		int code, s; cin >> code >> s;
		int ind = mapper[s], length = size[s] - 1;

		if (code == 3){
			cout << query(seg_tree, 1, n, ind+1, ind+length, 0, lazy,len) << endl;
		}
		else if (code == 2){
			update(seg_tree	, 1, n, ind+1, ind+length, 0, lazy, len, 0);
		}
		else {
			update(seg_tree	, 1, n, ind+1, ind+length, 0, lazy, len, 1);
		}

	}
	return 0;
}