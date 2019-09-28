#include <bits/stdc++.h>
#define int long long
using namespace std;
int *size_ar, *mapper, *rev_mapper;
vector<int> *seg_tree;

void build_tree(int l, int r, vector<int>& ar, int i){
	if (l==r){
		seg_tree[i].push_back(ar[l]);
	}
	else {
		int mid = (r+l-1)/2;
		build_tree(l, mid, ar, 2*i+1); build_tree(mid+1, r, ar,2*i+2);
		vector<int> temp(r-l+1); int itr = 0, l_ptr = 0, r_ptr = 0;

		while(itr <= r-l){
			if (l_ptr > mid-l){
				temp[itr] = seg_tree[2*i+2][r_ptr]; r_ptr++;
			}
			else if (r_ptr > r-mid-1){
				temp[itr] = seg_tree[2*i+1][l_ptr]; l_ptr++;
			}
			else if (seg_tree[2*i+1][l_ptr] < seg_tree[2*i+2][r_ptr]){
				temp[itr] = seg_tree[2*i+1][l_ptr]; l_ptr++;
			}
			else {
				temp[itr] = seg_tree[2*i+2][r_ptr]; r_ptr++;				
			}
			itr++;
		}

		seg_tree[i] = temp;
	}
}

int query(int l, int r, int ql, int qr, int i, int val){
	if (ql <= l && qr >= r){
		return upper_bound(seg_tree[i].begin(), seg_tree[i].end(), val) - lower_bound(seg_tree[i].begin(), seg_tree[i].end(), val);
	}
	else if (ql > r || qr < l){
		return 0;
	}
	else {
		int mid = (r+l-1)/2;
		return query(l, mid, ql, qr, 2*i+1, val) + query(mid+1, r, ql, qr, 2*i+2, val);
	}
}

int dfs(int src, vector<int> adj[], vector<int> &ar, int depth){
	mapper[src] = ar.size(); rev_mapper[ar.size()] = src; ar.push_back(depth);
	size_ar[src] = 1;
	for (int i=0; i<adj[src].size(); ++i){
		size_ar[src] += dfs(adj[src][i], adj, ar, depth+1);
	}

	return size_ar[src];
} 

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int *baap = new int[n+1];
	size_ar = new int[n+1]; mapper = new int[n+1]; rev_mapper = new int[n+1];
	vector<int>* adj = new vector<int>[n+1];vector<int> ar;

	int size = log2(n);
	int** dp= new int*[n+1];
	for (int i=0; i<=n; ++i){
		dp[i] = new int[size+2];
	}
	for (int i=0; i<= size; ++i) dp[0][i] = 0;

	for (int i=1; i<=n; ++i) {
		size_ar[i] = -1;
		cin >> baap[i];
		dp[i][0] = baap[i];
		adj[baap[i]].push_back(i);
	}
	for (int i=1; i<=n; ++i){
		if (baap[i] == 0)
			dfs(i, adj, ar, 0);
	}
	int ceil = log2(n) + 3;
	int all = pow(2, ceil);
	seg_tree = new vector<int>[all];
	build_tree(0, n-1, ar, 0);

	// Jump pointer algorithm for pth parent
	
	for (int i = 1; i<=size; ++i){
		for (int j = 1; j<=n; ++j){
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}

	int q; cin >> q;
	while (q--){
		int v, p; cin >> v >> p;
		// find pth baap of v
		int cur_depth = ar[mapper[v]];
		if (cur_depth < p){
			cout << 0 << endl; continue;
		}
		int c_p = p, v_c = v;
		while (c_p > 0){
			int cur = c_p&(-1*c_p);
			c_p -= cur;
			v_c = dp[v_c][(int) log2(cur)];
		}

		cout << query(0, n-1, mapper[v_c], mapper[v_c] + size_ar[v_c] - 1, 0, ar[mapper[v_c]] + p) - 1<< endl;
		
	}


	return 0;
}