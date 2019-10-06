#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(vector<int> *adj, int cur, int* zero, int * one, int parent, bool* set, int * baap, int * global){
	int onev = set[cur];
	int zerov = 1 - onev;
	baap[cur] = parent;
	for (int i=0; i<adj[cur].size(); ++i){
		if (adj[cur][i]==parent)
			continue;
		dfs(adj, adj[cur][i], zero, one, cur, set, baap, global);
		zerov += zero[adj[cur][i]];
		onev += one[adj[cur][i]];
	}
	cout<< "at " << cur << endl;
	zero[cur] = zerov;
	one[cur] = onev;
	cout << " 0 " << zerov << " one " << onev << endl;

	vector<int> vv;

	for (int i=0; i<adj[cur].size(); ++i){
		if (adj[cur][i]==parent)
			continue;
		vv.push_back(min(zero[adj[cur][i]], one[adj[cur][i]]));
	}
	sort(vv.begin(), vv.end());
	int count = 0;
	for (int i=0; i<vv.size(); ++i){
		cout << "got " << vv[i] << endl;
		count += vv[i]*(vv.size()-i-1);
	}
	*global += count;

	if (set[cur] == 1){
			int g = 0;
			for (int i=0; i<adj[cur].size(); ++i){
				if (adj[cur][i]!=parent)
					g += zero[adj[cur][i]];
			}
			*global += g;
			cout << "incremented " << g << endl;
	}

}

signed main(){
	int t;
	cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> adj[n+1];
		bool set[n+1];
		for (int i=1; i<=n; ++i){
			cin >> set[i];
		}
		for (int i=0; i<n-1; ++i){
			int x, y; cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		int zero[n+1]; int one[n+1];
		int baap[n+1]; int global = 0;
		dfs(adj, 1, zero, one, 0, set, baap, &global);
		cout << global << endl;

		
	}

	return 0;
}