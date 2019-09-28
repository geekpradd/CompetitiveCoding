#include <bits/stdc++.h>
#define int long long
using namespace std;

int dfs(int i, vector<int> &visited, vector< vector<int> >  &adj, int* cost){
	int score = cost[i];
	visited[i] = 1;
	for (int j=0; j<adj[i].size(); j++){
		int to = adj[i][j];
		if (!visited[to]){
			score += dfs(to, visited, adj, cost);
		}
	}
	return score;
}

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m, k; cin >> n >> m >> k;
		vector< vector<int> > adj(n+1);
		int cost[n+1];
		for (int i=0; i<m; ++i){
			int a, b; cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i=1; i<=n; ++i){
			cin >> cost[i];
		}

		vector<int> components;
		int count = 0;
		vector<int> visited(n+1, 0);
		for (int i=1; i<=n; ++i){
			if (!visited[i]){
				count++;
				components.push_back(dfs(i, visited, adj, cost));
			}
		}

		if (k > count){
			cout << "-1" << endl;
		}
		else {
			int ans = 0;
			for (int i=1; i<=k; ++i){
				if (i%2){
					ans += components[(i-1)/2];
				}
				else {
					ans += components[count - (i/2)];
				}
			}
			cout << ans << endl;
		}
		
	}

	return 0;
}