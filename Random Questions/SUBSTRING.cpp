#include <bits/stdc++.h>
#define int long long

using namespace std;
// 1 indexing is followed
signed main(){
	int t; cin >> t;
	while (t--){
		int n, k; cin >> n >> k;
		int array[n+1]; array[0] = -1;

		for (int i=1; i<=n; ++i){
			char X;cin >> X;
			if (X=='X') array[i] = 0;
			if (X=='Y') array[i] = 1;
			if (X=='Z') array[i] = 2;
		}

		int LX[n+2][3]; // LX[i][j]: Number of X to the left of index i with remainder j on divison by 3 of index of X
		LX[1][0] =  LX[1][1] = LX[1][2] = 0;
		LX[n+1][0] = LX[n+1][1] = LX[n+1][2] = 0;
		for (int i=2; i<=n; ++i){
			LX[i][0] = LX[i-1][0];
			LX[i][1] = LX[i-1][1];
			LX[i][2] = LX[i-1][2];

			if (array[i-1]==0){
				LX[i][(i-1)%3]++;
			}
		}
		int S[n+1]; S[0] = 0; //S[i] is number of intersecting good substrings that has terminal Z in [1,2,3... i]
		for (int i=1; i<=n; ++i){
			S[i] = S[i-1];
			if (array[i] == 2){
				S[i] += LX[i][(i-2)%3];
			}
		}
	
		int RZ[n+1][3]; // RZ[i][j]: Number of Z to right of index i with remainder j
		RZ[n][0] = RZ[n][1] = RZ[n][2] = 0;
		for (int i = n-1; i>= 0; --i){
			RZ[i][0] = RZ[i+1][0];
			RZ[i][1] = RZ[i+1][1];
			RZ[i][2] = RZ[i+1][2];

			if (array[i+1]==2){
				RZ[i][(i+1)%3]++;
			}
		}
		int minimal; bool set = false;
		for (int i=1; i+k-1<=n; ++i){
			int count = S[i+k-1] - S[i-1];
			count += RZ[i+k-1][1]*LX[i+k][2];

			count += RZ[i+k-1][2]*LX[i+k][0];

			count += RZ[i+k-1][0]*LX[i+k][1];

			if (!set){
				minimal = count; set = true;
			}
			else {
				minimal = min(minimal, count);
			}
		}

		cout << minimal << endl;
	} 

	return 0;
}