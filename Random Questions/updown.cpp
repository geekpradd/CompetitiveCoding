#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, int* precomp, vector<int>* adj, int* a, int* baap, int* maxa){
	precomp[cur] = precomp[baap[cur]];
	if (a[cur] > maxa[baap[cur]])
		precomp[cur]++;

	maxa[cur] = max(maxa[baap[cur]], a[cur]);

	for (int i=0; i<adj[cur].size(); ++i)
		dfs(adj[cur][i], precomp, adj, a, baap, maxa);
}
signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a[n+1]; 
		for (int i=1; i<=n; ++i) cin >> a[i];
		vector<int> adj[n+1]; int baap[n+1];
		int siz = log2(n) + 2;
		int baapu[n+1][siz];

		for (int i=0; i<siz; ++i)
			baapu[1][i] = -1;
		for (int i=2; i<=n;++i){
			cin >> baap[i];
			adj[baap[i]].push_back(i);

			baapu[i][0] = baap[i];
		}	
		
		int precomp[n+1]; precomp[1] = 0;
		int maxa[n+1]; maxa[1] = a[1];
		

		for (int i=0; i<adj[1].size(); ++i)
			dfs(adj[1][i], precomp, adj, a, baap, maxa);

		for (int l = 1; l < siz; ++l){
			for (int i = 2; i <=n; ++i){
				int c = baapu[i][l-1];
				if (c > 0){
					baapu[i][l] = baapu[c][l-1];
				}
				else {
					baapu[i][l] = -1;
				}

			}
		}


		int q;cin >> q; int pr = 0;

		while(q--){
			int v, w; cin >> v >> w;
			v = v^pr; w = w^pr;

			int copy = v;

			if (maxa[v] > w){
				for (int m = siz - 1; m>=0; --m){
					int to = baapu[v][m];
					if (to > 0){
						if (maxa[to] > w){
							v = to;
						}
					}
				}

				pr = precomp[copy] - precomp[v] + 1;
			}

			else {
				pr = 0;
			}
			
			cout << pr << endl;
		}
	}
}