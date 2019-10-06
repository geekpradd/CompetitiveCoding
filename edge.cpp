#include <bits/stdc++.h>
#define int long long
using namespace std;

int dfs(int n, vector<int> adj[], vector<bool>&visited, int i){
	visited[i] = 1;
	int c = 0;
	for (int j=0; j<adj[i].size(); ++j){
		if (!visited[adj[i][j]]){
			c+= dfs(n, adj, visited, adj[i][j]);
		}
	}
	return c + adj[i].size();
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> adj[n+1];
		for (int i=0; i<m; ++i){
			int a, b; cin >> a >> b;
			adj[a].push_back(b); adj[b].push_back(a);
		}
		if (m%2==0){
			cout << 1 << endl;
			for (int i=0; i<n; ++i){
				cout << 1 << " ";
			}
			cout << endl;
		}
		else {
			bool odd = false; int j;
			for (int i=1; i<=n; ++i){
				if (adj[i].size()%2){
					odd = true; j = i; break;
				}
			}
			if (odd){
				cout << 2 << endl;
				for (int i=1; i<=n; ++i){
					cout << (i==j ? 2 : 1) << " ";
				}
				cout << endl;
			}
			else {
				// cout << "yay" << endl;
				vector<bool> visited(n+1, false);
				int j;
				for (int i=1; i<=n; ++i){
					if (!visited[i]){
						int ret = dfs(n, adj, visited, i);
						// cout << "ret = " << ret << endl;
						if ((ret/2)%2){
							j = i;
							break;
						}
					}
					
				}
				// cout << "j is " << j << endl;
				cout << 3 << endl; int b = adj[j][0];
				for (int i=1; i<=n; ++i){
					if (i==j){
						cout << 1 << " ";
					}
					else if (i==b){
						cout << 2 << " ";
					}
					else {
						cout << 3 << " ";
					}
				}
				cout << endl;
			}
		}
	}

	return 0;
}