#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> *adj, int *depth, int c){
	depth[src] = c;
	for (int i=0; i<adj[src].size(); ++i){
		dfs(adj[src][i], adj, depth, c+1);
	}
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int parent[n+1];
	vector<int> adj[n+1];
	parent[1] = 0;
	for (int i=0; i<n-1; ++i){
		cin >> parent[i+2];
		adj[parent[i+2]].push_back(i+2);
	}
	int val[n+1];
	val[0] = INT_MAX;
	int siz = log2(n)+2;
	int rmq[n+1][siz];
	int baap[n+1][siz];
	for (int i=0; i<siz; ++i){
		baap[0][i] = 0;
	}

	for (int i=1; i<=n; ++i){
		cin >> val[i];
		baap[i][0] = parent[i];
		rmq[i][0] = min(val[i], val[parent[i]]);
	}

	for (int i=0; i<siz; ++i){
		rmq[0][i] = INT_MAX;
	}

	
	for (int j=1; j<siz; ++j){
		for (int i=1; i<=n;++i){
			baap[i][j] = baap[baap[i][j-1]][j-1];
			rmq[i][j] = min(rmq[baap[i][j-1]][j-1], rmq[i][j-1]);
		}
	}

	int depth[n+1];
	dfs(1, adj, depth, 1);
	vector< pair<int, int> > ordered(n);
	for (int i=1; i<=n; ++i){
		ordered[i-1] = make_pair(depth[i], i);
	}
	sort(ordered.begin(), ordered.end());

	int dp[n+1];
	dp[0] = 0;
	dp[1] = val[1];
	for (int i=1; i<=n; ++i){
		// using log n steps find the closest ancestor which has value <  value
		// at this node 
		int current = ordered[i].second;
		for (int j = siz - 1; j >=0; --j){
			int to = baap[current][j];
			if (!to) continue;

			// if (i==6){
			// 	cout << "got current " << current << " to " << to << " j " << j << " and rmq " << rmq[current][j] << endl;
			// }
			if (rmq[current][j] >= val[ordered[i].second]){
				current = to;
			}

		}

		// cout << current << endl;
		dp[ordered[i].second] = dp[parent[current]] + (depth[ordered[i].second] - depth[current]+1)*val[ordered[i].second];
	}

	for (int i=1; i<=n; ++i){
		cout << dp[i] << " ";
	}
	cout << endl;

	return 0;
	
}