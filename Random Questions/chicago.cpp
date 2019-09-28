#include <bits/stdc++.h>
#include <iomanip> 
#define int long long 
#define id pair<double, int>
using namespace std;

signed main(){
	int n; cin >> n;

	while (n!=0){
		int m; cin >> m;
		vector<id> adj[n];
		for (int i=0; i<m; i++){
			int a, b, p; cin >> a >> b >> p;
			double prob = p/100.0;
		
			adj[a-1].push_back(make_pair(prob, b-1)); adj[b-1].push_back(make_pair(prob, a-1));

		}

		priority_queue<id> djk;
		double distance[n];
		int visited[n];
		for (int i=0; i<n; ++i) distance[i] = visited[i] =  0;
		djk.push(make_pair(1, 0));

		while (!djk.empty()){
			id cur = djk.top();

			double p = cur.first;
			int to = cur.second;

			if (!visited[to]){
				for (int i=0; i<adj[to].size(); ++i){
					int r = adj[to][i].second;
					double pd = adj[to][i].first;
					pd *= p;


					if (!visited[r] && pd > distance[r]){
						distance[r] = pd;
						djk.push(make_pair(pd, r));
					}
				}

				visited[to] = 1;
			}

			djk.pop();

		}
		cout << fixed;
		cout << setprecision(6);
		cout << distance[n-1]*100 << " percent"<< endl;

		cin >> n;

	}
	


}