#include <bits/stdc++.h>
#define int long long
using namespace std;

void power(int matrix[2][2], int powe, int m){
	if (powe == 0 || powe == 1)
		return;
	int cpy[2][2];
	for (int i=0; i<2; ++i){
		for (int j=0; j<2; ++j)
			cpy[i][j] = matrix[i][j];
	}
	matrix[0][0] = (cpy[0][0]*cpy[0][0] + cpy[0][1]*cpy[1][0])%m;
	matrix[0][1] = (cpy[0][0]*cpy[0][1] + cpy[0][1]*cpy[1][1])%m;
	matrix[1][0] = (cpy[1][0]*cpy[0][0] + cpy[1][1]*cpy[1][0])%m;
	matrix[1][1] = (cpy[1][0]*cpy[0][1] + cpy[1][1]*cpy[1][1])%m;
	if (powe%2){
		power(matrix, powe/2, m);
		int l[2][2];
		l[0][0] = (cpy[0][0]*matrix[0][0] + cpy[0][1]*matrix[1][0])%m;
		l[0][1] = (cpy[0][0]*matrix[0][1] + cpy[0][1]*matrix[1][1])%m;
		l[1][0] = (cpy[1][0]*matrix[0][0] + cpy[1][1]*matrix[1][0])%m;
		l[1][1] = (cpy[1][0]*matrix[0][1] + cpy[1][1]*matrix[1][1])%m;
		for (int i=0; i<2; ++i){
			for (int j=0; j<2; ++j)
				matrix[i][j] = l[i][j];
		}

	}
	else {
		power(matrix, powe/2, m);
	}
}

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int p[n];
		for (int i=0; i<n; ++i) cin >> p[i];
		int m[n];
		for (int i=0; i<n; ++i) cin >> m[i];

		int status = -1;
		int best;

		for (int i=n-1; i>=0; --i){
			int mat[2][2];
			mat[0][0] = mat[0][1] = mat[1][0] = 1;
			mat[1][1] = 0;
			power(mat, p[i], m[i]);
			int f = mat[1][0];
			if (f==0)
				continue;
			if (status == -1){
				status = f;
				best = i+1;
			}
			else {
				if (f <= status){
					status = f;
					best = i+1;
				}
			}
		}

		if (status == -1)
			cout << -1 << endl;
		else
			cout << best << " " << status << endl;
	}

	return 0;
}