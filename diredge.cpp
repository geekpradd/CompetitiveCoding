#include <bits/stdc++.h>
#define ii  pair<int, int>
using namespace std;

struct edge {
	int from; int to; bool swap; int id;
	// from, to are original states
};

void dfs(vector< vector<edge> > &span, int cur, vector<bool> &visit, vector<int> &count, vector<edge> &edges){
	visit[cur] = 1;
	for (int i=0; i<span[cur].size(); ++i){
		int to = span[cur][i].from^span[cur][i].to^cur;
		if (!visit[to]){
			dfs(span, to, visit, count, edges);
			if (count[to]%2){
				edges[span[cur][i].id].swap ^= 1;
			}

			count[cur] += count[to];
		}
	}
}

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		vector<edge> edges(m);
		vector< vector<int> > adj(n);
		vector<int> indegree(n, 0);
		


		for (int i=0; i<m; ++i){
			int a, b; cin >> a >> b;
			edge f; f.from = a-1; f.to = b-1; f.swap = 0; f.id = i;
			edges[i] = f;
			adj[a-1].push_back(i);
			adj[b-1].push_back(i);
			indegree[b-1]++;
		}
		if (m%2){
			cout << -1 << endl; continue;
		}
		// find the spanning tree
		queue<edge> st;
		vector<bool> visited(n, false);
		visited[0] = 1;
		for (int i=0; i<adj[0].size(); ++i){
			st.push(edges[adj[0][i]]);
		}
		vector<int> tree(n-1); int c = 0;
		while (!st.empty()){
			edge top = st.front();
			st.pop();
			if (visited[top.from] && visited[top.to])
				continue;
			int x = top.from;
			if (visited[top.from]){
				x = top.to;
			}

			tree[c] = top.id; c++;
			// cout << "joined " << top.from << " and " << top.to << endl;
			visited[x] = true;
			for (int i=0; i<adj[x].size(); ++i){
				int other = edges[adj[x][i]].from^edges[adj[x][i]].to^x;
				if (!visited[other])
					st.push(edges[adj[x][i]]);
			}	
		}

		// cout << c << endl;

		vector< vector<edge> > span(n);
		for (int i=0; i<c; ++i){
			edge cur = edges[tree[i]];
			span[cur.from].push_back(cur); span[cur.to].push_back(cur);
		}
		vector<bool> visit(n, 0); vector<int> count(n);
		for (int i=0; i<n; ++i){
			if (indegree[i]%2)
				count[i] = 1;
			else 
				count[i] = 0;
		}
		dfs(span, 0, visit, count, edges);

		for (int i=0; i<m; ++i){
			cout << edges[i].swap << " ";
		}
		cout << endl;
	}

	return 0;
}