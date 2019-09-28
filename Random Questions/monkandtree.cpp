#include <bits/stdc++.h>
#include <climits>
#define ii pair<int, int>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		vector<int> adj[n+1];
		int cost = 0;
		for (int i=0; i<m; ++i){
			int a, b; cin >> a >> b;
			cost += abs(a-b);
			adj[a].push_back(b); adj[b].push_back(a);
		}

		priority_queue<ii> prim;
		int distance[n+1];
		for (int i=0; i<=n; ++i){
			distance[i] = INT_MAX;
		}
		prim.push(make_pair(0, 1));
		int better_cost = 0;

		while (!prim.empty()){
			int to = prim.top().second;
			int weight = prim.top().first;
			prim.pop();
			if (distance[to]==INT_MAX){
				distance[to] = weight;
				better_cost += weight;
				for (int i=0; i<adj[to].size(); ++i){
					int dest = adj[to][i];

					if (distance[dest] == INT_MAX){
						int w = abs(to-dest);
						prim.push(make_pair(w, dest));	
					}

				}
			}


		}

		cout << cost - better_cost << endl;
	}
	return 0;
}