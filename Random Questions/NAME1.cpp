#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		string a, b;
		cin >> a >> b;
		vector<int> counter(26, 0);

		for (int i=0; i<a.size();++i){
			counter[a[i]-'a']++;
		}
		for (int i=0; i<b.size();++i){
			counter[b[i] - 'a']++;
		}

		int m; cin >> m;
		vector<int> cc(26, 0);
		for (int i=0; i<m; ++i){
			string cur; cin >> cur;
			for (int i=0; i<cur.size(); ++i){
				cc[cur[i]-'a']++;
			}
		}
		bool pas = true;
		for (int i=0; i<26; ++i){
			if (cc[i]>counter[i])
				pas = false;
		}

		if (pas)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}