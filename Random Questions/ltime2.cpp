#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t--){
		string s, r; cin >> s;
		cin >> r;
		vector<int> counts(26, 0);
		vector<int> countr(26, 0);
		for (int i=0; i<s.length(); ++i){
			counts[s[i] - 'a']++;
		}
		for (int i=0; i<r.length(); ++i){
			countr[r[i]-'a']++;
		}
		bool poss = true;
		for (int i=0; i<26; ++i){
			if (counts[i]>countr[i])
				poss = false;
			countr[i] = countr[i] - counts[i];
		}
		if (!poss){
			cout << "Impossible" << endl;
			continue;
		}
		char start = s[0];
		bool shift = false;
		for (int i=1; i<s.length(); ++i){
			if (s[i]!=start){
				if (s[i]<start)
					shift = true;

				break;
			}
		}
		int finish = (shift ? start - 'a' - 1 : start - 'a');
		for (int i=0; i<=finish; ++i){
			char cur = 'a' + i;
			for (int j=0; j<countr[i]; ++j){
				cout << cur;
			}
		}
		cout << s;
		for (int i=finish+1; i<26; ++i){
			char cur = 'a' + i;
			for (int j=0; j<countr[i]; ++j){
				cout << cur;
			}
		}

		cout << endl;
	}

	return 0;
}