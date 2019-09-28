#include <bits/stdc++.h>
#define int long long
using namespace std;

struct cell {
	int i;
	int j; 
	int kind; // 0 for W and 1 for B
};

bool compare_cell(cell a, cell b){
	if (a.i==b.i){
		return a.j <= b.j;
	}
	else {
		return a.i <= b.i;
	}
}
signed main(){
	int n, m, w, b; cin >> n >> m >> w >> b;
	vector<cell> marks(w + b);
	for (int i=0; i<w; ++i){
		int x, y; cin >> x >> y;
		cell in = {x, y, 0};
		marks[i] = in;
	}
	for (int i=0; i<b; ++i){
		int x, y; cin >> x >> y;
		cell in = {x, y, 1};
		marks[w+i] = in;		
	}
	sort(marks.begin(), marks.end(), compare_cell);
	int net_sum = n*m*(m+1);
	net_sum = net_sum/2;
	bool prev_white = false; // was the last cell an actual white one
	int start_j = 1;
	int prev_i = -1;

	for (int i=0; i<(w+b); ++i){
		cell a = marks[i];
		if (a.i != prev_i){
			prev_white = false;
			start_j = 1;
			prev_i = a.i;
		}
		net_sum -= m + 1 - a.j;
n
		if (a.kind == 1){
			net_sum -= (m-a.j)*(a.j - start_j);
			start_j = a.j + 1;
			if (prev_white){
				net_sum += m-a.j;
			}
			prev_white = false;
		}
		else {
			if (prev_white){
				net_sum -= (m-a.j)*(a.j - start_j-1);
				start_j = a.j + 1;
				prev_white = false;
			}
			else {
				prev_white = true;
			}
		}

	}
	cout << net_sum << endl;
	return 0;
}